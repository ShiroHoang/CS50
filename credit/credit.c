#include <cs50.h>
#include <stdio.h>
#include <math.h>
int First_Sum( long credit);
int Second_sum(long credit);
long Amount_Digits(long credit);
bool VISA(long credit, int m, int n);
bool MASTERCARD(long credit, int m, int n);
bool AMEX(long credit, int m, int n);
int main(void)
{
    int n = 0;
    long credit = get_long("Number: ");
    int m = Amount_Digits(credit);
    int a = First_Sum(credit);
    int b = Second_sum(credit);
    n = First_Sum(credit) + Second_sum(credit);
    if( VISA(credit, m, n) == true)
    {
        printf("VISA\n");
    }
    else if( MASTERCARD(credit, m, n) == true)
    {
        printf("MASTERCARD\n");
    }
    else if( AMEX(credit, m, n) == true)
    {
        printf("AMEX\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

//Sum1
int First_Sum( long credit)
{
    credit = (long) credit / 10;
    int sum = 0;
    while ( credit > 0 )
    {
        int the_digit = credit % 10;
        credit = credit / 100;
        int n = the_digit * 2;
        if( n < 10 )
        {
            sum = sum + n;
        }
        else if ( n >= 10)
        {
            sum = sum + ((int) n /10 ) + ( n % 10);
        }
    }
    return sum;
}

//Sum2
int Second_sum(long credit)
{
    int sum2 = 0;
    while (credit > 0 )
    {
        int n = credit % 10;
        sum2 = sum2 + n;
        credit = credit / 100;
    }
    return sum2;
}
//Get credit
long Amount_Digits(long credit)
{
    long n = credit;
    int m = 0;
    do
    {
        n = n / 10;
        m++;
    }
    while( n > 0);
    return m;
}
// Check VISA
bool VISA(long credit, int m, int n)
{
    int First_Num = 0;
    if( m == 16 && n %  10 == 0)
    {
        First_Num = credit / pow(10, 15);
    }
    else if ( m == 13 && n % 10 == 0)
    {
        First_Num = credit / pow(10, 12);
    }
    if ( First_Num == 4)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Check MASTERCARD
bool MASTERCARD(long credit, int m, int n)
{
    int FirstTwoNum = 0;
    if (m == 16 && n % 10 == 0)
    {
        FirstTwoNum = credit / pow(10, 14);
    }
    if(FirstTwoNum > 50 && FirstTwoNum < 56)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Check AMEX
bool AMEX(long credit, int m, int n)
{
    int FirstTwoNum = 0;
    if (m == 15 && n % 10 == 0)
    {
        FirstTwoNum = credit / pow(10, 13);
    }
    if(FirstTwoNum == 37 || FirstTwoNum == 34)
    {
        return true;
    }
    else
    {
        return false;
    }
}
