#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k, a, b;
    cin >> n >> k >> a >> b;

    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i)
        cin >> x[i];
    for (int i = 0; i < n; ++i)
        cin >> y[i];

    // 标记每个位置是否同时满足能力值和合作值要求
    vector<int> valid(n, 0);
    for (int i = 0; i < n; ++i)
        if (x[i] >= a && y[i] >= b)
            valid[i] = 1;

    // 滑动窗口计算符合条件的连续k个位置
    int count = 0;
    int current_valid = 0;

    // 初始化第一个窗口
    for (int i = 0; i < k; ++i)
        current_valid += valid[i];
    if (current_valid == k)
        count++;

    // 滑动
    for (int i = k; i < n; ++i) {
        current_valid += valid[i] - valid[i - k];
        if (current_valid == k) {
            count++;
        }
    }

    cout << count << endl;
    return 0;
}
