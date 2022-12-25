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

int search(int d)
{
    if (head == NULL)
    {
        printf("Empty List\n");
        return -1;
    }
    Node *temp = head;
    int count = 1;
    while (temp != NULL && temp->data != d)
    {
        temp = temp->next;
        count++;
    }
    if (temp == NULL)
        return -1;

    return count;
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
    insertion_at_Beg(15);
    insertion_at_Beg(25);
    display();
    printf("\nElement is at %d position\n", search(15));
    return 0;
}