#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
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

void insert_Beg_DCircular(int x)
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
        newNode->prev = head;
        return;
    }
    newNode->next = head;
    tail->next = newNode;
    head->prev = newNode;
    newNode->prev = head;
    head = newNode;
}

void insert_Last_DCircular(int x)
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
        newNode->prev = head;
        return;
    }
    newNode->prev = tail;
    tail->next = newNode;
    newNode->next = head;
    tail = newNode;
    head->prev = tail;
}

void insert_Specific_DCircular(int pos, int x)
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
        insert_Beg_DCircular(x);
        return;
    }
    if (pos == length() + 1)
    {
        insert_Last_DCircular(x);
        return;
    }
    int i = 1;
    Node *temp = head;
    while (i < pos - 1)
    {
        i++;
        temp = temp->next;
    }
    newNode->prev = temp;
    newNode->next = temp->next;
    temp->next = newNode;
    newNode->next->prev = newNode;
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
    printf("\n");
}

void displayPrev()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    Node *temp = tail;
    while (temp != head)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("%d ", temp->data);
    printf("\n");
}
int main()
{
    insert_Beg_DCircular(5);
    insert_Beg_DCircular(15);
    insert_Beg_DCircular(25);

    // insert_Last_DCircular(30);
    // insert_Last_DCircular(40);
    // insert_Last_DCircular(255);
    // insert_Specific_DCircular(1, 2);
    // insert_Specific_DCircular(2, 54);
    // insert_Specific_DCircular(3, 90);
    // insert_Specific_DCircular(2, 39);
    // printf("Length is %d \n", length());
    display();
    displayPrev();
}