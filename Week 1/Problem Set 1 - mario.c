#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;

    // Get height from user
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // Printing pyramid
    for (int i = 1; i < height + 1; i++) // Starting from 1 for easier understanding
    {
        int no_of_gaps = height - i;
        // Printing gaps
        for (int j = 0; j < no_of_gaps; j++)
        {
            printf(" ");
        }

        // Printing bricks
        for (int k = 0; k < i; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}
