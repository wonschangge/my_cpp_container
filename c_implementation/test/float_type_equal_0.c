#include <stdio.h>

int main() {
    int x = 0xFFFFFFFF;
    printf("%d\n", x);

    printf("%d\n", sizeof("hello"));


    float a = 0.0;
    const float EPSINON = 0.00001;
    if ((a >= -EPSINON) && (a <= EPSINON))
        printf("a == 0.0\n");

    return 0;
}