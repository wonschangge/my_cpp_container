#include <bits/stdc++.h>

using namespace std;

// 模板函数：打印任意类型的二维向量 vector<vector<T>>
template <typename T>
void print2DVector(const vector<vector<T>>& vec2D) {
    int subVecIndex = 1;
    for (const auto& subVec : vec2D) { // 遍历每个子向量
        cout << "子向量 " << subVecIndex++ << ": ";
        bool isFirstElement = true;
        for (const auto& element : subVec) { // 遍历子向量中的每个元素
            if (!isFirstElement) {
                cout << ", ";
            }
            cout << element; // 直接输出元素（需支持 << 运算符）
            isFirstElement = false;
        }
        cout << endl;
    }
}
