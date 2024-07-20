#include <stdio.h>
#include <cs50.h>
const int N = 3;

float average(int array[], int length);

int main(void)
{
    int score[N];
    for(int i = 0; i < N; i++)
    {
        score[i]=get_int("Score: ");
    }
    printf("Average score: %f\n", average(score, N));
}

float average(int array[], int length)
{
    int sum = 0;
    for(int i = 0; i < length; i++)
    {
        sum += array[i];
    }
    return sum / (float)length;
}