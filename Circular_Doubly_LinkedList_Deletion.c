#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
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

void insert_DCircular_Beg(int x)
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
        newNode->prev = head;
        return;
    }
    newNode->next = head;
    tail->next = newNode;
    head->prev = newNode;
    newNode->prev = head;
    head = newNode;
}

int delete_DCircularBeg()
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
    head->prev = tail;
    free(temp);
    tail->next = head;
    return val;
}

int delete_DCircularLast()
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
    head->prev = tail;
    free(store);
    return val;
}

int delete_DCircularSpecific(int pos)
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
        return delete_DCircularBeg();
    }
    if (pos == length())
        return delete_DCircularLast();
    int i = 1;
    Node *temp = head, *store = NULL;
    while (i < pos - 1)
    {
        temp = temp->next;
        i++;
    }
    store = temp->next;
    int val = store->data;
    temp->next = temp->next->next; // temp->next->next = store->next
    store->next->prev = temp;
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

void displayPrev()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("\n");
    Node *temp = tail;
    while (temp != head)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("%d ", temp->data);
    printf("\n");
}
int main()
{
    insert_DCircular_Beg(5);
    insert_DCircular_Beg(90);
    insert_DCircular_Beg(25);
    insert_DCircular_Beg(65);
    insert_DCircular_Beg(92);
    display();
    printf("\n%d is deleted\n", delete_DCircularBeg());
    display();
    // printf("\n%d is deleted\n", delete_DCircularBeg());
    // display();
    // displayPrev();
    // printf("\n%d\n",tail->data);
    // printf("\n%d is deleted\n", delete_DCircularLast());
    // display();
    // displayPrev();
    printf("\n%d is deleted\n", delete_DCircularLast());
    display();
    displayPrev();
    // printf("\n%d is deleted\n", delete_DCircularSpecific(3));
    // display();
    // displayPrev();
    printf("\n%d is deleted\n", delete_DCircularSpecific(2));
    display();
    displayPrev();
}