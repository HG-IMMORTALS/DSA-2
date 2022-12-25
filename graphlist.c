#include<stdio.h>
#include<stdlib.h>
struct treetype
{
	int source,destination,weight;
	struct treetype*next;
};
struct treetype *head=NULL;
void insert(int s,int d,int wt)
{
	struct treetype *newnode;
	newnode=(struct treetype*)malloc(sizeof(struct treetype));
	newnode->source=s;
	newnode->destination=d;
	newnode->weight=wt;
	newnode->next=NULL;
		if(!head)
		{
			head=newnode;
			newnode->next=NULL;
			return ;
		}
		else
	    {
	    	struct treetype *temp;
	    	temp=head;
	    	while(temp)
	    	{
	    		if(temp->weight==wt)
	    		{
	    			newnode->next=temp->next;
	    			temp->next=newnode;
	    			return ;
				}
				if(temp->weight<wt)
				{
					if(!temp->next)
					{
						temp->next=newnode;
						newnode->next=NULL;
						return;
					}
					if(temp->next->weight>wt)
					{
	                   newnode->next=temp->next;
	                   temp->next=newnode;
	                   return;
	                }
				}
				if(temp->weight>wt)
				{
					if(temp==head)
					{
						newnode->next= temp;
						head=newnode;
						return ;
					}
				}
				temp=temp->next;
		    }
		}
	}
void display()
{
    if(head==NULL)
	{
        printf("\n nothing to display");
        return;
    }
    struct treetype *temp;
    temp=head;
    printf("\nsrc  dest  weight\n");
    while(temp){
        printf("%d\t%d\t%d\n",temp->source,temp->destination,temp->weight);
        temp=temp->next;
    }
}
int main()
{
	insert(3,4,2);
	insert(9,7,4);
	insert(7,8,6);
	insert(5,9,3);
    display();
	return 0;
}

