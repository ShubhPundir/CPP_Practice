#include <stdio.h>

void swapNum(int * a, int *b)
{
    printf("SWAP FUNCTION BEGIN\n\n");

    printf("a=%d and &a=%d\n",a,&a);
    printf("b=%d and &b=%d\n",b,&b);


    // int t;
    // t = a;
    // a = b;
    // b = t;

    int t;
    t = *a;
    printf("t=%d and &t=%d\n",t,&t);
    *a = *b;
    *b = t;


    printf("a=%d and &a=%d\n",a,&a);
    printf("b=%d and &b=%d\n",b,&b);
    printf("SWAP FUNCTION ENDED\n\n");
}
int main()
{

    int x = 10;
    int y = 2;

    printf("x=%d and &x=%d\n",x,&x);
    printf("y=%d and &y=%d\n",y,&y);
    swapNum(&x,&y);
    printf("x=%d and &x=%d\n",x,&x);
    printf("y=%d and &y=%d\n",y,&y);
    return 0;
}