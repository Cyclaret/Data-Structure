// dummy node를 사용한 doubly linked List.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct {
    Node* head;  // dummy head
    Node* tail;  // dummy tail
} DList;

void initList(DList* list) {
    list->head = (Node*)malloc(sizeof(Node));
    list->tail = (Node*)malloc(sizeof(Node));

    list->head->prev = NULL;
    list->head->next = list->tail;

    list->tail->prev = list->head;
    list->tail->next = NULL;
}

void insertFront(DList* list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    Node* first = list->head->next;

    newNode->prev = list->head;
    newNode->next = first;

    list->head->next = newNode;
    first->prev = newNode;
}

void insertRear(DList* list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    Node* last = list->tail->prev;

    newNode->next = list->tail;
    newNode->prev = last;

    last->next = newNode;
    list->tail->prev = newNode;
}

void display(DList* list) {
    Node* cur = list->head->next;
    while (cur != list->tail) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

int main() {
    DList list;
    initList(&list);

    insertFront(&list, 10);
    insertRear(&list, 20);
    insertFront(&list, 5);
    insertRear(&list, 30);

    display(&list);  // 출력: 5 10 20 30

    return 0;
}