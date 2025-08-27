// 1.算法
//   给罗马数字，返回其整数
//   1. 小的在大的右边
//      特例：4 不写作 IIII，而是 IV，代表大的减去小的
//           9 是 IX
//      适用情况，1. I可放在V(5)和X(10)的左边，表示4和9
//      适用情况，2. X可放在L(50)和C(100)的左边，表示40和90
//      适用情况，3. C可放在D(50)和M(1000)的左边，表示400和900

// 无外乎: IV/IX/XL/XC/CD/CM

// 3999=MMM,CM,XC,IX

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_map<char, int> dic = {
        { 'I', 1 },
        { 'V', 5 },
        { 'X', 10 },
        { 'L', 50 },
        { 'C', 100 },
        { 'D', 500 },
        { 'M', 1000 },
    };

    unordered_map<string, int> special_dic = {
        { "IV", 4 },
        { "IX", 9 },
        { "XL", 40 },
        { "XC", 90 },
        { "CD", 400 },
        { "CM", 900 },
    };

    int romanToInt(string s) {
        int sum = 0;
        int l = s.size();
        int lp = 0;
        while (lp < l) {
            if (s[lp+1]) {
                string tmp = s.substr(lp, 2);
                if (special_dic.count(tmp)) {
                    sum += special_dic[tmp];
                    lp += 2;
                    continue;
                }
            }
            sum += dic[s[lp]];
            lp++;
        }

        return sum;
    }
};

int main() {
    Solution* s = new Solution();
    // std::cout << s->romanToInt("IV") << std::endl;
    // std::cout << s->romanToInt("IX") << std::endl;
    // std::cout << s->romanToInt("XL") << std::endl;
    // std::cout << s->romanToInt("XC") << std::endl;
    // std::cout << s->romanToInt("CD") << std::endl;
    // std::cout << s->romanToInt("CM") << std::endl;
    std::cout << s->romanToInt("III") << std::endl;
    std::cout << s->romanToInt("IV") << std::endl;
    std::cout << s->romanToInt("IX") << std::endl;
    std::cout << s->romanToInt("LVIII") << std::endl;
    std::cout << s->romanToInt("MCMXCIV") << std::endl;
}