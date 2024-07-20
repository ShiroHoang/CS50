#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool check(string s);

int main(int argc, string argv[])
{
    if( argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
        bool n = check(argv[1]);
        if( n == false)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
        else
        {
            string s = get_string("plaintext: ");
            int m = atoi(argv[1]);
            printf("ciphertext: ");
            for(int i = 0; i < strlen(s); i++)
            {
                if(isupper(s[i]))
                {
                    printf("%c", (s[i] - 'A' + m) % 26 + 'A');
                }
                else if(islower(s[i]))
                {
                    printf("%c", (s[i] - 'a' + m) % 26 + 'a');
                }
                else
                {
                    printf("%c", s[i]);
                }
            }
            printf("\n");
    }
}

// check number
bool check(string s)
{
    int n = 0;
    int m = 0;
    while(n < strlen(s))
    {
        if(isalpha(s[n]))
        {
            m++;
        }
        n++;
    }
    if(m > 0)
    {
        return false;
    }
    else
    {
        return true;
    }

}