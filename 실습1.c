#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inputArray(int arr[], int size);
void findMaxMin(int arr[], int size);
void searchValue(int arr[], int size);
void rotateArray(int arr[], int size);
void sortArray(int arr[], int size);
void printArray(int arr[], int size);

int main(void)
{
    int arr[100];
    int size;

    srand(time(NULL));

    printf("입력할 정수 개수 n을 입력 (최대 100개) : ");
    scanf("%d", &size);

    inputArray(arr, size);
    printArray(arr, size);
    findMaxMin(arr, size);
    searchValue(arr, size);
    rotateArray(arr, size);
    sortArray(arr, size);
    printArray(arr, size);

    return 0;
}

void inputArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() & 101;
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}

void findMaxMin(int arr[], int size)
{
    int max = arr[0], min = arr[0];

    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        else if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    printf("max : %d, min : %d\n", max, min);
}

void searchValue(int arr[], int size)
{
    int number;
    printf("input value to search : ");
    scanf("%d", &number);

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == number)
        {
            printf("value is in %d index.\n", i);
            return;
        }
    }
    printf("Arr doesn't have value want to find.\n");
}

void rotateArray(int arr[], int size)
{
    char answer;
    printf("rotate? (y/n) : ");
    scanf(" %c", &answer);

    while (answer == 'y' || answer == 'Y')
    {
        int j = size - 1;
        int temp = arr[j];
        while (j > 0)
        {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[0] = temp;

        printArray(arr, size);

        printf("rotate more? (y/n) : ");
        scanf(" %c", &answer);
    }
}

void sortArray(int arr[], int size)
{ // insertion sort
    int i, j, key;
    for (i = 1; i < size; i++)
    {
        key = arr[i];
        for (j = i - 1; j >= 0; j--)
        {
            if (key < arr[j])
            {
                arr[j + 1] = arr[j];
            }
            else
                break;
        }
        arr[j + 1] = key;
    }
}
