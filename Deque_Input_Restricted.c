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
void enqueue(int x)
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

int dequeue_Front()
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

int dequeue_Rear()
{
    if (isEmpty())
    {
        printf("Deque is empty\n");
        return -1;
    }
    int val = deque[rear - 1];
    rear--;
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
    enqueue(50);
    enqueue(200);
    enqueue(300);
    enqueue(893);
    enqueue(634);
    display();
    printf("%d is deleted\n", dequeue_Front());
    display();
    printf("%d is deleted\n", dequeue_Rear());
    display();
    printf("%d is deleted\n", dequeue_Front());
    display();
    printf("%d is deleted\n", dequeue_Rear());
    display();
}