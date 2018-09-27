#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// No "magic numbers" in code
#define ALPHABET_SIZE 26
#define UPPERCASE_A 65
#define LOWERCASE_A 97

int main(int argc, string argv[])
{
    // We expect only one argument
    // No other conditions to check as per specification. We trust/assume user is doing good...
    if (argc != 2)
    {
        printf("Usage: %s k\n", argv[0]);
        return 1;
    }

    // Convert user input from string to integer
    int key = atoi(argv[1]);

    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");

    // Loop over plaintext and print ciphertext
    // No lecture about string concatenation yet, thus ugly printf here.
    for (int i = 0, ptlen = strlen(plaintext); i < ptlen; i++)
    {
        char plaintext_letter = plaintext[i];

        if (isalpha(plaintext_letter))
        {
            // Preserve case
            if (isupper(plaintext_letter))
            {
                // Shift plaintext character by key
                // Convert ascii to alphabetical index in meantime
                printf("%c", ((plaintext_letter - UPPERCASE_A + key) % ALPHABET_SIZE) + UPPERCASE_A);
            }

            if (islower(plaintext_letter))
            {
                printf("%c", ((plaintext_letter - LOWERCASE_A + key) % ALPHABET_SIZE) + LOWERCASE_A);
            }
        }
        else
        {
            printf("%c", plaintext_letter);
        }
    }

    printf("\n");
    return 0;
}
