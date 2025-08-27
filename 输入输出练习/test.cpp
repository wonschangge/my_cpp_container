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