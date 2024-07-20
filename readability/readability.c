#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
int count_letters( string s);
int count_words( string s);
int count_sentences( string s);

int main(void)
{
    string s = get_string("Text: ");
    int n = count_letters(s);
    int m = count_words(s);
    int k = count_sentences(s);
    float L = (float)n / m * 100;
    float S = (float)k / m * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    if( index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if( index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        if( index -0.5 > (int) index)
        {
            printf("Grade %i\n", (int) ceil(index));
        }
        else
        {
            printf("Grade %i\n", (int) floor(index));
        }
    }
}

//count letters
int count_letters( string s)
{
    int m = 0;
    for(int i = 0, n = strlen(s); i < n; i++)
    {
        if(isalpha(s[i]))
        {
            m++;
        }
    }
    return m;
}

//count words
int count_words( string s)
{
    int m = 1;
    for(int i = 0, n = strlen(s); i < n; i++)
    {
        if(isblank(s[i]))
        {
            m++;
        }
    }
    return m;
}

// count sentences
int count_sentences( string s)
{
    int m = 0;
    for(int i = 0, n = strlen(s); i < n; i++)
    {
        if( s[i] == '.' || s[i] == '!' || s[i] == '?')
        {
            m++;
        }
    }
    return m;
}