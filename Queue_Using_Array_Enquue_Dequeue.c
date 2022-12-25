#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int front = 0;
int rear = 0;

int isEmpty()
{
    return front == rear;
}
int isFull()
{
    return rear == MAX;
}
void enqueue(int arr[], int x)
{
    if (isFull())
    {
        printf("\nQueue Is Full");
        return;
    }

    if (front == rear)
    {
        arr[rear] = x;
        rear++;
        return;
    }

    arr[rear] = x;
    rear++;
}

int dequeue(int arr[])
{
    if (isEmpty())
    {
        printf("\nUnderflow\n");
        return -1;
    }
    int val = arr[front];
    front++;
    return val;
}
void display(int arr[])
{
    printf("\n");
    for (int i = front; i < rear; i++)
        printf("%d ", arr[i]);
}
int main()
{
    int queue[10];
    enqueue(queue, 5);
    enqueue(queue, 10);
    display(queue);

    printf("\n%d is deleted", dequeue(queue));
    display(queue);
    return 0;
}