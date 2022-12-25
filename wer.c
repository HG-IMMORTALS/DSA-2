#include<stdio.h>
#include<stdlib.h>
int s1[100],s2[100];
int top1=-1,top2=-1;
int count=-1;
void create()
{
	top1=top2=-1;
}
void push1(int data)
{
	s1[++top1]=data;
}
int pop1()
{
	return(s1[top1--]);
}
void push2(int data)
{
	s2[++top2]=data;
}
int pop2()
{
	return(s2[top2--]);
}
void enqueue()
{
	int data;
	printf("enter the data");
	scanf("%d",&data);
	count++;
}
void dequeue()
{
	int i;
	for(i=0;i<=count;i++)
		push2(pop1());
	pop2();
	count--;
	for(i=0;i<=count;i++)
	    push1(pop2());
	pop1();
}
void display()
{
	int i;
	for(i=0;i<=top1;i++)
	{
	   printf("%d",s1[i]);	
	}
}
int main()
{
 int ch;
 
    printf("\n1 - Enqueue element into queue");
    printf("\n2 - Dequeu element from queue");
    printf("\n3 - Display from queue");
    printf("\n4 - Exit");
    create();
    while (1)
    {
        printf("\nEnter choice");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Wrong choice");
        }
    } 
 return 0;
}

