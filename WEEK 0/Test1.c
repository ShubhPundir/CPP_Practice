#include <stdio.h>

int main()
{
    typedef double num[3];
    num array[5] = {1,2,3,4,5,6};

    printf("%d",sizeof(array));

    printf(" %.2f",array[1][1]);
    return 0;
}