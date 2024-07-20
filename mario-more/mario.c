#include <cs50.h>
#include <stdio.h>
int get_height(void);
void print_grid(int height);
int main(void)
{
        int n = get_height();
        print_grid(n);
}
//Get height
int get_height(void)
{
    int n;
    do
    {
        n = get_int("Heigh: ");
    }
    while( n < 1 || n > 8);
    return n;
}
//Print out

void print_grid(int height)
{
 int i;
    for( int a = 1; a <= height; a++)
    {
        for(i = 1; i <= (height-a); i++)
        {
            printf(" ");
        }
        for(int b = 1; b <= a; b++)
        {
            printf("#");
        }
            printf("  ");
            for(int b = 1; b <= a; b++)
            printf("#");
    printf("\n");
    }
}
