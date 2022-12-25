#include <stdio.h>
#include <stdlib.h>

struct treetype{
    int source,destination,weight;
    struct treetype *next;
};
struct treetype *start=NULL;
void insert(int source,int destination,int weight){
    struct treetype *newnode;
    newnode=(struct treetype*)malloc(sizeof(struct treetype));
    if(newnode==NULL){
        printf("Memory overflow");
        return;
    }
    newnode->source=source;
    newnode->destination=destination;
    newnode->weight=weight;
    if(start==NULL){
        start=newnode;
        newnode->next=NULL;
        return;
    }
    else{
        struct treetype *temp;
        temp=start;
        while(temp!=NULL){
           if(temp->weight==weight){
               newnode->next=temp->next;
               temp->next=newnode;
               return;
           }
           if(temp->weight<weight){
               if(temp->next==NULL){
                   temp->next=newnode;
                   newnode->next=NULL;
                   return;
               }
               if(temp->next->weight>weight){
                   newnode->next=temp->next;
                   temp->next=newnode;
                   return;
               }
           }
           if(temp->weight>weight){
               if(temp==start){
                   newnode->next=temp;
                   start=newnode;
                   return;
               }
           } 
           temp=temp->next;
        }
    }
}
void display(){
    if(start==NULL){
        printf("\n nothing to display");
        return;
    }
    struct treetype *temp;
    temp=start;
    printf("\nsrc  dest  weight\n");
    while(temp!=NULL){
        printf("%d->%d->%d\n",temp->source,temp->destination,temp->weight);
        temp=temp->next;
    }
}

int main() {
    int src,dest,wt,choice;
    while(1){
        printf("enter 1 to insert\n");
        printf("enter 2 to display\n");
        printf("enter 3 to exit\n");
        printf("enter choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
              printf("enter source: ");
              scanf("%d",&src);
              printf("enter dest: ");
              scanf("%d",&dest);
              printf("enter weight: ");
              scanf("%d",&wt);
              insert(src,dest,wt);
              break;
            case 2: 
              display();
              break;
            case 3:
              exit(0);
              break;
            default:
              break;
        }
    }
    return 0;
}
