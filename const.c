#include <stdio.h>

int main()
{
    const int a = 1234;
    int const b = 2345;

    const int *c = &a;
    c = &b;
    // *c = 3456; // read-only variable is not assignableC/C++

    int * const d = &a;
    // d = &b; // cannot assign to variable 'd' with const-qualified type 'int *const'
    *d = 3456;

    int const * const e = &a;
    // e = &b; // cannot assign to variable 'd' with const-qualified type 'int *const'
    // *e = 4567; // read-only variable is not assignableC/C++
}