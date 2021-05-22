#include <cs50.h>
#include <stdio.h>
#include <math.h>

float get_positive_float(void);

int main(void)
{
    int cents = round(get_positive_float() * 100);
    int i = 0;
    while (cents > 0)
    {
        if ((cents - 25) >= 0)
        {
            cents = cents - 25;
        }
        else if ((cents - 10) >= 0)
        {
            cents = cents - 10;
        }
        else if ((cents - 5) >= 0)
        {
            cents = cents - 5;
        }
        else
        {
            cents = cents - 1;
        }
        i++;
    }
    printf("%d\n", i);
}


float get_positive_float(void)
{
    float n;
    do
    {
        n = get_float("%s", "Change owed: ");
    }
    while (n <= 0);
    return n;
}