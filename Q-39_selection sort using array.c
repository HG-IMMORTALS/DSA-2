#include <stdio.h>
int main()
{
    int a[100],n,i,j,temp;
    printf("\n Please Enter the total n of Elements  :  ");
    scanf("%d", &n);
    printf("\n Please Enter the Array Elements  :  ");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    for(i=0;i<n;i++) 
	{
        for(j=i+1;j<n;j++)
		 {
            if(a[i]>a[j]) 
			{
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    printf("\nSelection Sort Result : ");
    for(i=0;i<n;i++) 
	{
        printf("%d\t",a[i]);
    }
    printf("\n");
    return 0;
}

