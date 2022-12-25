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

void deleteOddPos()
{
    if (head == NULL)
    {
        printf("Empty List\n");
        return;
    }
    Node *store = head;
    if (head->next == NULL)
    {
        free(store);
        head = NULL;
        return;
    }

    head = head->next;
    free(store);
    Node *temp = head;
    while (temp != NULL && temp->next != NULL)
    {
        store = temp->next;
        temp->next = temp->next->next;
        free(store);
        temp = temp->next;
    }
}

void deleteEvenPos()
{
    if (head == NULL)
    {
        printf("Empty List\n");
        return;
    }
    Node *temp = head, *store = NULL;
    while (temp != NULL && temp->next != NULL)
    {
        store = temp->next;
        temp->next = store->next;
        free(store);
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
    insertion_at_Beg(16);
    insertion_at_Beg(12);
    insertion_at_Beg(22);

    display();
    // deleteOddPos();
    // printf("\nAfter Deleting Odd Positions\n");
    // display();
    deleteEvenPos();
    printf("\nAfter Deleting Even Positions\n");
    display();
    return 0;
}