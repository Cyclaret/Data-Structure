/*
stack, queue 모두 골자는 linkedList를 사용하고, LIFO, FIFO같은 개념을 추가한다.

stack은 LIFO의 구조를 띈다.
1_linkedList.c에서 insert_front()는 값을 넣는데 사용함. pop()은 무조건 head를 없애는 것으로 구현
peek()은 가장 위의 값을 return하는 함수
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef Node* Stack;

void push(Stack* top, int value) { // node 만들기
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = *top; // node 추가는 항상 head를 가리키도록 (가장 위에 추가)
    *top = newNode;
}

int pop(Stack* top) { // top node를 지우는 함수
    if (*top == NULL) {
        printf("Stack is empty.\n");
        return -1;
    }
    Node* temp = *top;
    int value = temp->data;
    *top = temp->next; // top이 2번째를 가리키도록 (첫번째 node 삭제)
    free(temp);
    return value;
}

int peek(Stack top) { // top node의 data 읽는 함수
    if (top == NULL) {
        printf("Stack is empty.\n");
        return -1;
    }
    return top->data; // top node의 data return
}