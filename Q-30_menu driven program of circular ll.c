#include<stdio.h>
#include<stdlib.h>

struct node
{
        int data;
        struct node *next;
};

struct node *create_list(struct node *last);
void display(struct node *last);
struct node *addtoempty(struct node *last,int data);
struct node *addatbeg(struct node *last,int data);
struct node *addatend(struct node *last,int data);
struct node *addafter(struct node *last,int data,int item);
struct node *del(struct node *last,int data);

int main( )
{
        int choice,data,item;
        struct node *last=NULL;

        while(1)
        {
                printf("1.Create List\n");
                printf("2.Display\n");
                printf("3.Add to empty list\n");
                printf("4.Add at beginning\n");
                printf("5.Add at end\n");
                printf("6.Add after \n");
                printf("7.Delete\n");
                printf("8.Quit\n");

                printf("\nEnter your choice : ");
                scanf("%d",&choice);

                switch(choice)
                {
                 case 1:
                        last=create_list(last);
                        break;
                 case 2:
                        display(last);
                        break;
                 case 3:
                        printf("\nEnter the element to be inserted : ");
                        scanf("%d",&data);
                        last=addtoempty(last,data);
                        break;
                 case 4:
                        printf("\nEnter the element to be inserted : ");
                        scanf("%d",&data);
                        last=addatbeg(last,data);
                        break;
                 case 5:
                        printf("\nEnter the element to be inserted : ");
                        scanf("%d",&data);
                        last=addatend(last,data);
                        break;
                 case 6:
                        printf("\nEnter the element to be inserted : ");
                        scanf("%d",&data);
                        printf("\nEnter the element after which to insert : ");
                        scanf("%d",&item);
                        last=addafter(last,data,item);
                        break;
                 case 7:
                        printf("\nEnter the element to be deleted : ");
                        scanf("%d",&data);
                        last=del(last,data);
                        break;
                 case 8:
                        exit(1);
                 default:
                        printf("\nWrong choice\n");
                }
        }

        return 0;

}

struct node *create_list(struct node *last)
{
        int i,n,data;
        printf("\nEnter the number of nodes : ");
        scanf("%d",&n);
        last=NULL;
        if(n==0)
                return last;
        printf("Enter the element to be inserted : ");
        scanf("%d",&data);
        last=addtoempty(last,data);

        for(i=2;i<=n;i++)
        {
                printf("Enter the element to be inserted : ");
                scanf("%d",&data);
                last=addatend(last,data);
        }
        return last;
}

struct node *addtoempty(struct node *last,int data)
{
        struct node *tmp;
        tmp=(struct node *)malloc(sizeof(struct node));
        tmp->data=data;
        last=tmp;
        last->next=last;
        return last;
}

struct node *addatbeg(struct node *last,int data)
{
        struct node *tmp;
        tmp=(struct node *)malloc(sizeof(struct node));
        tmp->data=data;
        tmp->next=last->next;
        last->next=tmp;
        return last;
}

struct node *addatend(struct node *last,int data)
{
        struct node *tmp;
        tmp=(struct node *)malloc(sizeof(struct node));
        tmp->data=data;
        tmp->next=last->next;
        last->next=tmp;
        last=tmp;
        return last;
}

struct node *addafter(struct node *last,int data,int item)
{
        struct node *tmp,*p;
        p=last->next;
        do
        {
                if(p->data==item)
                {
                        tmp=(struct node *)malloc(sizeof(struct node));
                        tmp->data=data;
                        tmp->next=p->next;
                        p->next=tmp;
                        if(p==last)
                                last=tmp;
                        return last;
                }
                p=p->next;
        }while(p!=last->next);
        printf("%d not present in the list\n",item);
        return last;
}

struct node *del(struct node *last,int data)
{
        struct node *tmp,*p;
        if(last==NULL)
        {
                printf("List is empty\n");
                return last;
        }
    
        if(last->next==last && last->data==data)
        {
                tmp=last;
                last=NULL;
                free(tmp);
                return last;
        }
    
        if(last->next->data==data)
        {
                tmp=last->next;
                last->next=tmp->next;
                free(tmp);
                return last;
        }
       
        p=last->next;
        while(p->next!=last)
        {
                if(p->next->data==data)
                {
                        tmp=p->next;
                        p->next=tmp->next;
                        free(tmp);
                        return last;
                }
                p=p->next;
        }
      
        if(last->data==data)
        {
                tmp=last;
                p->next=last->next;
                last=p;
                free(tmp);
                return last;
        }
        printf("\nElement %d not found\n",data);
        return last;
}

void display(struct node *last)
{
        struct node *p;
        if(last==NULL)
        {
                printf("\nList is empty\n");
                return;
        }
        p=last->next;
        do
        {
                printf("%d ",p->data);
                p=p->next;
        }while(p!=last->next);
        printf("\n");
}
