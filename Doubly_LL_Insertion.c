#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

Node *head = NULL;

Node *create(int x)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Overflow\n");
        return newNode;
    }
    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

int length()
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
void insert_Beg_Doubly(int x)
{
    Node *newNode = create(x);
    if (newNode == NULL)
    {
        printf("Overflow\n");
        return;
    }

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void insert_Last_Doubly(int x)
{
    Node *newNode = create(x);
    if (newNode == NULL)
    {
        printf("Overflow\n");
        return;
    }

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
     newNode->next = NULL;
}

void insert_specific_Doubly(int pos, int x)
{
    Node *newNode = create(x);
    if (newNode == NULL)
    {
        printf("Overflow\n");
        return;
    }

    if (head == NULL)
    {
        head = newNode;
        return;
    }
    if (pos == 1)
    {
        insert_Beg_Doubly(x);
        return;
    }
    if (pos == length() + 1)
    {
        insert_Last_Doubly(x);
        return;
    }

    Node *temp = head;
    int i = 1;
    while (i < pos - 1)
    {
        temp = temp->next;
        i++;
    }
    temp->next->prev = newNode;
    newNode->next = temp->next;
    newNode->prev = temp;
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
    insert_Beg_Doubly(5);
    insert_Beg_Doubly(10);
    insert_Beg_Doubly(15);
//     display();
    insert_Last_Doubly(100);
    insert_Last_Doubly(200);
    display();
    printf("\n Length is %d\n", length());
//     insert_specific_Doubly(6, 2);
    display();
    return 0;
}
