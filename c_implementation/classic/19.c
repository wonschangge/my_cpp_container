// 题目：一个数如果恰好等于它的因子之和，这个数就称为"完数"，例如 6=1＋2＋3 ，
//      请编程找出 1000 以内的所有完数。
// 程序分析：请参照：14.c
#include <stdio.h>
#include <math.h>

// 找到一个数的所有因数并计算和
int findDivisors(int num, int divisors[]) {
    int sum = 1; // 初始化因数和为1（1是所有数的因数）
    int count = 1; // 初始化因数计数

    divisors[0] = 1;

    // 遍历从2到num/2的所有数，寻找因数
    for(int j=2;j<=num/2;++j) {
        if(num % j == 0) // 如果j是num的因数
        {
            sum+=j;
            divisors[count++] = j;
        }
    }
    return sum;
}


int main() {
    // 遍历从2到1000的所有数，寻找完美数
    // int **divisors; // 指针用于存储因数数组
    int max = ((int)log2(10000) + 1) >> 0;
    int divisors[max];
    for (int i = 2; i <= 10000; ++i) {
        int sum = findDivisors(i, divisors);
        if(i==sum) {
            printf("%d=%d", i, divisors[0]);
            for (int n = 1; divisors[n] != 0; ++n) { // 输出所有因数
                printf("+%d", divisors[n]);
            }
            printf("\n");
            fflush(stdout);
        }
    }
}