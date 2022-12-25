#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *head = NULL;
Node *tail = NULL;

int length()
{
    if (head == NULL)
    {
        return 0;
    }
    if (head->next == NULL)
        return 1;

    int count = 1;
    Node *temp = head->next;
    while (temp != head)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void insert_Beg(int x)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("No space to allocate\n");
        return;
    }
    newNode->data = x;
    if (head == NULL)
    {
        head = tail = newNode;
        newNode->next = head;
        return;
    }
    newNode->next = head;
    tail->next = newNode;
    head = newNode;
}

void insert_Last(int x)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("No space to allocate\n");
        return;
    }
    newNode->data = x;
    if (head == NULL)
    {
        head = tail = newNode;
        newNode->next = head;
        return;
    }

    tail->next = newNode;
    newNode->next = head;
    tail = newNode;
}

void insert_Specific(int pos, int x)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("No space to allocate\n");
        return;
    }
    newNode->data = x;
    if (pos == 1)
    {
        insert_Beg(x);
        return;
    }
    if (pos == length() + 1)
    {
        insert_Last(x);
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
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    Node *temp = head->next;
    printf("%d ", head->data);
    while (temp != head)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
int main()
{
    insert_Beg(5);
    insert_Beg(15);
    insert_Beg(25);

    insert_Last(30);
    insert_Last(40);
    insert_Beg(255);
    insert_Specific(7, 89);
    printf("Length is %d \n", length());
    display();
}