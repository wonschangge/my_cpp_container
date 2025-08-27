#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int maximumLengthSubstring(string s) {
            // 法1.map
            int ans = 0, left = 0;
            std::map<char, int> cnt;
            int n = s.size();
            for (int i = 0; i < n; i++) {
                cnt[s[i]]++; // 直接使用字符作为key
                while (cnt[s[i]] > 2) { // 检查当前字符频率
                    cnt[s[left]]--;     // 递减左边界字符计数
                    // if (cnt[s[left]] == 0) {
                    //     cnt.erase(s[left]); // 清理计数为0的条目（可选）
                    // }
                    left++;
                }
                ans = max(ans, i - left + 1);
            }
            return ans;
    
            // 法2:将字符转为数字的滑动
            // int ans = 0, left = 0, cnt[26]{};
            // int n = s.size();
            // for (int i=0;i<n;i++){
            //     int b=s[i]-'a';
            //     cnt[b]++;
            //     while(cnt[b]>2){
            //         cnt[s[left++] - 'a']--;
            //     }
            //     ans=max(ans,i-left+1);
            // }
            // return ans;
        }
};

int main()
{
    Solution s;
    cout << s.maximumLengthSubstring("aaaa");
    cout << s.maximumLengthSubstring("bcbbbcba");
}
