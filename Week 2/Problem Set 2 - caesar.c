#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string key);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    if (argc < 2 || argc >= 3) // The program name is also counted as one of the arguments so we only want 2 arguments.
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        string key = argv[1];
        if (!only_digits(key)) // Error handling for keys that are not integers.
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
        else
        {
            int key_int = atoi(key); // Converts integers to a string of that integer.
            string plaintext = get_string("plaintext: ");
            int textlen = strlen(plaintext);
            printf("ciphertext: ");
            for (int i = 0; i < textlen; i++)
            {
                printf("%c", rotate(plaintext[i], key_int));
            }
            printf("\n");
            return 0;
        }
    }
}

bool only_digits(string key)
{
    int key_len = strlen(key);
    for (int i = 0; i < key_len; i++)  // Check whether each character is a digit or not.
    {
        if (!isdigit(key[i]))
        {
            return false;
        }
    }
    return true;
}

char rotate(char c, int n)
{
    if (!isalpha(c)) // Non-alphabets are returned as is.
    {
        return c;
    }
    else
    {
        if isupper(c)
        {
            int new_c_int = ((int) c - 65 + n) % 26; // 65 is the ASCII value for 'A'.
            // Subtraction is required to standardise 'A' as 0, 'B' is 1, etc.
            // The modulo operation is required to wrap the rotation after the letter 'Z'.
            new_c_int += 65; // Getting back the actual ASCII value.
            return new_c_int;
        }
        else
        {
            int new_c_int = ((int) c - 97 + n) % 26; // 97 is the ASCII value for 'a'
            // Subtraction is required to standardise 'a' as 0, 'b' is 1, etc.
            new_c_int += 97;
            return new_c_int;
        }
    }
}
