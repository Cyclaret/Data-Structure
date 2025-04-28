// 기존 1이랑 다른건 조금 더 필요없는 code 최적화. 완전 양식이라 가져다쓰면 됨. logic 공부하려고 복습하는거임

#include <stdio.h>
#include <stdlib.h>

typedef struct node_type
{
    int data;
    struct node_type *next;
} node;

typedef node *list; // 객체 선언

// create_node
list create_node(int data)
{
    list new_node = (list)malloc(sizeof(node));
    if (new_node == NULL)
    {
        printf("malloc failed.\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert_front(node**head, list *tail, int data);
void insert_back(list *head, list *tail, int data);
void insert_middle(list *head, list *tail, int data, int pos);
int search_value(list head, int value);
void delete_value(list *head, list *tail, int value);
void show_list(list list);

int main(void)
{
    list head, tail;
    head = tail = NULL;

    printf("=== Insert Front ===\n");
    insert_front(&head, &tail, 10);
    insert_front(&head, &tail, 20);
    insert_front(&head, &tail, 30);
    show_list(head);

    printf("=== Insert Back ===\n");
    insert_back(&head, &tail, 40);
    insert_back(&head, &tail, 50);
    show_list(head);

    printf("=== Insert Middle (at pos 2) ===\n");
    insert_middle(&head, &tail, 25, 2);
    show_list(head);

    printf("=== Search Value ===\n");
    int pos = search_value(head, 25);
    if (pos != -1)
        printf("25 found at position %d\n", pos);
    else
        printf("25 not found\n");

    printf("=== Delete Value (25) ===\n");
    delete_value(&head, &tail, 25);
    show_list(head);

    printf("=== Delete Value (100, not in list) ===\n");
    delete_value(&head, &tail, 100);
    show_list(head);

    return 0;
}

// insert_front
void insert_front(list *head, list *tail, int data) // flaw chart로 logic 기억
{
    list temp = create_node(data);
    temp->next = *head;
    *head = temp;
    if (*tail == NULL)
    {
        *tail = temp;
    }
}
// insert_back
void insert_back(list *head, list *tail, int data)
{
    list temp = create_node(data);
    if (*head == NULL)
    {
        *head = *tail = temp;
    }
    else
    {
        (*tail)->next = temp; // 괄호 주의
        *tail = temp;
    }
}
// insert_middle
void insert_middle(list *head, list *tail, int data, int pos)
{ // pos = n이라면 n번째 node 뒤에 temp가 들어간다. 최종적으로 n+1 node가 됨. 이 함수는 좀 어려우니 logic 잘 볼것...
    if (*head == NULL)
    {
        printf("list가 비어있으면 안됨\n");
        return;
    }
    if (pos < 1)
    {
        printf("pos >= 1 이상이어야 함\n");
        return;
    }
    list temp = create_node(data);
    list target = *head;
    // target이 pos회 이동 && 이동했더니 NULL을 가리키면 안됨
    for (int i = 0; i < pos; i++)
    {
        if (target != NULL)
        {
            target = target->next;
        }
        else
        {
            printf("pos out of range/\n");
            free(temp); // 주의 : free하고 return
            return;
        }
    }
    temp->next = target->next;
    target->next = temp; // 이 두 줄은 순서가 매우 중요함. 바꾸면 temp->next가 temp를 가리키게 되어 logic Error

    if (temp->next == NULL)
    { // tail 처리
        *tail = temp;
    }
}
// search value : 이전 코드에서 훨씬 간단하게 바꿈. return type도 int로 바꿈. 단, 중복되는 값을 모두 찾고싶다면 이전 code를 사용.
int search_value(list head, int value)
{
    int pos = 1;
    while (head != NULL)
    {
        if (head->data == value)
        {
            return pos; // 찾은 위치 return
        }
        head = head->next;
        pos++;
    }
    return -1; // 못찾은 경우 (list가 비어있는 경우 포함)
}
// delete_value. 핵심은 : 찾았어? 그럼 어디 위치인지 3개로 나눠서 처리하자. 찾았다면 free쓰고 return. 이번 위치에서 못찾았으면 한칸 뒤로. 다 돌았는데 못 찾았어? 그럼 그냥 종료.
void delete_value(list *head, list *tail, int value)
{
    list target = *head;
    list prev = NULL; // delete는 이게 필요함 : 선언 및 초기화

    while (target != NULL) // list 비어있지 않은 경우에...
    {
        if (target->data == value) // 지울 위치 찾음. 그 위치가 어디냐는 아래 조건문으로 확인 : 'head라면, tail이라면, middle이라면' 이 3개로 나눔
        {
            if (prev == NULL) // head를 지운다면...
            {
                *head = target->next;
            }
            else // 중간이라면...
            {
                prev->next = target->next; // delete할 node 양 옆의 node 2개를 서로 잇는 과정
            }
            if (target->next == NULL) // tail을 지운다면...
            {
                *tail = prev;
            }
            free(target);
            printf("delete.\n");
            return;
        }
        prev = target;         // prev 저장하고,
        target = target->next; // target 뒤로 한칸
    }
    // 못찾음? 이땐 free(target); 하면 안됨.
    printf("not found.\n");
}

void show_list(list list)
{
    while (list != NULL)
    {
        printf("%d ", list->data);
        list = list->next;
    }
    printf("\n");
}