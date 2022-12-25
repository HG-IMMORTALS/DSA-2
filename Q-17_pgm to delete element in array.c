#include <stdio.h>
#include <conio.h> 
int main(){
    int a[500],n,i,index;
     
    printf("Enter number of elements in array: ");
    scanf("%d",&n);
    printf("Enter %d numbers \n",n);
     
    for(i=0;i<n;i++)
	{
        scanf("%d",&a[i]);
    }
     
    printf("Enter index from where you want to delete an element\n");
    scanf("%d",&index);
     
    for(i=index;i<n-1;i++){
        a[i]=a[i+1];
    } 
    printf("Updated Array\n");
    for(i = 0;i<n-1;i++)
	{
        printf("%d ",a[i]);
    }
    return 0;
}
