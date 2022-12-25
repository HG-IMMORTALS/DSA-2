#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

Node *head = NULL;

Node *create(int x)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Overflow\n");
        return newNode;
    }
    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
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
void insert_Beg_Doubly(int x)
{
    Node *newNode = create(x);
    if (newNode == NULL)
    {
        printf("Overflow\n");
        return;
    }

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

int deletion_Beg_Doubly()
{
    if (head == NULL)
    {
        printf("Underflow\n");
        return -1;
    }
    int val;
    Node *temp = head;
    if (head->next == NULL)
    {
        temp = head;
        val = head->data;
        free(temp);
        head = NULL;
        return val;
    }
    val = temp->data;
    head = head->next;
    free(temp);
    return val;
}

int deletion_Last_Doubly()
{
    if (head == NULL)
    {
        printf("Underflow\n");
        return -1;
    }
    int val;
    Node *temp = head;
    if (head->next == NULL)
    {
        temp = head;
        val = head->data;
        free(temp);
        head = NULL;
        return val;
    }
    while (temp->next->next != NULL)
        temp = temp->next;
    Node *store = temp->next;
    val = temp->next->data;
    temp->next = NULL;
    store->prev = NULL;
    free(store);
    return val;
}

int deletion_Specific_Doubly(int pos)
{
    if (head == NULL)
    {
        printf("Underflow\n");
        return -1;
    }
    if (pos > length())
        return -1;

    if (pos == 1)
    {
        return deletion_Beg_Doubly();
    }

    if (pos == length())
    {
        return deletion_Last_Doubly();
    }
    int i = 1;
    Node *temp = head;
    while (i < pos - 1)
    {
        temp = temp->next;
        i++;
    }
    Node *store = temp->next;
    Node *forward = temp->next->next;
    int val = store->data;
    temp->next = forward;
    forward->prev = temp;
    store->next = store->prev = NULL;
    free(store);
    return val;
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
    insert_Beg_Doubly(5);
    insert_Beg_Doubly(10);
    insert_Beg_Doubly(40);
    insert_Beg_Doubly(15);
    insert_Beg_Doubly(30);
    display();
    printf("\n%d is deleted\n", deletion_Beg_Doubly());
    display();
    printf("\n%d is deleted\n", deletion_Last_Doubly());
    display();
    printf("\n%d is deleted\n", deletion_Specific_Doubly(2));
    display();
    return 0;
}