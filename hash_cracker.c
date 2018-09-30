//Assume that each password has been hashed with C’s DES-based (not MD5-based) crypt function.
//Assume that each password is no longer than five (5) characters. Gasp!
//Assume that each password is composed entirely of alphabetical characters (uppercase and/or lowercase).

// Hashes provided for testing:
// anushree:50xcIMJ0y.RXo
// brian:50mjprEcqC/ts
// bjbrown:50GApilQSG3E2
// lloyd:50n0AAUD.pL8g
// malan:50CcfIk1QrPr6
// maria:509nVI8B9VfuA
// natmelo:50JIIyhDORqMU
// rob:50JGnXUgaafgc
// stelios:51u8F0dkeDSbY
// zamyla:50cI2vYkF0YU2

// Beware, cracking longer passwords (like malan's, lloyd's, jbrown's which are 5-letter words) could take more than 15+ minutes

#include <cs50.h>
#include <crypt.h>
#include <stdio.h>
#include <string.h>
#define _XOPEN_SOURCE
#include <unistd.h>

#define MAX_PW_LENGTH 5
#define HASH_SIZE 13

int main(int argc, string argv[])
{
    // We expect only one 13-chars long argument
    if (argc != 2 || strlen(argv[1]) != HASH_SIZE)
    {
        printf("Usage: %s hash\n", argv[0]);
        return 1;
    }

    string hash = argv[1];
    // Get salt from entered hash
    char salt[3] = {hash[0], hash[1], '\0'};

    string new_hash = "";
    int generator(char *letters, int size);
    bool compare_hashes(string hash, string new_hash);


// Iterate over up to MAX_PW_LENGTH-letter words, hash them and compare results with provided hash

    char letters[MAX_PW_LENGTH] = {0};

    while (generator(letters, MAX_PW_LENGTH))
    {
        new_hash = crypt(letters, salt);

        if (compare_hashes(hash, new_hash))
        {
            printf("Hashes match. The key for hash: %s is: %s\n", hash, letters);
            return 0;
        }
    }

    printf("Unable to crack provided hash.\n");
    return 1;
}

int generator(char *letters, int size)
{
    for (int i = 0; i < size; i++)
    {
        // Wrap around
        if (letters[i] == '\0')
        {
            letters[i] = 'A';
            break;
        }
        // Switch to lower case
        if (letters[i] == 'Z')
        {
            letters[i] = 'a';
            break;
        }
        // Reset
        if (letters[i] == 'z')
        {
            if (i == size - 1)
            {
                return 0;
            }
            letters[i] = 'A';
        }

        else
        {
            letters[i]++;
            break;
        }
    }

    return 1;
}

bool compare_hashes(string hash, string new_hash)
{
    for (int i = 0; i < HASH_SIZE; i++)
    {
        if (hash[i] != new_hash[i])
        {
            return false;
        }
    }

    return true;
}
