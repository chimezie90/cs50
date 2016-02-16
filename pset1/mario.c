#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        printf("please enter a positive integer less than 23: ");
        scanf("%i", &height);
    }
    while ((height > 23) || (height < 0) );
        
    
    for (int x = 0; x < height; x++)
    {
        for (int y = 0; y < height - x - 1; y++)
        {
            printf(" ");
        }
        for (int y = 0; y < x + 2; y++)
        {
            printf("#");
        }
        printf("\n");
    }
}