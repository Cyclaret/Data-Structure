#include <stdio.h>
#include <stdlib.h>

typedef struct node_type // linkedList node 정의
{
    int data;
    struct node_type *next;
} node;

typedef node *list; // node들의 객체 선언

list create_node(int data) // node 생성 logic만 떼어낸 함수. insert 함수들이 얘를 갖다쓸 예정
{
    list new_node = (list)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void show_list(list start);
void insert_front(list *head, list *tail, int data);
void insert_back(list *head, list *tail, int data);
void insert_middle(list *head, list *tail, int data, int pos);
void search_value(list head, int target);
void delete_value(list *head, list *tail, int target); // tail 포인터 추가

int main(void)
{
    list head, tail;
    char ch;
    int n;

    head = tail = NULL; // head, tail의 주소 초기화

    printf("Enter Data? (y/n)\n");
    scanf(" %c", &ch);

    while (ch == 'y' || ch == 'Y')
    {
        printf("Give data : \n");
        scanf("%d", &n);

        insert_front(&head, &tail, n);

        printf("More Data?(y/n)\n");
        scanf(" %c", &ch);
    }

    show_list(head);
    // 외에도 밑에 만든 함수들 호출해서 실행해볼 것...
}

void insert_front(list *head, list *tail, int data)
{
    list temp = create_node(data);
    temp->next = *head;
    *head = temp;
    if (*tail == NULL)
        *tail = temp;
}

void insert_back(list *head, list *tail, int data)
{
    list temp = create_node(data);
    if (*head == NULL)
    {
        *head = *tail = temp;
    }
    else
    {
        (*tail)->next = temp;
        *tail = temp;
    }
}

void insert_middle(list *head, list *tail, int data, int pos)
{
    if (pos < 1 || *head == NULL)
    {
        printf("Pos는 1이상이어야 하고, list가 비어있으면 안된다.\n");
        return;
    }

    list temp = create_node(data);
    list current = *head;

    for (int i = 1; i < pos && current != NULL; i++)
    {
        current = current->next;
    }

    if (current == NULL)
    {
        printf("Position out of bounds.\n");
        free(temp);
        return;
    }

    temp->next = current->next;
    current->next = temp;

    if (temp->next == NULL)
    {
        *tail = temp;
    }
}

void show_list(list start)
{
    while (start != NULL)
    {
        printf("%d ", start->data);
        start = start->next;
    }
    printf("\n");
    fflush(stdout); // printf 단점 보완용임. 단순히 모니터에 출력하는 경우 없애도 됨. 파일에 출력하거나 이럴때 쓰는겨.
}

void search_value(list head, int target) // 값 검색 함수 추가
{
    int pos = 1;
    int found = 0;
    while (head != NULL)
    {
        if (head->data == target)
        {
            printf("Value %d found at position %d\n", target, pos);
            found = 1;
            break; // 같은 값이 중복되어 list에 있다면, 그걸 모두 찾고 싶다면 break;를 없애면 다 찾아서 printf함
        }
        head = head->next;
        pos++;
    }
    if (!found)
    {
        printf("Value %d not found in the list.\n", target);
    }
}

void delete_value(list *head, list *tail, int target) // tail 포인터 추가
{
    list current = *head;
    list prev = NULL;

    while (current != NULL)
    {
        if (current->data == target)
        {
            if (prev == NULL) // 아직 prev 아무것도 안 건듦 > head node가 삭제 대상이면...
            {
                *head = current->next; // head 뒤로 하나
            }
            else
            {
                prev->next = current->next; // 지우려는 node 이전 node의 다음이, 지우는 node의 다음 node와 연결 : 그림 그려라
            }

            if (current->next == NULL) // tail을 지우려면...
            {
                *tail = prev; // tail 앞으로 하나
            }

            free(current);
            printf("Value %d deleted from the list.\n", target);
            return;
        }
        prev = current; // 이동 전에 prev 저장하고
        current = current->next; // 한칸 이동
    }
    printf("Value %d not found. Nothing deleted.\n", target); // 앞에서 return; 안걸렸다 : 지우려는게 없다.
}