#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
bool check_dup(string s);

int main(int argc, string argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    if(strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    for(int i = 0; i < strlen(argv[1]); i++)
    {
        if(!isalpha(argv[1][i]))
        {
            return 1;
        }
    }
    bool a = check_dup(argv[1]);
    if (a == true)
    {
        return 1;
    }
    string plaintext = get_string("plaintext: \n");
    printf("ciphertext: ");
    for(int t = 0; t < strlen(plaintext); t++)
    {
        if(!isalpha(plaintext[t]))
        {
            printf("%c", plaintext[t]);
            continue;
        }
        if(islower(plaintext[t]))
        {
            printf("%c", tolower(argv[1][plaintext[t] - 'a']));
        }
        if(isupper(plaintext[t]))
        {
            printf("%c", toupper(argv[1][plaintext[t] - 'A']));
        }
    }
    printf("\n");
}

// check_dup
bool check_dup(string s)
{
    int m = 0;
    for(int i = 1; i < strlen(s); i++)
    {
        for(int k = i - 1;k >= 0; k--)
        {
            if(s[i] == toupper(s[k]) || s[i] == tolower(s[k]))
            {
                m++;
            }
        }
    }
    if(m > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}