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
    if (isEmpty())
    {
        front = rear = newNode;
        rear->next = front;
        return;
    }

    rear->next = newNode;
    rear = newNode;
    rear->next = front;
}

int dequeue()
{
    if (isEmpty())
    {
        printf("Circular Queue is Empty\n");
        return -1;
    }

    Node *temp = front;
    int val = front->data;
    if (front->next == front)
    {
        front = NULL;
        free(temp);
        return val;
    }

    front = front->next;
    rear->next = front;
    free(temp);
    return val;
}
void display()
{
    if (isEmpty())
    {
        printf("Circular Queue is Empty\n");
        return;
    }
    printf("Elements present are: ");
    printf("%d ", front->data);
    Node *temp = front->next;
    while (temp != front)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    enqueue(5);
    enqueue(10);
    enqueue(15);
    display();
    printf("%d is deletd\n", dequeue());
    display();
    printf("%d is deletd\n", dequeue());
    display();
    printf("%d is deletd\n", dequeue());
    display();
    return 0;
}