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

void deleteFirstN(int n)
{
    if (head == NULL)
    {
        printf("List is Empty\n");
        return;
    }
    if (n > length())
    {
        printf("Not Enough Nodes to delete\n");
        return;
    }

    Node *temp = head;

    int count = 1;
    Node *store = NULL;
    while (temp != NULL && count <= n)
    {
        store = head;
        head = head->next;
        free(store);
        count++;
        temp = head;
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
    insertion_at_Beg(29);
    insertion_at_Beg(40);
    insertion_at_Beg(60);
    display();
    deleteFirstN(1);
    printf("\nAfter deleting N Nodes from the beginning\n");
    display();
    return 0;
}