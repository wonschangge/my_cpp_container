// 题目：古典问题（兔子生崽）：
//      有一对兔子，从出生后第3个月起每个月都生一对兔子，
//      小兔子长到第三/个月后每个月又生一对兔子，
//      假如兔子都不死，问每个月的兔子总数为多少？（输出前40个月即可）
// 程序分析：兔子的规律为数列1,1,2,3,5,8,13,21....，即下个月是上两个月之和（从第三个月开始）。
//         斐波纳契数列的另一种隐晦语言表示
#include <stdio.h>
long long int fibonacci(int i) {
    if (i <= 0) return -1;
    if (i == 1 || i == 2) return 1;
    return fibonacci(i-1) + fibonacci(i-2);
}

// 利用cache来优化递归，空间换时间
unsigned long long int fibonacci2(int n) {
    unsigned long long cache[200] = {0,1};
    for (int i = 2; i <= n; i++)
        cache[i] = cache[i-1] + cache[i-2];
    return cache[n];
}

int main() {
    printf("40: %lld\n", fibonacci2(40));
    printf("MAX: 123: %lld\n", fibonacci2(123));
}