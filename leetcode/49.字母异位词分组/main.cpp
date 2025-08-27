#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // 打印二维向量的函数
    static void print2DVector(const vector<vector<string>>& vec2D) {
        int subVecIndex = 1;
        for (const auto& subVec : vec2D) {
            cout << "子向量 " << subVecIndex++ << ": ";
            bool isFirstElement = true;
            for (const auto& str : subVec) {
                if (!isFirstElement) {
                    cout << ", ";
                }
                cout << str;
                isFirstElement = false;
            }
            cout << endl;
        }
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 法1: 排序
        // unordered_map<string, vector<string>> mp;
        // for (string& str: strs) {
        //     string key = str;
        //     sort(key.begin(), key.end());
        //     mp[key].emplace_back(str);
        // }

        // vector<vector<string>> ans;
        // for (auto it = mp.begin(); it != mp.end(); ++it) {
        //     ans.emplace_back(it->second);
        // }
        // return ans;

        // 法2: 计数
        // 自定义对 array<int,26> 类型的哈希函数
        auto arrayHash = [fn = hash<int>{}] (const array<int, 26>& arr) -> size_t {
            return accumulate(arr.begin(), arr.end(), 0u, [&](size_t acc, int num) {
                return (acc << 1) ^ fn(num);
            });
        };

        unordered_map<array<int, 26>, vector<string>, decltype(arrayHash)> mp(0, arrayHash);
        for (string& str: strs) {
            array<int, 26> counts{};
            int length = str.length();
            for (int i = 0; i < length; ++i)
                counts[str[i] - 'a']++;
            mp[counts].emplace_back(str);
        }
        vector<vector<string>> ans;
        for (auto it = mp.begin(); it != mp.end(); ++it)
            ans.emplace_back(it->second);
        return ans;
        
    }
};

int main() {
    Solution* s = new Solution();
    {
        vector<string> input = {"eat", "tea", "tan", "ate", "nat", "bat"};
        vector<vector<string>> output = s->groupAnagrams(input);
        s->print2DVector(output);
    }
    {
        vector<string> input = {""};
        vector<vector<string>> output = s->groupAnagrams(input);
        s->print2DVector(output);
    }
    {
        vector<string> input = {"a"};
        vector<vector<string>> output = s->groupAnagrams(input);
        s->print2DVector(output);
    }
}