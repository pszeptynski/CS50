#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Ask user for credit card number

    long long cc_number;
    do
    {
        cc_number = get_long_long("Credit card number: ");
    }
    while (cc_number < 0);

    // Check issuer. If invalid, there's no need to calculate checksum.

    string issuer = "";

    // Visa numbers all start with 4 and Visa uses 13- and 16-digit numbers
    if ((cc_number >= 4000000000000 && cc_number <= 4999999999999) ||
        (cc_number >= 4000000000000000 && cc_number <= 4999999999999999))
    {
        issuer = "VISA";
    }
    // American Express numbers all start with 34 or 37 and AmEx uses 15-digit numbers
    else if ((cc_number >= 340000000000000 && cc_number <= 349999999999999) ||
             (cc_number >= 370000000000000 && cc_number <= 379999999999999))
    {
        issuer = "AMEX";
    }
    // MasterCard numbers start with 51, 52, 53, 54, or 55 and MC uses 16-digit numbers
    else if (cc_number >= 5100000000000000 && cc_number <= 5599999999999999)
    {
        issuer = "MASTERCARD";
    }
    else
    {
        issuer = "INVALID";
    }

    // Check if card number is valid using Luhn’s algorithm

    int digit;
    int ccn_length = 0;
    int checksum = 0;
    
    while (cc_number > 0)
    {
        digit = cc_number % 10;     // Get last digit
        cc_number = cc_number / 10; // Cut last digit off
        ccn_length++;               // Number of digits in card's number but also a pointer

        if (ccn_length % 2)         // Odd digit - add to the checksum
        {
            checksum += digit;
        }
        else                        // Even digit - multiply by 2 and add those product's digits to the checksum
        {
            digit = digit * 2;
            checksum += ((digit % 10) + (digit / 10));
        }
    }


    // Check if last digit of checksum is 0
    // If it's not the card number is invalid.

    if (checksum % 10)
    {
        issuer = "INVALID";
    }

    printf("%s\n", issuer);
}
