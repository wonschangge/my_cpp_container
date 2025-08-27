
在 C++ 中，对 `vector` 进行值去重（保留唯一元素）的方法有多种，可根据元素类型、是否需要保持顺序、性能需求等选择合适的方式。以下是常见的实现方法：


### **一、利用 `std::set` 或 `std::unordered_set`（高效去重，顺序可能改变）**
通过集合类的**自动唯一性**特性实现去重，适用于不需要保留原始顺序的场景。

#### **1. 使用 `std::set`（有序去重）**
- **原理**：`set` 内部基于红黑树实现，自动排序并去重。  
- **步骤**：将 `vector` 元素插入 `set`，再转换回 `vector`。  
- **代码示例**：  
  ```cpp
  #include <vector>
  #include <set>
  #include <algorithm> // 用于 std::copy

  template <typename T>
  std::vector<T> removeDuplicatesSorted(const std::vector<T>& vec) {
      std::set<T> setData(vec.begin(), vec.end()); // 自动去重并排序
      std::vector<T> result(setData.begin(), setData.end());
      return result;
  }

  // 使用示例
  std::vector<int> vec = {3, 1, 2, 2, 4, 3};
  std::vector<int> uniqueVec = removeDuplicatesSorted(vec); // 结果：{1, 2, 3, 4}（有序）
  ```

#### **2. 使用 `std::unordered_set`（无序去重，效率更高）**
- **原理**：基于哈希表实现，去重效率更高，元素顺序与原始 `vector` 无关。  
- **代码示例**：  
  ```cpp
  template <typename T>
  std::vector<T> removeDuplicatesUnordered(const std::vector<T>& vec) {
      std::unordered_set<T> setData(vec.begin(), vec.end());
      std::vector<T> result(setData.begin(), setData.end());
      return result;
  }

  // 使用示例
  std::vector<int> vec = {3, 1, 2, 2, 4, 3};
  std::vector<int> uniqueVec = removeDuplicatesUnordered(vec); // 结果顺序不确定（如 {3,1,2,4}）
  ```

#### **注意事项**：  
- **自定义类型**：需为类型定义哈希函数和相等判断（`unordered_set`）或比较函数（`set`）。  
- **顺序变化**：集合类会改变元素顺序，若需保留原始顺序，需用其他方法。


### **二、使用 `std::unique` + `erase`（保留原始顺序，需排序或相邻去重）**
`std::unique` 算法用于**移除相邻重复元素**，需配合 `sort` 实现全量去重，或直接处理相邻重复的场景。

#### **1. 先排序再去重（全量去重，顺序改变）**
- **步骤**：  
  1. 对 `vector` 排序，使重复元素相邻。  
  2. 用 `std::unique` 移除相邻重复元素（返回新的逻辑末尾迭代器）。  
  3. 用 `erase` 删除末尾无效元素。  
- **代码示例**：  
  ```cpp
  #include <vector>
  #include <algorithm> // 包含 sort 和 unique

  std::vector<int> vec = {3, 1, 2, 2, 4, 3};
  std::sort(vec.begin(), vec.end()); // 排序后：{1, 2, 2, 3, 3, 4}
  auto it = std::unique(vec.begin(), vec.end()); // 逻辑上变为 {1, 2, 3, 4, ...}，返回 it 指向第一个重复元素
  vec.erase(it, vec.end()); // 移除无效元素，最终 vec：{1, 2, 3, 4}
  ```

#### **2. 直接处理相邻重复元素（保留原始顺序，仅去重相邻重复）**
- **场景**：若 `vector` 中重复元素已相邻（如链表去重），可直接去重而不排序。  
- **代码示例**：  
  ```cpp
  std::vector<int> vec = {1, 2, 2, 3, 3, 3, 4};
  auto it = std::unique(vec.begin(), vec.end());
  vec.erase(it, vec.end()); // 结果：{1, 2, 3, 4}（保留原始顺序中的非相邻重复元素）
  ```

#### **注意事项**：  
- `std::unique` 并非真正删除元素，而是将重复元素移到末尾，需配合 `erase` 释放空间。  
- 若不排序，只能移除**相邻**重复元素，无法处理非相邻的重复（如 `{1, 2, 1}` 去重后仍为 `{1, 2, 1}`）。


### **三、手动遍历 + 哈希表（保留原始顺序，高效去重）**
通过哈希表记录已出现的元素，遍历 `vector` 时跳过重复值，**保留原始顺序**。

#### **代码示例**：  
```cpp
#include <vector>
#include <unordered_set> // 或 std::set 用于有序记录

template <typename T>
std::vector<T> removeDuplicatesKeepOrder(const std::vector<T>& vec) {
    std::vector<T> result;
    std::unordered_set<T> seen; // 记录已出现的元素

    for (const auto& element : vec) {
        if (seen.find(element) == seen.end()) { // 未出现过
            seen.insert(element);
            result.push_back(element); // 按原始顺序添加
        }
    }
    return result;
}

// 使用示例
std::vector<int> vec = {3, 1, 2, 2, 4, 3};
std::vector<int> uniqueVec = removeDuplicatesKeepOrder(vec); // 结果：{3, 1, 2, 4}（保留首次出现顺序）
```

#### **优点**：  
- 保留元素**首次出现的顺序**。  
- 时间复杂度 **O(n)**（平均情况，`unordered_set` 查找为 O(1)）。  

#### **缺点**：  
- 需额外空间存储哈希表（空间复杂度 O(n)）。  
- 自定义类型需支持哈希和相等判断。


### **四、基于排序和二分查找（适用于有序 `vector`）**
若 `vector` 已排序，可通过二分查找高效判断重复元素。

#### **代码示例**：  
```cpp
#include <vector>
#include <algorithm> // 包含 binary_search

std::vector<int> sortedVec = {1, 2, 2, 3, 4, 4, 4};
std::vector<int> result;
result.reserve(sortedVec.size()); // 预分配空间

for (const auto& element : sortedVec) {
    if (result.empty() || element != result.back()) { // 相邻元素比较
        result.push_back(element);
    }
}
// 结果：{1, 2, 3, 4}（仅适用于已排序的 vector）
```


### **五、使用 `<set>` 辅助并保留原始顺序（进阶方法）**
结合 `set` 和 `vector` 的特性，先去重再按原始顺序筛选元素（适用于元素可哈希的场景）。

#### **代码示例**：  
```cpp
#include <vector>
#include <set>
#include <unordered_set>

template <typename T>
std::vector<T> removeDuplicates(const std::vector<T>& vec) {
    std::unordered_set<T> seen;
    std::vector<T> result;
    std::set<typename std::vector<T>::const_iterator> orderedSeen; // 记录顺序

    for (auto it = vec.begin(); it != vec.end(); ++it) {
        if (seen.insert(*it).second) { // 插入成功（元素唯一）
            orderedSeen.insert(it); // 记录迭代器顺序
        }
    }

    // 按原始顺序提取元素
    for (auto it : orderedSeen) {
        result.push_back(*it);
    }
    return result;
}
```

#### **注意**：  
此方法通过记录迭代器顺序保留原始顺序，但实现较复杂，通常优先使用**手动遍历 + 哈希表**的简化版本。


### **性能对比**
| 方法                | 时间复杂度       | 空间复杂度 | 顺序保留 | 适用场景                     |
|---------------------|------------------|------------|----------|------------------------------|
| `set/unordered_set` | O(n log n)/O(n) | O(n)       | 否       | 无需顺序，高效去重           |
| `std::unique + erase` | O(n log n)      | O(1)       | 部分保留 | 先排序再去重，顺序改变       |
| 手动遍历 + 哈希表   | O(n)             | O(n)       | 是       | 需保留原始顺序               |
| 有序 vector 去重    | O(n)             | O(1)       | 是       | vector 已排序                |


### **选择建议**
1. **无需保留顺序，追求高效**：使用 `std::unordered_set`，时间复杂度 O(n)（平均）。  
2. **需保留原始顺序**：手动遍历 + 哈希表（推荐），或先排序再用 `std::unique`（顺序改变）。  
3. **自定义类型**：  
   - 若类型支持哈希和相等判断，用 `unordered_set`。  
   - 若类型支持排序，用 `set` 或先排序再去重。  
4. **相邻重复去重**：直接使用 `std::unique + erase`，无需排序。  

根据实际需求选择合适的方法，优先使用标准库工具（如 `set`、`unique`）以保证代码简洁性和效率。