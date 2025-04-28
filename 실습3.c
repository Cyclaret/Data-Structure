#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
} node;

void makeList(node **); // head를 전달해서 리스트 생성
void viewList(node *);  // 리스트 출력

node *findLast(node *); // head를 전달해서 마지막 노드의 포인터 리턴

void insertList(node **, node *, int); // head, target, inputData를 주면 node 추가

int main(void)
{
    node *head = NULL;
    makeList(&head);
    viewList(head);
}

node *findLast(node *hptr)
{
    if (hptr != NULL)
    {
        node *target = hptr;
        while (target->link != NULL)
        {
            target = target->link;
        }
        return target;
    }
    return hptr;
}

void makeList(node **hptr)
{
    node *pre = NULL;
    node *new = NULL;
    int data;

    printf("입력할 데이터는 (-1 입력 시 종료) : ");
    scanf("%d", &data);

    while (data != -1)
    {
        pre = findLast(*hptr);
        insertList(hptr, pre, data);
        printf("Enter data again : ");
        scanf("%d", &data);
    }
}

void insertList(node **hptr, node *pptr, int data)
{
    node *new = (node *)malloc(sizeof(node));
    new->data = data;
    new->link = NULL;

    if (*hptr == NULL)
    {
        *hptr = new;
    }
    else if (pptr == NULL)
    {
        new->link = *hptr;
        *hptr = new;
    }
    else
    {
        new->link = pptr->link;
        pptr->link = new;
    }
}

void viewList(node *hptr)
{
    while (hptr != NULL)
    {
        printf("%d ", hptr->data);
        hptr = hptr->link;
    }
    printf("\n");
}