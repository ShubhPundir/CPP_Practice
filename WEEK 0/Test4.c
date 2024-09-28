#include <stdio.h>

int main()
{
    int x = 1;
    int y;

    y = (x=x+5,x*5);
    printf("%d",y);
    printf(" %d",x);
    return 0;
}