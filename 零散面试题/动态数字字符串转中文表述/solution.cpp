#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 中文数字映射
const vector<string> digitMap = {"零", "一", "二", "三", "四", "五", "六", "七", "八", "九"};
// 单位映射（对应位数：0-个，1-十，2-百，3-千，4-万，8-亿）
const vector<string> unitMap = {"", "十", "百", "千", "万", "", "", "", "亿"};

// 处理单个数字段（最多4位）转中文
string convertSegment(const string& seg) {
    string res;
    bool hasZero = false;
    int len = seg.size();
    for (int i = 0; i < len; ++i) {
        int digit = seg[i] - '0';
        int pos = len - 1 - i; // 当前位的单位索引（0-3对应个-千）
        if (digit == 0) {
            hasZero = true;
        } else {
            if (hasZero) {
                res += "零";
                hasZero = false;
            }
            res += digitMap[digit];
            res += unitMap[pos];
        }
    }
    return res;
}

// 完整数字串转中文
string numberToChinese(const string& num) {
    if (num.empty()) return "";
    if (num == "0") return "零";

    string processed = num;
    // 移除前导零
    size_t firstNonZero = processed.find_first_not_of('0');
    if (firstNonZero != string::npos) {
        processed = processed.substr(firstNonZero);
    } else {
        return "零"; // 全零
    }

    // 反转后按4位分段（从低位到高位：个、万、亿）
    reverse(processed.begin(), processed.end());
    vector<string> segments;
    for (size_t i = 0; i < processed.size(); i += 4) {
        string seg = processed.substr(i, 4);
        reverse(seg.begin(), seg.end()); // 恢复分段内顺序
        segments.push_back(seg);
    }

    string result;
    // 处理各分段（从高位到低位：亿、万、个）
    for (int i = segments.size() - 1; i >= 0; --i) {
        string seg = segments[i];
        string segStr = convertSegment(seg);
        if (!segStr.empty()) {
            // 对应单位：亿（i=2）、万（i=1）、个（i=0）
            if (i == 2) segStr += "亿";
            else if (i == 1) segStr += "万";
            result += segStr;
        }
    }

    // 处理特殊情况：十位数（如"10"-> "十"而非"一十"）
    if (result.size() >= 2 && result.substr(0, 2) == "一十") {
        result = result.substr(1);
    }

    return result;
}

// 处理输入（支持*号退位）并返回中文表述
string processInput(string input) {
    // 处理退位
    for (size_t i = 0; i < input.size(); ++i) {
        if (input[i] == '*') {
            if (i > 0) {
                input.erase(i-1, 2); // 删除前一位和*号
                i -= 2; // 回退索引
            } else {
                input.erase(i, 1); // 首位*直接删除
                i -= 1;
            }
        }
    }
    // 转换有效数字
    return numberToChinese(input);
}

int main() {
    // 测试案例
    cout << processInput("134") << endl; // 一百三十四
    cout << processInput("1500110") << endl; // 一百五十万零一百一十
    cout << processInput("1500110*") << endl; // 十五万零十一
    return 0;
}