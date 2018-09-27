#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// No "magic numbers" in code
#define ALPHABET_SIZE 26
#define UPPERCASE_A 65
#define LOWERCASE_A 97

int main(int argc, string argv[])
{
    // We expect only one argument
    if (argc != 2)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }

    string key = argv[1];
    int keylen = strlen(key);

    // Check if key does not contain any unwanted characters
    for (int i = 0; i < keylen; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("The key must be alphabetic.\n");
            return 1;
        }
    }

    // Get plaintext from user
    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");

    // Loop over plaintext and print ciphertext
    for (int i = 0, j = 0, ptlen = strlen(plaintext); i < ptlen; i++)
    {
        if (isalpha(plaintext[i]))
        {
            // Preserve case
            if (isupper(plaintext[i]))
            {
                // Implement Vigenere's cipher: Ci = (Pi + Kj) mod 26
                // Shift plaintext character by key's letter in a sequence
                // Convert ascii to alphabetical index in meantime

                printf("%c", (plaintext[i] - UPPERCASE_A + key[j] - (isupper(key[j]) ? UPPERCASE_A : LOWERCASE_A)) % ALPHABET_SIZE + UPPERCASE_A);
            }

            if (islower(plaintext[i]))
            {
                printf("%c", (plaintext[i] - LOWERCASE_A + key[j] - (isupper(key[j]) ? UPPERCASE_A : LOWERCASE_A)) % ALPHABET_SIZE + LOWERCASE_A);
            }

            // Use modulo for wraparound the index of key word
            j = (j + 1) % keylen;
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }

    printf("\n");
    return 0;
}
