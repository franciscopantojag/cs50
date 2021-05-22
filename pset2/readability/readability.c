#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
//readability

int main(void)
{
    const string input = get_string("Text: ");
    const int n = strlen(input);
    int letters = 0;
    int words = 0;
    int sentences = 0;
    for (int i = 0; i < n; i++)
    {
        char actualChar = input[i];
        if (isalpha(actualChar))
        {
            letters++;
        }
        if (isspace(actualChar))
        {
            words++;
        }
        else
        {
            if (i == n - 1)
            {
                words++;
            }
        }



        if ((actualChar == '!') || (actualChar == '?') || (actualChar == '.'))
        {
            sentences++;

        }
        else
        {
            if (i == n - 1 && ((actualChar == '!') || (actualChar == '?') || (actualChar == '.')))
            {
                sentences++;
            }
        }
    }

    float L1 = (100 * letters) / (float)words;
    float S1 = (100 * sentences) / (float)words;

    float L = floorf(L1 * 100) / 100;
    float S = floorf(S1 * 100) / 100;


    int result = round(0.0588 * L - 0.296 * S - 15.8);
    if (result < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (result > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", result);
    }
}

