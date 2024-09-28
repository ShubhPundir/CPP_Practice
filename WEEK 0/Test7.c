#include <stdio.h>

int main()
{
    int array[] = {10,20,30,40,50};
    int *ip, i;
    // printf("%d\n",ip);
    // printf("%d\n",array);
    // printf("%d\n",ip);
    for(ip = array + 4, i = 0; i<5;i++)
    {
        printf("%d ",i);
        printf("%d\n",ip[-i]);
    }
    
    
    return 0;
}