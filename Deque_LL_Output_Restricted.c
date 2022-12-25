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
void enqueueRear(int x)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Overflow\n");
        return;
    }
    newNode->data = x;
    newNode->next = NULL;
    if (isEmpty())
    {
        front = rear = newNode;
        return;
    }

    rear->next = newNode;
    rear = newNode;
}

void enqueueFront(int x)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Overflow\n");
        return;
    }
    newNode->data = x;
    newNode->next = NULL;
    if (isEmpty())
    {
        front = rear = newNode;
        return;
    }

    newNode->next = front;
    front = newNode;
}

int dequeue()
{
    if (isEmpty())
    {
        printf("Dequeue is empty\n");
        return -1;
    }
    Node *temp = front;
    int val = front->data;

    if (front->next == NULL)
    {
        front = NULL;
        free(temp);
        return val;
    }
    front = front->next;
    free(temp);
    return val;
}

void display()
{
    if (isEmpty())
    {
        printf("Deque is empty \n");
        return;
    }
    Node *temp = front;
    printf("Deque Elements: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    enqueueRear(23);
    enqueueFront(46);
    enqueueFront(97);
    display();
    printf("%d is deleted\n", dequeue());
    display();
    printf("%d is deleted\n", dequeue());
    display();
    return 0;
}