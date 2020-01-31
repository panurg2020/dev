#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int arg, string argv[])
{   //check if there are 2 arguments
    if (arg != 2)
    {
        printf("Usage: ./substitution KEY (no blanks)\n");
        return (1);
    }
    //check if keyword is all letters
    int n = strlen(argv[1]);
    printf("Length: %d; ", n);
    // If the key is invalid (as by not containing 26 characters, containing any character that is not an alphabetic character, or not containing each letter exactly once), your program should print an error message of your choice (with printf) and return from main a value of 1 immediately.
    for (int i = 0; i < n; i++)
    {
        if (!isalpha(argv[1][i]) || n != 26)
        {
            printf("Usage: ./substitution KEY (must be 26 alphabetical characters)\n");
            return (1);
        }
        for (int j = i + 1 ; j < n; j++)
        {
            if (argv[1][i] == argv[1][j])
            {
                printf("Usage: ./substitution KEY (must contain each letter exactly once)\n");
                return (1);
            }
        }
        if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
        {
            argv[1][i] = argv[1][i] - 32;

        }
    }
    printf("The KEY is - %s\n", argv[1]);
    //Your program must output plaintext: (without a newline) and then prompt the user for a string of plaintext (using get_string).
    string plaintext = get_string("plaintext: ");
    string ciphertext = plaintext;
    int strLen = strlen(plaintext);
    int j = 0;
    for (int i = 0; i < strLen; i++)
    {
        if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
        {
            ciphertext[i] = argv[1][toupper(plaintext[i]) - 65];
        }
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
        {
            ciphertext[i] = tolower(argv[1][toupper(plaintext[i]) - 65]);
        }

        if (plaintext[i] == ' ')
        {
            ciphertext[i] = ' ';
        }
    }
    // ret 0 and ciphertext
    printf("ciphertext: %s\n", ciphertext);
    return (0);
}