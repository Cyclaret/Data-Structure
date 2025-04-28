#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef Node *list;

int main(void)
{
    list head, tail;
    head = tail = NULL;

    inputFront(&head, &tail, 10);
    inputLast(&head, &tail, 30);
    inputMid(&head, &tail, 20, 1);

    printList(head);
    deleteNode(&head, &tail, 2);
    printList(head);
}

list createNode(int data)
{
    list new = (list)malloc(sizeof(Node));
    if (new == NULL)
    {
        printf("malloc failed.\n");
        exit(1);
    }
    new->data = data;
    new->next = NULL;

    return new;
}

// input before front
void inputFront(list *head, list *tail, int data)
{
    list new = createNode(data);
    if (*head == NULL)
    {
        *head = new;
        *tail = new;
        return;
    }
    new->next = *head;
    *head = new;
}

void inputLast(list *head, list *tail, int data)
{
    list new = createNode(data);
    if (*head == NULL)
    {
        *head = new;
        *tail = new;
        return;
    }
    (*tail)->next = new;
    *tail = new;
}

void inputMid(list *head, list *tail, int data, int index)
{
    list new = createNode(data);
    if (*head == NULL)
    {
        *head = *tail = new;
        return;
    }
    list target = *head;

    for (int i = 0; i < index - 1; i++)
    {
        if (target != NULL)
        {
            target = target->next;
        }
        else
        {
            printf("index out of range.\n");
            free(target);
            return;
        }
    }
    new->next = target->next;
    target->next = new;
    if (new->next == NULL)
    {
        *tail = new;
    }
}

void deleteNode(list *head, list *tail, int index)
{
    if (*head == NULL)
    {
        printf("array empty.\n");
        return;
    }
    // head가 지울 대상인 경우
    if (index == 1)
    {
        list temp = *head; // temp 쓰는 이유는 free할라고
        *head = (*head)->next;
        if (*head == NULL) // 한 칸인 경우
        {
            *tail = NULL;
            free(temp);
            return;
        }
    }

    list prev = *head;
    for (int i = 0; i < index - 2; i++)
    {
        if (prev == NULL || prev->next == NULL)
        {
            printf("index out of range.\n");
            return;
        }
        prev = prev->next;
    }
    list target = prev->next;

    if (target == NULL)
    {
        printf("index out of range.\n");
        return;
    }
    prev->next = target->next;
    if (target == *tail)
    {
        *tail = prev;
    }
    free(target);
}