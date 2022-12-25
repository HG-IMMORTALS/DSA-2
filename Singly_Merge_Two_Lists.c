#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *create(int x)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}
Node *insertion_at_Beg(Node *head, int x)
{
    Node *newNode = create(x);
    if (newNode == NULL)
    {
        printf("Overflow\n");
        return head;
    }
    if (head == NULL)
        head = newNode;
    else
    {
        newNode->next = head;
        head = newNode;
    }
}

Node *merge(Node *list1, Node *list2)
{
    if (list1 == NULL && list2 == NULL)
    {
        printf("Both lists are empty\n");
        return list1;
    }

    if (list1 == NULL && list2 != NULL)
        return list2;

    if (list1 != NULL && list2 == NULL)
        return list1;

    Node *temp = list1;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = list2;
    return list1;
}

void display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    Node *head = NULL, *head2 = NULL;
    head = insertion_at_Beg(head, 5);
    head = insertion_at_Beg(head, 10);
    head = insertion_at_Beg(head, 15);
    head = insertion_at_Beg(head, 25);
    display(head);

    printf("\nSecond List \n");
    head2 = insertion_at_Beg(head2, 90);
    head2 = insertion_at_Beg(head2, 80);
    head2 = insertion_at_Beg(head2, 75);
    head2 = insertion_at_Beg(head2, 65);
    display(head2);

    printf("\nMerged List\n");
    head = merge(head, head2);
    display(head);
    return 0;
}