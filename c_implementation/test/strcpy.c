#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

// strcpy函数的实现 
// https://www.cnblogs.com/chenyg32/p/3739564.html

void my_memcpy(char * dst, const char * src, int cnt);

char * strcpy(char * dst, const char * src)
{
    assert(dst != NULL);

    char *ret = dst;

    // while ( (*dst++ = *src++) != '\0' );  // 内存重叠导致 Segmentation fault
    my_memcpy(dst, src, strlen(src) + 1);

    return ret;
}

void my_memcpy(char * dst, const char * src, int cnt)
{
    if (dst >= src && dst <= src + cnt - 1) // 唯一例外，内存重叠，从高地址开始复制
    {
        dst = dst + cnt - 1;
        src = src + cnt - 1;
        while (cnt--)
            *dst-- = *src--;
    }
    else
        while (cnt--)
            *dst++ = *src++;
}

int main(void)
{
    char *a = "hello";
    char *b = (char *)malloc(10);
    
    strcpy(b, a);

    printf("a: %s, b: %s\n", a, b);

    char c[10] = "hello";
    printf("c: %s\n", c);
    printf("c: %s\n", strcpy(c, c + 1));
    printf("c: %s\n", c);

    char d[10] = "hello";
    printf("d: %s\n", d);
    printf("d: %s\n", strcpy(d + 1, d)); // 内存重叠导致 Segmentation fault
    printf("d: %s\n", d);
}
