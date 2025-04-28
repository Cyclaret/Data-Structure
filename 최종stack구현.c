#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void push(Node **top, int value);
int peek(Node *top);
void pop(Node **top);

int main(void)
{
    typedef Node *Stack;
    Stack top = NULL;
    int number, number2;

    printf("몇 개의 data 입력? : ");
    scanf("%d", &number);

    for (int i = 0; i < number; i++)
    {
        printf("%d번째 정수 입력 : ", i + 1);
        scanf("%d", &number2);
        push(&top, number2);
    }
    printf("top data : %d\n", peek(top));
    for (int i = 0; i < number; i++)
    {
        printf("지우는 중...\n");
        pop(&top);
    }
    printf("top data : %d\n", peek(top));
}

void push(Node **top, int value)
{
    Node *temp = (Node *)malloc(sizeof(Node)); // temp는 Node 타입 포인터(주소)다.
    if (temp == NULL)
    {
        printf("malloc failed.\n");
        return;
    }
    temp->data = value;
    temp->next = *top;
    *top = temp;
}

int peek(Node *top)
{
    if (top == NULL)
    {
        printf("stack empty.\n");
        exit(1); // 사실 이건 프로그램 완전 종료라서 main에서 peek()하기 전에 top==NULL 예외처리하는거 추천
    }
    return top->data;
}

void pop(Node **top)
{
    if (*top == NULL)
    {
        return;
    }
    Node *temp = *top;
    int value = temp->data;
    *top = (*top)->next;
    free(temp);
}