#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *head = NULL;
Node *tail = NULL;

int length()
{
    if (head == NULL)
    {
        return 0;
    }
    if (head->next == NULL)
        return 1;

    int count = 1;
    Node *temp = head->next;
    while (temp != head)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void insert_Beg(int x)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("No space to allocate\n");
        return;
    }
    newNode->data = x;
    if (head == NULL)
    {
        head = tail = newNode;
        newNode->next = head;
        return;
    }
    newNode->next = head;
    tail->next = newNode;
    head = newNode;
}

void insert_Last(int x)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("No space to allocate\n");
        return;
    }
    newNode->data = x;
    if (head == NULL)
    {
        head = tail = newNode;
        newNode->next = head;
        return;
    }

    tail->next = newNode;
    newNode->next = head;
    tail = newNode;
}
int delete_Beg()
{
    if (head == NULL)
    {
        printf("List is Empty\n");
        return -1;
    }
    Node *temp = head;
    int val = head->data;
    if (head->next == head)
    {
        head = NULL;
        free(temp);
        return val;
    }

    head = head->next;
    free(temp);
    tail->next = head;
    return val;
}

int delete_Last()
{
    if (head == NULL)
    {
        printf("List is Empty\n");
        return -1;
    }
    Node *temp = head;
    int val = head->data;
    if (head->next == head)
    {
        head = NULL;
        free(temp);
        return val;
    }
    val = tail->data;
    Node *store = tail;
    while (temp->next != tail)
        temp = temp->next;
    temp->next = head;
    tail = temp;
    free(store);
    return val;
}

int delete_Specific(int pos)
{
    if (head == NULL)
    {
        printf("\nList is Empty\n");
        return -1;
    }
    if (pos > length())
    {
        printf("\nNo element is at that position\n");
        return -1;
    }
    if (pos == 1)
    {
        return delete_Beg();
    }
    if (pos == length())
        return delete_Last();
    int i = 1;
    Node *temp = head, *store = NULL;
    while (i < pos - 1)
    {
        temp = temp->next;
        i++;
    }
    store = temp->next;
    int val = store->data;
    temp->next = temp->next->next;
    free(store);
    return val;
}

void display()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    Node *temp = head->next;
    printf("%d ", head->data);
    while (temp != head)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    insert_Beg(5);
    insert_Beg(90);
    insert_Beg(25);
    insert_Beg(65);
    insert_Beg(92);
    display();
    printf("\n%d is deleted\n", delete_Beg());
    display();
    // printf("\n%d\n",tail->data);
    printf("\n%d is deleted\n", delete_Last());
    display();
    printf("\n%d is deleted\n", delete_Specific(3));
    display();
}