#include <stdio.h>
int main()
{
	int bin[100],n,i,j;
	printf("enter the n");
	scanf("%d",&n);
	i=0;
	while(n>0)
	{
		bin[i]=n%2;
		n=n/2;
		i++;
	}
	for(j=i-1;j>=0;j--)
	{
		printf("%d",bin[j]);
	}
}
