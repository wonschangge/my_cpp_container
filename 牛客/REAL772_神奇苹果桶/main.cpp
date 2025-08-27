#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> ops(2 * n);
    for (int i = 0; i < 2 * n; ++i)
        cin >> ops[i];

    int apples = 0;
    for (int i = 0; i < n; ++i) {
        int op = ops[2 * i];
        int m = ops[2 * i + 1];

        if (op == 1) apples += m;
        else if (op == 2) apples -= apples >= m ? m : 0;
        else if (op == 3) {
            int take = (apples + m - 1) / m;
            apples -= take;
        }
    }

    cout << apples << endl;
    return 0;
}