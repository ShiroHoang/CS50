#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int s;
    do
    {
        s = get_int("Start size: ");
    }
    while(s < 9);

    // TODO: Prompt for end size
    int e;
    do
    {
        e = get_int("End size: ");
    }
    while(e < s);

    // TODO: Calculate number of years until we reach threshold
    int i = 0;
    while (s < e)
    {
        s = s + ((int) s / 3) - ((int) s / 4);
        i++;
    }
    //Print out
    printf("Years: %i\n", i);
}
