#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct
{
    Node *head; // 이 Node는 위 구조체를 가리킴 (9번 줄)
    Node *tail;
} dll;

void init(dll *list) // 0 <- head <-> tail -> 0 형태로 초기화. 실제 node는 <-> 사이에 들어간다.
{
    list->head = (Node *)malloc(sizeof(Node));
    list->tail = (Node *)malloc(sizeof(Node));
    list->head->next = list->tail;
    list->tail->prev = list->head;
    list->head->prev = NULL;
    list->tail->next = NULL;
}

void insertAfter(Node *target, int data)
{ // target node 뒤에 삽입
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    newNode->prev = target;
    newNode->next = target->next;
    target->next->prev = newNode;
    target->next = newNode;
}

void append(dll *list, int data)
{
    insertAfter(list->tail->prev, data);
}

Node *findNode(dll *list, int index)
{ // index = 1이면 1번째 node 반환
    Node *target = list->head->next;
    for (int i = 0; i < index - 1; i++)
    {
        target = target->next;
    }
    return target;
}

void insert(dll *list, int data, int index)
{
    Node *target = findNode(list, index);
    insertAfter(target, data);
}

void deleteNode(Node *target)
{ // 삭제하려는 node가 head, tail 혹은 빈 배열이면 삭제 불가
    if (target == NULL || target->prev == NULL || target->next == NULL)
    {
        return;
    }
    target->prev->next = target->next;
    target->next->prev = target->prev;
    free(target);
}

void printdll(dll *list)
{
    Node *temp = list->head->next;
    while (temp != list->tail)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(void)
{
    dll *list = (dll *)malloc(sizeof(dll));
    init(list);

    append(list, 10);
    append(list, 20);
    append(list, 30);
    insert(list, 40, 2);

    printdll(list);

    deleteNode(findNode(list, 2));

    printdll(list);
}