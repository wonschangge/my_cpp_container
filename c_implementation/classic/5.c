// 题目：输入三个整数 x、y、z，请把这三个数由小到大输出。
// 程序分析：我们想办法把最小的数放到 x 上，先将 x 与 y 进行比较，
//         如果 x>y 则将 x 与 y 的值进行交换，然后再用 x 与 z 进行比较，
//         如果 x>z 则将 x 与 z 的值进行交换，这样能使 x 最小。

#include <stdio.h>
int main() {
    int x,y,z;
    printf("\n请输入三个数字:\n");
    scanf("%d%d%d",&x,&y,&z);

    int t;
    if (x>y) { t=x; x=y; y=t; }
    if (x>z) { t=z; z=x; x=t; }
    if (y>z) { t=y; y=z; z=t; }
    printf("从小到大排序: %d %d %d\n",x,y,z);    
}