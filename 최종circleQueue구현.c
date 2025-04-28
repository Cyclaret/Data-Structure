#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *data;
    int size;
    int front;
    int rear;
} cq;

// 배열이라서 * 하나면 충분
void createCQ(cq *q, int number);
void enqueue(cq *q, int number);
int dequeue(cq *q);
void freeQ(cq *q);
void printCQ(cq *q, int number);

int main(void)
{
    cq q; // circle queue는 배열기반이라서 *q처럼 굳이 동적할당할 필요가 없음. 나중에 free도 귀찮은데 뭐하러? 걍 cq q; 훨 편함
    int number, number2;

    printf("원형 큐의 크기를 입력. (data 개수 + 1 해야함) : ");
    scanf("%d", &number);
    createCQ(&q, number);

    for (int i = 0; i < number - 1; i++)
    {
        printf("자연수 입력 : ");
        scanf("%d", &number2);
        enqueue(&q, number2);
    }
    printCQ(&q, number);

    printf("\n가장 오래된 값 없앰 : %d\n", dequeue(&q));

    freeQ(&q);
    return 0;
}

void createCQ(cq *q, int size)
{
    q->data = (int *)malloc(sizeof(int) * size); // 배열을 만듦 : cq는 배열이 좋음
    q->size = size;
    q->front = 0;
    q->rear = 0;
}

void enqueue(cq *q, int value)
{
    if ((q->rear + 1) % q->size == q->front) // array full의 조건
    {
        printf("array full.\n");
        return;
    }
    q->rear = (q->rear + 1) % q->size;
    q->data[q->rear] = value; // 이거 node 아니다. 배열이라서 이런식으로 넣는 게 맞다.
    printf("값 넣음 : %d\n", q->data[q->rear]);
}

int dequeue(cq *q)
{
    if (q->rear == q->front) // array empty의 조건
    {
        printf("array empty.\n");
        return -1;
    }
    q->front = (q->front + 1) % q->size; // FIFO에 따라 front 한칸 이동한 곳이 가장 오래된 곳
    return q->data[q->front];            // 해서 거기 값을 return
}

void freeQ(cq *q)
{
    free(q->data);
}

void printCQ(cq *q, int number)
{
    // 가장 오래된 값부터 순서대로 출력
    
    // i 쓰는 이유는 함부로 front, rear 건드리면 원본이 바뀌어서 그럼. 어차피 반복만 할거면 i가 안전함
    int i = (q->front + 1) % q->size; // i가 front 한칸 후부터 시작해서...
    while (i != (q->rear + 1) % q->size) // i == rear가 되는 곳이 마지막 출력
    {
        printf("%d, ", q->data[i]);
        i = (i + 1) % q->size;
    }
    printf("\n");
}