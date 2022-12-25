#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head=0;
void create(int data)
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==0)
	{
		printf("not enough space");
	}
	else
	{
		newnode->data=data;
		if(head==0)
		{
		     newnode->next=0;
			head=newnode;
		}
		else
		{
			newnode->next=head;
			head=newnode;
		}
	}
}
void duplicate()
{
	struct node *temp;
	struct node *p1,*p2;
	p1=head;
	p2=0;
	while(p1!=0&&p1->next!=0)
	{
		p2=p1;
		while(p2->next!=0)
		{
			if(p1->data==p2->next->data)
			{
				temp=p1->next;
				p1->next=p2->next->next;
				free(temp);
			}
			else
			{
					p2=p2->next;
			}
		}
		p1=p1->next;
	}
}
void print()
{
	struct node *temp;
	temp=head;
	while(temp!=0)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
}
int main()
{
	create(2);
	create(2);
	create(66);
	create(2);
	create(88);
	print();
	printf("\n");
	duplicate();
	print();
	return 0;
}
