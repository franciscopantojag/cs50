#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        string commandLineArg = argv[1];
        const int commandLineArgLength = strlen(commandLineArg);
        for (int i = 0; i < commandLineArgLength; i++)
        {
            char acChar = commandLineArg[i];
            if (!isdigit(acChar))
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
        const string plaintext = get_string("plaintext: ");
        const int plaintTextLength = strlen(plaintext);
        char ciphertext[plaintTextLength];
        for (int j = 0; j < plaintTextLength; j++)
        {
            char actualChar = plaintext[j];
            int actualCharInt = (int) plaintext[j];
            int argument = atoi(commandLineArg);
            if (isupper(actualChar))
            {

                ciphertext[j] = (char)(64 + (((actualCharInt - 64) + argument) % 26));
            }
            else if (islower(actualChar))
            {

                ciphertext[j] = (char)(96 + (((actualCharInt - 96) + argument) % 26));
            }
            else
            {

                ciphertext[j] = actualChar;
            }
        }
        printf("ciphertext: ");
        for (int k = 0; k < plaintTextLength; k++)
        {
            if (k == plaintTextLength - 1)
            {
                printf("%c\n", ciphertext[k]);
            }
            else
            {
                printf("%c", ciphertext[k]);
            }
        }
    }
    else
    {
        printf("Number of arguments is incorrect\n");
        return 1;
    }

}