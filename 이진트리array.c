// binary tree by array

#include <stdio.h>
#include <stdlib.h>

// buildtree ref from pa
int *buildTree(int size)
{
    int *pa = (int *)malloc(sizeof(int) * (size + 1));
    for (int i = 1; i < size + 1; i++)
    {
        printf("input value : ");
        scanf("%d", pa + i);
    }

    return pa;
}

// LVR
void inorder(int *arr, int index, int size)
{
    if (index > size)
    {
        return;
    }
    inorder(arr, 2 * index, size);
    printf("%d, ", arr[index]);
    inorder(arr, 2 * index + 1, size);
}

// VLR
void preorder(int *arr, int index, int size)
{
    if (index > size)
    {
        return;
    }
    printf("%d, ", arr[index]);
    preorder(arr, 2 * index, size);
    preorder(arr, 2 * index + 1, size);
}

// LRV
void postorder(int *arr, int index, int size)
{
    if (index > size)
    {
        return;
    }
    postorder(arr, 2 * index, size);
    postorder(arr, 2 * index + 1, size);
    printf("%d, ", arr[index]);
}

int main(void)
{
    int size;
    printf("how many? : ");
    scanf("%d", &size);
    int *arr = buildTree(size);
    inorder(arr, 1, size);
    printf("\n");
    preorder(arr, 1, size);
    printf("\n");
    postorder(arr, 1, size);
    printf("\n");
}