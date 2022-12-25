#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;
Node *head = NULL;

Node *create(int x)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}
void insertion_at_Beg(int x)
{
    Node *newNode = create(x);
    if (newNode == NULL)
    {
        printf("Overflow\n");
        return;
    }
    if (head == NULL)
        head = newNode;
    else
    {
        newNode->next = head;
        head = newNode;
    }
}

void insertion_at_Last(int x)
{
    Node *newNode = create(x);
    if (newNode == NULL)
    {
        printf("Overflow\n");
        return;
    }
    if (head == NULL)
    {
        insertion_at_Beg(x);
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void oddList()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    int count = 1;
    Node *temp = head;
    while (temp != NULL)
    {
        if (count % 2 != 0)
            printf("%d ", temp->data);
        count++;
        temp = temp->next;
    }
}

void evenList()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    int count = 1;
    Node *temp = head;
    while (temp != NULL)
    {
        if (count % 2 == 0)
            printf("%d ", temp->data);
        count++;
        temp = temp->next;
    }
}

void display()
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
    insertion_at_Beg(5);
    insertion_at_Beg(10);
    insertion_at_Beg(23);
    insertion_at_Beg(54);
    insertion_at_Beg(10);
    insertion_at_Beg(12);
    display();
    printf("\n Odd List \n");
    oddList();
    printf("\n Even List \n");
    evenList();
    return 0;
}