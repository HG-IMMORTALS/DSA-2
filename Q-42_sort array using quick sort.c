#include<stdio.h>

void quicksort(int [],int,int);

int main(){
  int n,i;

  printf("Enter n of the array: ");
  scanf("%d",&n);

  int x[n];

  printf("Enter %d elements: ",n);
  for(i=0;i<n;i++)
    scanf("%d",&x[i]);

  quicksort(x,0,n-1);

  printf("Sorted elements: ");
  for(i=0;i<n;i++)
    printf(" %d",x[i]);

  return 0;
}

void quicksort(int x[],int s,int e){
    int pivot,j,temp,i;

     if(s<e){
         pivot=s;
         i=s;
         j=e;

         while(i<j){
             while(x[i]<=x[pivot]&&i<e)
                 i++;
             while(x[j]>x[pivot])
                 j--;
             if(i<j){
                 temp=x[i];
                  x[i]=x[j];
                  x[j]=temp;
             }
         }

         temp=x[pivot];
         x[pivot]=x[j];
         x[j]=temp;
         quicksort(x,s,j-1);
         quicksort(x,j+1,e);
    }
}
