#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int front = -1;
int rear = -1;
int deque[MAX];

int isEmpty()
{
    return front == rear;
}
int isFull()
{
    return rear == MAX - 1;
}
void enqueue_Rear(int x)
{
    if (isFull())
    {
        printf("Deque is Full\n");
        return;
    }
    if (isEmpty())
    {
        front = rear = 0;
        deque[rear] = x;
        rear++;
        return;
    }

    deque[rear] = x;
    rear++;
}

void enqueue_Front(int x)
{
    if (isFull())
    {
        printf("Deque is Full\n");
        return;
    }

    if (isEmpty())
    {
        front = rear = 0;
        deque[rear] = x;
        rear++;
        return;
    }

    front--;
    deque[front] = x;
}

int dequeue()
{
    if (isEmpty())
    {
        printf("Deque is empty\n");
        return -1;
    }
    int val = deque[front];
    front++;
    return val;
}

void display()
{
    if (isEmpty())
    {
        printf("Deque is empty\n");
        return;
    }
    printf("Deque elements are : ");
    for (int i = front; i < rear; i++)
        printf("%d ", deque[i]);
    printf("\n");
}
int main()
{
    enqueue_Rear(12);
    enqueue_Rear(32);
    enqueue_Front(48);
    enqueue_Rear(97);
    enqueue_Front(943);
    display();
    printf("%d is deleted\n", dequeue());
    display();
}