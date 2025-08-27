// 题目：输入某年某月某日，判断这一天是这一年的第几天？
// 程序分析：以3月5日为例，应该先把前两个月的加起来，
//         然后再加上5天即本年的第几天，
//         特殊情况，闰年且输入月份大于3时需考虑多加一天。

#include <stdio.h>
int isLeapYear(int year) {
    // 闰年的判断规则：能被4整除且（不能被100整除或能被400整除）
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return 1;
    return 0;
}
int main() {
    int year, month, day;
    int daysInMonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int totalDays = 0;

    printf("请输入年份、月份和日期（格式：年 月 日）：");
    scanf("%d %d %d", &year, &month, &day);

    // 判断是否是闰年
    if (isLeapYear(year))
        daysInMonth[1] = 29; // 闰年2月有29天

    // 计算从1月1日到如输入日期的天数
    for (int i = 0; i < month - 1; i++)
        totalDays += daysInMonth[i];
    totalDays += day; // 加上当前月份的天数
    printf("%d年%d月%d日是该年的第%d天\n", year, month, day, totalDays);
}