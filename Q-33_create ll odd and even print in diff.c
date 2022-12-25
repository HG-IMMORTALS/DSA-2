#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}s;
s*even=NULL;
s*odd=NULL;
void insertion(s **,s**,int);
void arrange(s*);
void display(s*,s*);
void main()
{
    s *f=NULL;
    s *r=NULL;
    int n,ch;
    do
    {
         printf("\npress 1 to enter node \n2 to display all nodes\n3.arrange\n");
         scanf("%d",&ch);
         switch(ch)
         {
             case 1:
             printf("Enter the number:");
             scanf("%d",&n);
             insertion(&f,&r,n);
             break;
             case 2:
             display(even,odd);
             break;
             case 3:
             arrange(f);
        }
    }while(ch!=4);
    getch();
}
void insertion(s**first,s**last,int n)
{
    s* p=NULL;
    p=((s*)malloc(sizeof(s)));
    p->data=n;
    p->next=NULL;
    if((*last)==NULL)
    {
        (*last)=p;
        (*first)=(*last);
    }
    else
    {
        (*last)->next=p;
        (*last)=(*last)->next;
    }
}
void arrange(s*f)
{
    s*r=NULL;
    s*q=NULL;
    s*g=NULL;
    int t;
    q=f;
    while(q!=NULL)
    {
        t=q->data;
        if((t%2)==0)
        {
             r=(s*)malloc(sizeof(s));
             r->data=t;
             r->next=NULL;
             if(even==NULL)
             {
                 even=r;
             }
             else
             {
                 r->next=even;
                 even=r;
             }
         }
         else
         {
              g=(s*)malloc(sizeof(s));
              g->data=t;
              g->next=NULL;
              if(odd==NULL)
              {
                  odd=r;
              }
              else
              {
                  g->next=odd;
                  odd=g;
              }
         }
         q=q->next;
     }
}
void display(s* even,s* odd)
{
    s*b=NULL;
    s*x=NULL;
    b=even;
    x=odd;
    printf("The output of even link list is: \n");
    while(b!=NULL)
    {
        printf("%d\t",b->data);
        b=b->next;
    }
    printf("\nThe output of odd link list is: \n");
    while(x!=NULL)
    {
        printf("%d\t",x->data);
        x=x->next;
    }
}
