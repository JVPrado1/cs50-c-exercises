#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

string criptografar(string plaintext, int key);
string copy_string(string text);

int main(int argc, string argv[])
{
    // Make sure program was run with just one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Make sure every character in argv[1] is a digit
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // Convert argv[1] from a `string` to an `int`
    int key = atoi(argv[1]);

    // Prompt user for plaintext
    string plaintext = get_string("plaintext: ");
    string cripto = copy_string(plaintext);
    cripto = criptografar(cripto, key);

    printf("key: %i\n", key);
    printf("plaintext: %s\n", plaintext);
    printf("ciphertext: %s\n", cripto);
}

// For each character in the plaintext:

string criptografar(string plaintext, int key)
{
    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (isalpha(plaintext[i]))
        {
            if (isupper(plaintext[i]))
            {
                plaintext[i] = ((plaintext[i] - 'A' + key) % 26) + 'A';
            }
            else if (islower(plaintext[i]))
            {
                plaintext[i] = ((plaintext[i] - 'a' + key) % 26) + 'a';
            }
        }
    }
    return plaintext;
}

string copy_string(string text)
{
    string copy = malloc(strlen(text) + 1);
    strcpy(copy, text);
    return copy;
}
