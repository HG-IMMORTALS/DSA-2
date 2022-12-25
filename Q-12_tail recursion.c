#include<stdio.h>
#include<stdlib.h>
int ans=1;
void tail(int n, int m, int x)
{
	if(m==x)
	return;

	tail(n,m,x+1);
	ans = ans*n;
}
int main()
{
	int n,m;
	printf("Enter number and m\n");
	scanf("%d %d", &n, &m);
	
	tail(n, m, 0);
	printf("\nAnswer: %d\n", ans);
return 0;
}

