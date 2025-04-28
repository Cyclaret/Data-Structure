// 득도 version. 이제 뭐 사실 복붙도 필요없음 이제 다 짤 수 있다. 

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef Node *queue;

void enqueue(Node **front, Node **rear, int number);
void peek(Node *front);
void dequeue(Node **front, Node **rear);

int main(void)
{
    queue front, rear;
    front = rear = NULL;
    int number;

    printf("3개의 정수 입력 : ");
    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &number);
        enqueue(&front, &rear, number);
    }
    peek(front);
    for (int i = 0; i < 3; i++)
    {
        printf("지우는 중...\n");
        dequeue(&front, &rear);
    }
    peek(front);

    return 0;
}

void enqueue(Node **front, Node **rear, int number)
{ // 배열이 비어있냐 차 있냐를 잘 확인할 것
    queue temp = (Node *)malloc(sizeof(Node));
    if (temp == NULL)
    {
        printf("malloc failed.\n");
        exit(1);
    }
    temp->data = number;
    temp->next = NULL;

    // 비어있다면 한번에 초기화
    if (*front == NULL)
    {
        *front = *rear = temp;
        return;
    }
    // 비어있지 않다면 rear 뒤에 추가
    (*rear)->next = temp;
    *rear = temp;
}

void dequeue(Node **front, Node **rear)
{ // *front의 이동 시 NULL 접근 주의!!!
    if (*front != NULL) // 배열이 비어있지 않다면 실행
    {
        Node *temp = *front; // 이건 temp가 단순히 책갈피 역할을 하므로 malloc 금지
        *front = (*front)->next;
        if ((*front)->next == NULL)
        { // 배열이 한칸이라 front 뒤로 이동했더니 NULL 뜬다면 전부 NULL로 바꿈
            *front = *rear = NULL;
        }
        free(temp);
    }
}

void peek(Node *front)
{
    if (front != NULL)
    {
        printf("peek value : %d\n", front->data);
    }
    else
        printf("queue is empty.\n");
}