#include <stdio.h>
#define max 10
int a[11]={10,14,19,26,27,31,33,35,42,44,0};
int b[10];
void merging(int s, int mid, int e) {
   int l1,l2,i;

   for(l1=s,l2=mid +1,i=s;l1<=mid&&l2<=e;i++)
   {
      if(a[l1]<=a[l2])
         b[i]=a[l1++];
      else
         b[i]=a[l2++];
   }
   
   while(l1<=mid)    
      b[i++]=a[l1++];

   while(l2<=e)   
      b[i++]=a[l2++];

   for(i=s;i<=e;i++)
      a[i]=b[i];
}

void sort(int s,int e) {
   int mid;
   
   if(s < e) 
   {
      mid = s+(e-s)/2;
      sort(s,mid);
      sort(mid+1,e);
      merging(s,mid,e);
   } 
   else 
   { 
      return;
   }   
}

int main() { 
   int i;
   printf("List before sorting\n");
   for(i=0;i<=max;i++)
      printf("%d ",a[i]);

   sort(0,max);

   printf("\nList after sorting\n");
   
   for(i=0;i<=max;i++)
      printf("%d ",a[i]);
}
