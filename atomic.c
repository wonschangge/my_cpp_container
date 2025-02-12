#include <stdatomic.h>
#include <stdio.h>

atomic_int atomic_count = 0;

int atomic_inc(int *ptr)
{
    // return __atomic_fetch_add(ptr, 1, __ATOMIC_SEQ_CST);
    return atomic_fetch_add(&atomic_count, 1);
}

int main()
{
    int a = 5;
    atomic_inc(&a);

    printf("%d\n", a);

    return 0;
}
