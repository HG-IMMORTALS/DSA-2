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

int dequeueFront()
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

int dequeueRear()
{
    if (isEmpty())
    {
        printf("Dequeue is empty\n");
        return -1;
    }
    Node *temp = front, *store = rear;
    int val = rear->data;

    if (front->next == NULL)
    {
        front = NULL;
        free(temp);
        return val;
    }
    while (temp->next->next != NULL)
        temp = temp->next;
    rear = temp;
    temp->next = NULL;
    free(store);
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
    enqueue(23);
    enqueue(46);
    enqueue(97);
    display();
    // printf("%d is deleted\n", dequeueFront());
    printf("%d is deleted\n", dequeueRear());
    display();
    printf("%d is deleted\n", dequeueRear());
    // printf("%d is deleted\n", dequeueRear());
    display();
    return 0;
}