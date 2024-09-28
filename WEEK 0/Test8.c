#include <stdio.h>

union uData
{
    int a; int b;
};
struct sData
{
    union uData c;
    int d;
};

int main()
{
    struct sData da = {10,20};

    printf("%ld ", sizeof(da));
    printf("%d %d %d", da.c.a, da.c.b, da.d);
    return 0;
}