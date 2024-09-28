#include <stdio.h>

enum Covid_prevention
{
    Sanitizer = 1,
    WEar_Mask = 2,
    Soc_Distance = 4
};
int main()
{
    int myCovidPrevention = WEar_Mask | Soc_Distance;
    printf("%d", myCovidPrevention);
    return 0;
}