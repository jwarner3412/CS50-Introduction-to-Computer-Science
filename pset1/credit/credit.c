#include <stdio.h>
#include <cs50.h>

// inputs credit card numbers, checks validity via Luhn's algorithm and number of digits, then determines card type

int main(void)
{
    // init vars
    int digit;
    int card_length = 0;
    long odd_sum = 0;
    long even_product = 0;

    // take input
    long card_input = get_long_long("Number: ");
    long card = card_input;

    // digit by digit from the back
    while (card)
    {
        digit = card % 10;
        card = card / 10;
        card_length++;
        // even numbers
        if (card_length % 2 == 0)
        {
            int product = digit * 2;
            // if double digit
            if (product > 9)
            {
                int d;
                // digit by digit (only 2)
                while (product)
                {
                    d = product % 10;
                    product = product / 10;
                    even_product += d;
                }
            }
            // single digit
            else
            {
                even_product += product;
            }
        }
        // odd numbers
        else
        {
            odd_sum += digit;
        }
    }

    // final check sum of algorithm
    int algo = even_product + odd_sum;

    // for powers without math lib to get first 2 placeholders easily
    long power = 1;
    for (int i = 0; i < card_length - 2; i++)
    {
        power *= 10;
    }

    // gets second digit
    long card_type2 = card_input / power;
    // gets first digit
    long card_type1 = card_type2 / 10;
    // sets 2nd digit with modulo, 1st digit set with base 10 division alone, for reference below
    card_type2 = card_type2 % 10;

    // check for proper length and algo checksum
    if ((card_length == 13 || card_length == 15 || card_length == 16) && algo % 10 == 0)
    {
        // check for card type
        if (card_type1 == 3 && (card_type2 == 4 || card_type2 == 7))
        {
            printf("AMEX\n");
        }
        else if (card_type1 == 4)
        {
            printf("VISA\n");
        }
        else if (card_type1 == 5 && (card_type2 > 0 && card_type2 < 6))
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    // on validity fail
    else
    {
        printf("INVALID\n");
    }
}