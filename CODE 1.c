#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head=0;
void create()
{
	struct node *newnode,*temp;
	newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==0)
	{
	printf("out of memory\n");
    }
    printf("enter the data\n");
    scanf("%d",&newnode->data);
    newnode->next=0;
    if(head==0)
	{
		head=newnode;
	}
	else
	{
		temp=head;
		while(temp->next!=0)
		{
			temp=temp->next;
		}
		temp->next=newnode;
	}
    
}
void display()
{
	struct node *temp;
	if(temp==0)
	{
		printf("the list is empty\n");
		return;
	}
	else
	{
		temp=head;
		printf("the list element is:\n");
		while(temp!=0)
		{
			printf("%d \n",temp->data);
			temp=temp->next;
		}
	
	}
}
void insert_begin()
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==0)
	{
	  printf("the list is empty\n");
	  return;
	}
	printf("\nenter the data at the begining\n");
	scanf("%d",&newnode->data);
	newnode->next=0;
	if(head==0)
	{
		head=newnode;
	}
	else
	{
		newnode->next=head;
		head=newnode;
	}
}
void insert_end()
{
	struct node *newnode,*temp;
	newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==0)
	{
		printf("the list is empty\n");
	}
	printf("enter the at end\n");
	scanf("%d",&newnode->data);
	newnode->next=0;
	if(head==0)
	{
		head=newnode;
	}
	else
	{
		temp=head;
		while(temp->next!=0)
		{
			temp=temp->next;
		}
		temp->next=newnode;
	}
}
void insert_pos()
{
	struct node *newnode,*temp;
	int i,pos;
	newnode=(struct node *)malloc(sizeof(struct node));
	if(newnode==0)
	{
		printf("out of memory\n");
		return;
	}

	printf("enter the position\n");
	scanf("%d",&pos);
	printf("enter the element\n");
	scanf("%d",&newnode->data);
	newnode->next=0;
	if(pos==0)
	{
		newnode->next=head;
		head=newnode;
	}
	else
	{
		temp=head;
		for(i=0;i<pos-1;i++)
		{
			temp=temp->next;
			if(temp==0)
			{
				printf("postion not found\n");
				return;
			}
		}
		newnode->next=temp->next;
		temp->next=newnode;
	}
}
int main()
{
	while(1)
	{
	create();
	insert_begin();
	insert_end();
	insert_pos();
	display();
    }
    return 0;
}
