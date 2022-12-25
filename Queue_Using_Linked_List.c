#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *front = NULL;
Node *rear = NULL;

int isEmpty()
{
    return front == NULL;
}
void enqueue(int x)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("No space to allocate memory\n");
        return;
    }

    newNode->data = x;
    newNode->next = NULL;

    if (isEmpty())
    {
        front = newNode;
        rear = newNode;
        return;
    }

    rear->next = newNode;
    rear = newNode;
}

int dequeue()
{
    if (isEmpty())
    {
        printf("\nUnderflow\n");
        return -1;
    }

    Node *temp = front;
    int val = front->data;
    front = front->next;
    free(temp);
    return val;
}
void display()
{
    printf("\n");
    Node *temp = front;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
int main()
{
    enqueue(3);
    enqueue(75);
    enqueue(30);
    enqueue(44);
    display();

    printf("\n%d is deleted", dequeue());
    printf("\n%d is deleted", dequeue());
    display();
    return 0;
}