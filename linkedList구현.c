#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;
typedef Node *list;
list head, tail;
head = NULL;
tail = NULL;

void insert(list **head, list **tail, int value);
int main(void)
{
    insert(&head, &tail, 3);
    printf("%d", head->data);
}

void insert(list **head, list **tail, int value)
{
    list temp = (list)malloc(sizeof(Node));
    temp->data = value;
    int index;
    printf("삽입할 위치 입력. ex) 1이면 첫 번째, 0이면 마지막 node : ");
    scanf("%d", &index);

    switch (index)
    {
    case (1):
        if (*head == *tail == NULL)
        {
            temp->next = *head;
            *head = temp;
        }
        break;
    case (0):
        if (*head == NULL) {
            *head = *tail = temp;
        }
        else {
            (*tail)->next = temp;
            tail = temp;
        }

    default:
        break;
    }
}