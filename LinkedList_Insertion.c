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

void insertion_at_specific_Position(int pos, int x)
{
    Node *newNode = create(x);
    if (newNode == NULL)
    {
        printf("Overflow\n");
        return;
    }

    if (head == NULL || pos == 1)
    {
        insertion_at_Beg(x);
        return;
    }
    int i = 1;

    Node *temp = head;
    while (i < pos - 1)
    {
        i++;
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
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

    insertion_at_Last(30);

    insertion_at_specific_Position(4, 7);
    insertion_at_specific_Position(2, 80);
    display();
    return 0;
}