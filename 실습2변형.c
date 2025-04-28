#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int arr[10][10];
    int rows, cols;
    srand(time(NULL));

    printf("input row size and cols size of array : ");
    scanf("%d%d", &rows, &cols);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr[i][j] = rand() & 21;
        }
    }
    printMatrix(arr, rows);
}

// printMatrix
void printMatrix(int arr[][10], int rows) // 2d matrix를 parameter로 넘겨줄 때 두번째 이하는 크기 고정해야함
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

// findMaxMin2D
void findMaxMin2D(int arr[][10], int rows)
{
    int max = arr[0][0], min = arr[0][0];
    int maxi, maxj, mini, minj;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            if (arr[i][j] > max)
            {
                max = arr[i][j];
                maxi = i;
                maxj = j;
            }
            else if (arr[i][j] < min)
            {
                min = arr[i][j];
                mini = i;
                minj = j;
            }
        }
    }
    printf("max : %d (%d행 %d열), min : %d (%d행 %d열)\n", max, maxi, maxj, min, mini, minj);
}

// rowSumColSum