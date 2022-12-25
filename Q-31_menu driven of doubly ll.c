#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *prev, *next;
};
struct node* start = NULL;
 
void traverse(){
   
    if (start == NULL) {
        printf("\nList is empty\n");
        return;
    }

    struct node* temp;
    temp = start;
    while (temp != NULL) {
        printf("Data = %d\n", temp->data);
        temp = temp->next;
    }
}
 
void insertAtFront(){
    int data;
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter number to be inserted: ");
    scanf("%d", &data);
    temp->data = data;
    temp->prev = NULL;
    temp->next = start;
    start = temp;
}
 
void insertAtEnd(){
    int data;
    struct node *temp, *trav;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->next = NULL;
    printf("\nEnter number to be inserted: ");
    scanf("%d", &data);
    temp->data = data;
    temp->next = NULL;
    trav = start;

    if (start == NULL) {
 
        start = temp;
    }

    else {
        while (trav->next != NULL)
            trav = trav->next;
        temp->prev = trav;
        trav->next = temp;
    }
}

void insertAtPosition(){
    int data, pos, i = 1;
    struct node *temp, *newnode;
    newnode = malloc(sizeof(struct node));
    newnode->next = NULL;
    newnode->prev = NULL;

    printf("\nEnter position : ");
    scanf("%d", &pos);
    printf("\nEnter number to be inserted: ");
    scanf("%d", &data);
    newnode->data = data;
    temp = start;
 
    if (start == NULL) {
        start = newnode;
        newnode->prev = NULL;
        newnode->next = NULL;
    }
 
    else if (pos == 1) {
        newnode->next = start;
        newnode->next->prev = newnode;
        newnode->prev = NULL;
        start = newnode;
    }

    else {
        while (i < pos - 1) {
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        newnode->prev = temp;
        temp->next = newnode;
        temp->next->prev = newnode;
    }
}

void deleteFirst(){
    struct node* temp;
    if (start == NULL)
        printf("\nList is empty\n");
    else {
        temp = start;
        start = start->next;
        if (start != NULL)
            start->prev = NULL;
        free(temp);
    }
}

void deleteEnd(){
    struct node* temp;
    if (start == NULL)
        printf("\nList is empty\n");
    temp = start;
    while (temp->next != NULL)
        temp = temp->next;
    if (start->next == NULL)
        start = NULL;
    else {
        temp->prev->next = NULL;
        free(temp);
    }
}

void deletePosition(){
    int pos, i = 1;
    struct node *temp, *position;
    temp = start;

    if (start == NULL)
        printf("\nList is empty\n");
    else {
        printf("\nEnter position : ");
        scanf("%d", &pos);
 
        if (pos == 1) {
            position = start;
            start = start->next;
            if (start != NULL) {
                start->prev = NULL;
            }
            free(position);
            return;
        }

        while (i < pos - 1) 
		{
            temp = temp->next;
            i++;
        }
        position = temp->next;
        if (position->next != NULL)
            position->next->prev = temp;
        temp->next = position->next;
        free(position);
    }
}
 
int main(){
    int choice;
    while (1) {
 
        printf("1.To see list\n");
        printf("2.For insertion at"
            " starting\n");
        printf("3.For insertion at"
            " end\n");
        printf("4.For insertion at "
            "any position\n");
        printf("5.For deletion of "
            "first element\n");
        printf("6.For deletion of "
            "last element\n");
        printf("7.For deletion of "
            "element at any position\n");
        printf("8.To exit\n");
        printf("\nEnter Choice :\n");
        scanf("%d", &choice);
 
        switch (choice) {
        case 1:
            traverse();
            break;
        case 2:
            insertAtFront();
            break;
        case 3:
            insertAtEnd();
            break;
        case 4:
            insertAtPosition();
            break;
        case 5:
            deleteFirst();
            break;
        case 6:
            deleteEnd();
            break;
        case 7:
            deletePosition();
            break;
 
        case 8:
            exit(1);
            break;
        default:
            printf("Incorrect Choice. Try Again \n");
            continue;
        }
    }
    return 0;
}

