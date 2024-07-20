#include <cs50.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    // get height
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while(n < 1 || n > 8);
    //Build
    int i;
    for( int a = 1; a <=n; a++)
    {
        for(i = 1; i <= (n-a); i++)
        {
            printf(" ");
        }
        for(int b = 1; b <= a; b++)
        {
            printf("#");
        }
    printf("\n");
    }
}
