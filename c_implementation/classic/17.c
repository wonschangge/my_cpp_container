// 题目：输入一行字符，分别统计出其中英文字母、空格、数字和其它字符的个数。
// 程序分析：利用while语句,条件为输入的字符不为'\n'。

#include <stdio.h>
int main() {
    char c;
    int letterCount = 0, spaceCount = 0, digitCount = 0, otherCount = 0;
 
    printf("请输入一些字符：\n");
 
    while ((c = getchar()) != '\n') {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            letterCount++;
        } else if (c >= '0' && c <= '9') {
            digitCount++;
        } else if (c == ' ') {
            spaceCount++;
        } else {
            otherCount++;
        }
    }
 
    printf("字母 = %d, 数字 = %d, 空格 = %d, 其他 = %d\n", letterCount, digitCount, spaceCount, otherCount);
    return 0;
}