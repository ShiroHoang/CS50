#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Get size of the grid
    int n;
    do
    {
        n = get_int("Size: ");
    }
    while (n < 1);

    // print grid of bricks
    for ( int i = 0; i < n; i++)
    {
        for ( int t = 0; t < n; t++)
        {
            printf("#");
        }
        printf("\n");
    }
}