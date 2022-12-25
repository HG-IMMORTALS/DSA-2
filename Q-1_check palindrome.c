#include<stdio.h>
int main()
{
  int a[10],i,j,s,n,t;
  printf("\nEnter the element :\n");
  for(i=0;i<10;i++)
  {
  	scanf("%d",&a[i]);
  }
  for(i=0;i<10;i++)
  {
  	n=a[i];
  	s=0;
  	while(n>0)
  	{
  	t=n%10;
  	s=s*10+t;
  	n=n/10;
    }
    if(s==a[i])
    {
    	printf("\n %d is palindrome",a[i]);
	}
  }
return 0;
}

