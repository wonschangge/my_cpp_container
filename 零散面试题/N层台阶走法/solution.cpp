#include <iostream>
using namespace std;

// 递归实现
int climbStairsRecursive(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    return climbStairsRecursive(n - 1) + climbStairsRecursive(n - 2);
}

// 非递归实现（迭代，时间O(n)，空间O(1)）
int climbStairsIterative(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    int prev_prev = 1; // f(n-2)
    int prev = 2;      // f(n-1)
    int current;
    for (int i = 3; i <= n; ++i) {
        current = prev + prev_prev;
        prev_prev = prev;
        prev = current;
    }
    return current;
}

int main() {
    int n;
    cout << "请输入台阶数n: ";
    cin >> n;
    cout << "递归方法：" << climbStairsRecursive(n) << endl;
    cout << "非递归方法：" << climbStairsIterative(n) << endl;
    return 0;
}