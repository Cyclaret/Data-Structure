// binary tree by linked list

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} node;

node *createNode(int data)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

node *buildTree(int arr[], int index, int size)
{ // 만드는건 정 이진트리 방식으로 순서대로 넣고 인덱스 이동 공식으로 다음 node 이동
    if (index >= size)
    {
        return NULL;
    }
    node *root = createNode(arr[index]);
    root->left = buildTree(arr, 2 * index + 1, size);
    root->right = buildTree(arr, 2 * index + 2, size);

    return root;
}

// VLR
void preorder(node *target, int size)
{
    if (target == NULL)
    {
        return;
    }
    printf("%d, ", target->data);
    preorder(target->left, size);
    preorder(target->right, size);
}

// LVR
void inorder(node *target, int size)
{
    if (target == NULL)
    {
        return;
    }
    inorder(target->left, size);
    printf("%d, ", target->data);
    inorder(target->right, size);
}

// LRV
void postorder(node *target, int size)
{
    if (target == NULL)
    {
        return;
    }
    postorder(target->left, size);
    postorder(target->right, size);
    printf("%d, ", target->data);
}

int main(void)
{
    int data[] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(data) / sizeof(data[0]);
    node *tree = buildTree(data, 0, size);

    printf("preorder : ");
    preorder(tree, size);
    printf("\n");

    printf("inorder : ");
    inorder(tree, size);
    printf("\n");

    printf("postorder : ");
    postorder(tree, size);
    printf("\n");
}