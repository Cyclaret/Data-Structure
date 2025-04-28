#include <stdio.h>
#include <stdlib.h>

void findLength(int *arr, int n)
{
    if (n == 0) {
        printf("longest : 0\n");
        return;
    }

    int maxLen = 1, currLen = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i - 1] <= arr[i]) {
            currLen++;
        } else {
            if (currLen > maxLen)
                maxLen = currLen;
            currLen = 1;
        }
    }

    if (currLen > maxLen)
        maxLen = currLen;

    printf("longest : %d\n", maxLen);
}

int main(void)
{
    int n;
    printf("how many? : ");
    scanf("%d", &n);

    int *arr = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        printf("input data : ");
        scanf("%d", &arr[i]);
    }

    // find length
    findLength(arr, n);
}
