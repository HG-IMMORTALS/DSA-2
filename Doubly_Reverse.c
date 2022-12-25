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

void display()
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
void reverse()
{
    if (head == NULL)
    {
        printf("List Is Empty\n");
        return;
    }
    if (head->next == NULL)
    {
        return;
    }

    Node *start = head;
    Node *temp = NULL;
    while (start != NULL)
    {
        temp = start->next;
        start->next = start->prev;
        start->prev = temp;
        start = temp;
        if (start != NULL && start->next == NULL)
            head = start;
    }
}

int main()
{
    insert_Beg_Doubly(5);
    insert_Beg_Doubly(10);
    // insert_Beg_Doubly(15);
    display();
    reverse();
    printf("\n Reversed List \n");
    display();
    return 0;
}