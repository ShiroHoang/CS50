#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    // TODO
    int length = strlen(input);
    if(length == 1)
    {
        return input[0] - '0';
    }
    char last_digit = input[length - 1];
    input[length - 1] = '\0';
    int convert_last_digit = last_digit - '0';
    return convert_last_digit + 10*convert(input);
}