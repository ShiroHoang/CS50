// Practice writing a function to find a max value

#include <cs50.h>
#include <stdio.h>

int max(int array[], int n);

int main(void)
{
    int n;
    do
    {
        printf("Number of elements: ");
        scanf("%d", &n);
    }
    while (n < 1);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
       printf("Element %i: ", i);
       scanf("%d", &arr[i]);
    }

    printf("The max value is %i.\n", max(arr, n));
}

// TODO: return the max value
int max(int array[], int n)
{
    int max = array[0];
    for(int i = 0; i < n; i++)
    {
        if(array[i] > max)
        {
            max = array[i];
        }
    }
    return max;
}
