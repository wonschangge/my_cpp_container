
在 C++ 中，对 `vector` 排序的方法主要有以下几种，可根据需求选择合适的方式：


### **一、使用 `<algorithm>` 头文件中的 `sort` 函数（最常用）**
`sort` 函数可以对 `vector` 进行**默认升序排序**或**自定义排序**，适用于**可随机访问的迭代器**（`vector` 符合条件）。

#### **1. 默认升序排序**
```cpp
#include <vector>
#include <algorithm> // 需包含此头文件

int main() {
    std::vector<int> vec = {3, 1, 4, 2, 5};
    std::sort(vec.begin(), vec.end()); // 排序后：1, 2, 3, 4, 5
    return 0;
}
```

#### **2. 降序排序（使用标准库函数对象）**
通过 `std::greater<T>` 实现降序：
```cpp
#include <functional> // 需包含此头文件

std::sort(vec.begin(), vec.end(), std::greater<int>()); // 排序后：5, 4, 3, 2, 1
```

#### **3. 自定义比较函数**
通过**自定义比较函数**实现复杂排序逻辑（如结构体按特定字段排序）：
```cpp
struct Student {
    std::string name;
    int score;
};

// 按分数升序排序（若分数相同，按姓名字典序降序）
bool compare(const Student& a, const Student& b) {
    if (a.score != b.score) {
        return a.score < b.score; // 先比较分数
    } else {
        return a.name > b.name; // 分数相同则比较姓名（降序）
    }
}

std::vector<Student> students;
std::sort(students.begin(), students.end(), compare); // 使用自定义比较函数
```

#### **4. Lambda 表达式自定义排序**
用 Lambda 表达式替代传统比较函数，代码更简洁：
```cpp
// 按分数降序排序（忽略姓名）
std::sort(students.begin(), students.end(), 
          [](const Student& a, const Student& b) {
              return a.score > b.score;
          });
```


### **二、使用 `<algorithm>` 中的 `stable_sort` 函数（稳定排序）**
`stable_sort` 是**稳定排序算法**，即**相等元素的相对顺序在排序后保持不变**，适用于需要保留原始顺序中相等元素位置的场景。
```cpp
std::vector<int> vec = {2, 3, 2, 1};
std::stable_sort(vec.begin(), vec.end()); // 排序后：1, 2, 2, 3（两个 2 的相对顺序与原数组一致）
```

#### **自定义比较方式**
用法与 `sort` 类似，可结合 Lambda 或函数对象：
```cpp
std::stable_sort(students.begin(), students.end(), 
                 [](const Student& a, const Student& b) {
                     return a.score < b.score;
                 });
```


### **三、使用 `vector` 成员函数（C++20 及以上）**
C++20 为 `vector` 新增了 `sort` 成员函数，用法更简洁（无需指定迭代器范围）：
```cpp
std::vector<int> vec = {3, 1, 4, 2, 5};
vec.sort(); // 默认升序，等价于 std::sort(vec.begin(), vec.end());

// 降序或自定义排序（传入比较函数或 Lambda）
vec.sort(std::greater<int>()); // 降序
vec.sort([](int a, int b) { return a % 2 > b % 2; }); // 按奇偶性排序（奇数在前）
```


### **四、对部分元素排序（`partial_sort`）**
若只需对 `vector` 中的**前 `n` 个最小/最大元素排序**，可使用 `partial_sort`，效率更高：
```cpp
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {5, 3, 8, 1, 4};
    std::vector<int> result(3); // 存储前 3 个最小元素

    // 排序前 3 个最小元素并放到 vec 前半部分
    std::partial_sort(vec.begin(), vec.begin() + 3, vec.end()); // vec 变为：1, 3, 4, 5, 8

    // 若需单独存储结果，可配合 copy
    std::copy(vec.begin(), vec.begin() + 3, result.begin()); // result: 1, 3, 4
    return 0;
}
```


### **五、其他排序相关函数**
1. **`reverse`：反转元素顺序**
   ```cpp
   std::vector<int> vec = {1, 2, 3, 4};
   std::reverse(vec.begin(), vec.end()); // vec 变为：4, 3, 2, 1
   ```

2. **`is_sorted`：检查是否已排序**
   ```cpp
   bool isSorted = std::is_sorted(vec.begin(), vec.end()); // 检查是否升序排列
   ```

3. **`nth_element`：找到第 `n` 小的元素**
   ```cpp
   std::vector<int> vec = {5, 2, 7, 1, 3};
   std::nth_element(vec.begin(), vec.begin() + 2, vec.end()); // 第 3 小的元素（索引 2）到位，其余元素无序，vec 可能为：2, 1, 3, 5, 7
   ```


### **选择建议**
- **通用场景**：优先使用 `std::sort` 或 C++20 的 `vector::sort`，简洁高效。
- **稳定排序需求**：使用 `std::stable_sort`。
- **部分排序或找第 `n` 大元素**：使用 `partial_sort` 或 `nth_element`。
- **自定义排序逻辑**：灵活使用 Lambda 表达式或函数对象，避免编写复杂的全局函数。

注意确保排序的元素类型支持比较操作（如自定义类型需重载 `operator<` 或提供显式比较函数）。