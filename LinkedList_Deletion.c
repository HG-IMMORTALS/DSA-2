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

int isEmpty()
{
    if (head == NULL)
    {
        printf("List Is Empty\n");
        return 1;
    }
    return 0;
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

int deletion_at_Beg()
{
    if (isEmpty())
        return -1;

    Node *temp = head;
    int d;
    if (head->next == NULL)
    {
        temp = head;
        d = temp->data;
        free(temp);
        head = NULL;
        return d;
    }
    d = head->data;
    head = head->next;
    free(temp);
    return d;
}

int deletion_at_Last()
{
    if (isEmpty())
        return -1;

    if (head->next == NULL)
    {
        return deletion_at_Beg();
    }

    Node *temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;
    Node *nodeToDelete = temp->next;
    int val = nodeToDelete->data;
    temp->next = NULL;
    free(nodeToDelete);
    return val;
}

int deletion_at_specific(int pos)
{
    if (isEmpty())
        return -1;

    if (pos == 1)
    {
        return deletion_at_Beg();
    }

    int i = 1;
    Node *temp = head;
    while (i < pos - 1)
    {
        i++;
        temp = temp->next;
    }
    Node *nodeToDelete = temp->next;
    int d = nodeToDelete->data;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
    return d;
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
    insertion_at_Beg(29);
    insertion_at_Beg(40);
    insertion_at_Beg(60);
    display();
    printf("\n%d is deleted\n", deletion_at_Beg());
    display();
    printf("\n%d is deleted\n", deletion_at_Last());
    display();
    printf("\n%d is deleted\n", deletion_at_specific(1));
    display();
    return 0;
}