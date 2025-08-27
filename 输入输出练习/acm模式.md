本文整理ACM模式的各种输入形式。

## 输入大类一 整形数组输入

### 形式一 在终端的一行中输入固定数目的整型数字，并存到数组中，中间以空格分隔

如：
```
3
1 2 3
```

方法1,初始化向量组时定义好规模:

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    // 或者拆为以下两步:
    // vector<int> nums;
    // nums.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> nums[i];
    for(auto i : nums) cout << i << " ";
    cout << endl;
}
```

方法2,向量组规模动态增长

```cpp
#include <iostream>
#include <vector>
using namespace std;
 
int main(){
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; ++i){
        int val;
        cin >> val;
        nums.push_back(val);
    }
    for(auto i : nums) cout << i << " ";
    cout << endl;
}
```

正确性测试：

```
Input:
    3
    1 2 3
Output:
    1 2 3
```

### 形式二 在终端的一行中输入非固定数目的整型数字，并存到数组中，中间以空格（或者其他单字符,./）分隔

向量组规模动态增长,遇到换行符跳出

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> nums;
    int num;
    while (cin>>num) {
        nums.push_back(num);
        if(getchar() == '\n') // 或使用 cin.get() == '\n'
            break;
    }
    for(auto i : nums) cout << i << " ";
    cout << endl;
}
```

正确性测试：

```
Input:
    1 2 3 4
Output:
    1 2 3 4
```

### 形式三 在终端的一行中输入固定数目的整型数字，并存到数组中，中间以（其他单字符,./）分隔

如:
```
3
1,2,3
```

向量组规模定死,将非数字字符排出
```cpp
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int m;
    cin >> m;
    char sep;
    vector<int> nums(m);
 
    for (int i = 0; i < m - 1; ++i){
        cin >> nums[i] >> sep;
    }
    cin >> nums[m - 1];
    //测试：打印数组
    cout<<"test c++ input:"<<endl;
    for(auto i : nums)
        cout << i << " ";
    cout << endl;
}
```

## 输入大类二 字符串输入
### 形式一 给定一行字符串，每个字符串用空格间隔，一个样例为一行

如:
```
daa ma yello
```

循环读取不停,回车键交互
```cpp
#include <iostream>
#include <vector>
using namespace std;

int main(){
    string str;
    vector<string> strs;
    while (cin >> str) {
        strs.push_back(str);
        if (getchar() == '\n') {  //控制测试样例
            for (auto& str : strs) {
                cout << "current character:"<< str << " ";
            }
            cout << endl;
            strs.clear();
        }
    }
    return 0;
}
```

### 形式二 给定一行字符串，每个字符串用逗号间隔，一个样例为一行

步骤:
1. 使用 getline 读取一整行字符串到字符串input中
2. 使用字符串流 stringstream ，读取单个数字或者字符
3. 每个字符中间用','间隔

```cpp
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;
int main(){
    string input;
    while (getline(cin, input)) {  //读取一行
        vector<string> strs;
        string str;
        stringstream ss(input);
        while(getline(ss, str,',')){
            strs.push_back(str);
        }
        sort(strs.begin(), strs.end());
        for (auto& str : strs) {
            cout << str << " ";
        }
        cout << endl;
    }
    return 0;
}
``` 

### 形式三 给定一行字符串表示的数字，每个字符串用空格间隔，一个样例为一行

```cpp
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
int main(){
    string input;
    while (getline(cin, input)) {  //读取一行
        stringstream data(input);  //使用字符串流
        int num = 0, sum = 0;
        while (data >> num) {
            sum += num;
        }
        cout << sum << endl;
    }
    return 0;
}
```

## 输入大类三 字符串输入到数组

### 形式一 输入n行字符串，逗号分开，存到数组里

如:
```
3
1,2,3,3,2
4,5,6,1,3
7,8,9,3,4
```

```cpp
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> vec(n,vector<int>(5));
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        replace(s.begin(), s.end(), ',', ' ');
        istringstream input(s);
        string tmp;
        for (int j = 0; j < 5; ++j){//内层循环也很重要
            input >> tmp;
            vec[i][j] = stoi(tmp);
        }
    }

    for(auto v: vec) {
        for(auto e: v) 
            cout << e << " ";
        cout << endl;
    }
    return 0;
}
```