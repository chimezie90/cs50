//used function GetInt() in the submitted version
#include <stdio.h>

int main(void)
{
    int minutes;
    printf("minutes: ");
    scanf("%i", &minutes);
    int bottles = 12 * minutes;
    printf("bottles: %i\n", bottles);
}
