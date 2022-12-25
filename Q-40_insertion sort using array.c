#include<stdio.h>
int main()
{
    int n,a[1000],c,d,temp;
    printf("Enter number of elements : ");
    scanf("%d",&n);    
    printf("Enter %d integers\n", n);
    
    for (c=0;c<n;c++) 
	{    
        scanf("%d", &a[c]);    
    }
    for (c=1;c<=n-1;c++) {    
        d=c;        
        while (d>0&&a[d]<a[d-1]) {        
            temp=a[d];
            a[d]=a[d-1];
            a[d-1]=temp;        
            d--;        
        }        
    }
    
    printf("Sorted list in ascending order:\t");
    
    for (c=0;c<=n-1;c++)
	{    
         printf("%d ",a[c]);    
    }
    
    return 0;
}
