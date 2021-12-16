#include <stdio.h>

int sum(int a, int b) {
    int tmp;
    tmp = a + b;
    return tmp;
}

int main()
{
    int a = 1;
    int b = 2;
    int ret = sum(a, b);
    printf("ret = %d\n", ret);
    return 0;
}