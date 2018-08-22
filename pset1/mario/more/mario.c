#include <stdio.h>
#include <cs50.h>

// draws the double pyramid from mario in the console with whitespace and '#'

int height;

int main(void)
{
    // takes user input until input valid
    do
    {
        height = get_int("Height: ");
    }
    while (height > 23 || height < 0);

    // loops to build pyramid
    for (int i = 0; i < height; i++)
    {
        // puts in whitespace (left)
        for (int ii = i; ii < height - 1; ii++)
        {
            printf(" ");
        }
        // puts in pounds (left)
        for (int iii = height - i; iii < height + 1; iii++)
        {
            printf("#");
        }

        // middles spaces
        printf("  ");

        // puts in pounds (right)
        for (int iiii = height - i; iiii < height + 1; iiii++)
        {
            printf("#");
        }

        // puts in whitespace (right) obviously not needed lol
        // for (int iiiii = i; iiiii < height - 1; iiiii++)
        // {
        //     printf(" ");
        // }

        // line break
        printf("\n");
    }

}
