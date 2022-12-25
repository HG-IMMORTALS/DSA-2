#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int cqueue[5];
int front = -1;
int rear = -1;

int isFull()
{
    if ((front == 0 && rear == MAX - 1) || (rear + 1 == front))
        return 1;
    return 0;
}

int isEmpty()
{
    return front == -1;
}

void enqueue(int x)
{
    if (isFull())
    {
        printf("Queue is Full\n");
        return;
    }
    if (isEmpty())
    {
        front = 0;
    }
    rear = (rear + 1) % MAX;
    cqueue[rear] = x;
}

int dequeue()
{
    if (isEmpty())
    {
        printf("UNDERFLOW\n");
        exit(1);
    }
    else
    {
        int val = cqueue[front];
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % MAX;
        }
        return val;
    }
}
void display()
{
    if (isEmpty())
    {
        printf("Empty Queue\n");
        return;
    }
    int i;
    for (i = front; i != rear; i = (i + 1) % MAX)
        printf("%d ", cqueue[i]);
    printf("%d\n", cqueue[i]);
}
int main()
{
    enqueue(3);
    enqueue(6);
    enqueue(9);
    enqueue(15);
    enqueue(31);
    enqueue(97);
    printf("\nFront : %d\n", cqueue[front]);
    printf("Rear : %d\n", cqueue[rear]);
    display();

    printf("%d is deleted\n", dequeue());
    printf("%d is deleted\n", dequeue());
    printf("%d is deleted\n", dequeue());
    printf("%d is deleted\n", dequeue());
    printf("%d is deleted\n", dequeue());
    display();
    return 0;
}