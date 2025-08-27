// 题目：判断 101 到 200 之间的素数。
// 程序分析：判断素数的方法：用一个数分别去除 2 到 sqrt(这个数)，
//         如果能被整除，则表明此数不是素数，反之是素数。

#include <stdio.h>
int main() {
    int i,j;
    int count=0;
    for (i=101;i<200;i++) {
        for(j=2;2*j<=i;j++)
            if (i%j==0) break; // 如果j能被i整除再跳出循环
        if(j*2+1>=i) { // 判断循环是否提前跳出，如果j<i说明在2~j之间,i有可整除的数
            count++;
            printf("%d\n", i);
        }
    }
}