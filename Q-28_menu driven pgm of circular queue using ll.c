#include<stdio.h>
#include<stdlib.h>

struct node
{
        int data;
        struct node *next;
}*rear=NULL;

void insert(int item);
int del();
void display();
int isEmpty();
int peek();

int main()
{
        int choice,item;
        while(1)
        {
                printf("1.Insert\n");
                printf("2.Delete\n");
                printf("3.Peek\n");
                printf("4.Display\n");
                printf("5.Quit\n");
                printf("\nEnter your choice : ");
                scanf("%d",&choice);

                switch(choice)
                {
                 case 1:
                        printf("\nEnter the element for insertion : ");
                        scanf("%d",&item);
                        insert(item);
                        break;
                 case 2:
                        printf("\nDeleted element is %d\n",del());
                        break;
                 case 3:
                        printf("\nItem at the front of queue is %d\n",peek());
                        break;
                 case 4:
                        display();
                        break;
                 case 5:
                        exit(1);
                 default:
                        printf("\nWrong choice\n");
                }
        }
}

void insert(int item)
{
        struct node *temp;
        temp=(struct node *)malloc(sizeof(struct node));
        temp->data=item;
        if(temp==NULL)
        {
                printf("\nMemory not available\n");
                return;
        }

        if( isEmpty() ) 
        {
                rear=temp;
                temp->next=rear;
        }
        else
        {
                temp->next=rear->next;
                rear->next=temp;
                rear=temp;
        }
}

del()
{
        int item;
        struct node *temp;
        if( isEmpty() )
        {
                printf("\nQueue underflow\n");
                exit(1);
        }
        if(rear->next==rear) 
        {
                temp=rear;
                rear=NULL;
        }
        else
        {
                temp=rear->next;
                rear->next=rear->next->next;
        }
        item=temp->data;
        free(temp);
        return item;
}

int peek()
{
        if( isEmpty() )
        {
                printf("\nQueue underflow\n");
                exit(1);
        }
        return rear->next->data;
}

int isEmpty()
{
        if( rear == NULL )
                return 1;
        else
                return 0;
}

void display()
{
        struct node *p;
        if(isEmpty())
        {
                printf("\nQueue is empty\n");
                return;
        }
        printf("\nQueue is :\n");
        p=rear->next;
        do
        {
                printf("%d ",p->data);
                p=p->next;
        }while(p!=rear->next);
        printf("\n");
}
