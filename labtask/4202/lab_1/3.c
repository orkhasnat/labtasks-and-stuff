#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MIN(a, b) a < b ? a : b
//=======================================

int freq_counter(int n, int *arr)
{
    int count = 0, max, count_prev = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i] == arr[j])
                count++;
        }
        if (count_prev < count)
            max = arr[i];
        if (count_prev == count)
            max = MIN(max, arr[i]);
        count_prev = count;
        count = 0;
    }
    return max;
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("%d", freq_counter(n, arr));
    return 0;
}