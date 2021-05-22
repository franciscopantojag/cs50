#include <cs50.h>
#include <stdio.h>

int get_number_between_one_and_eight(void);

int main(void)
{
    int height = get_number_between_one_and_eight();
    for (int i = 1; i <= height; i++)
    {
        int numberOfSpaces = height - i;
        for (int j = 1; j <= numberOfSpaces; j++)
        {
            printf(" ");
        }
        for (int k = 1; k <= i; k++)
        {
            if (k == i)
            {
                printf("#\n");
            }
            else
            {
                printf("#");
            }

        }
    }
}


int get_number_between_one_and_eight(void)
{
    int n;
    do
    {
        n = get_int("%s", "Height: ");
    }
    while (n < 1 || n > 8);
    return n;
}