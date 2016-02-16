#include <stdio.h>
#include <math.h>

int main(void)
{
    int quarter = 25;
    int dime  = 10;
    int nickel = 5;
    
    int q, d, n, p = 0;
    
    float change;
    
    do 
    {
        printf("How much change is owed? ");
        scanf("%f", &change);
    }
    while (change < 0);
    
    int x = round(change*100);
    int coins = 0;
    
    while (x>0)
    {
        if (x >= 25)
        {
            
            int div = x/quarter;
            coins += div;
            q = div;
            x -= div*quarter;
        }
        else if (x >= 10)
        {
            
            int div = x/dime;
            d = div;
            coins += div;
            x -= div*dime;
        }
        else if (x >= 5)
        {
            
            int div = x/nickel;
            coins += div;
            n = div;
            x -= div*nickel;
        }
        
        else
        {
            coins += x;
            p = x;
            x -= x;
            
        }
    }
    
    printf("%i\n", coins);
}