#include<stdio.h>
int binary(int n,int a[],int key)
{
	int s=0;
	int e=n-1;
	int mid=s+(e-s)/2;
	while(s<=e)
	{
		if(a[mid]==key)
		{
			return mid;
		}
		else if(key>a[mid])
		{
			s=mid+1;
		}
		else
		{
			s=mid-1;
		}
		mid=s+(e-s)/2;
	}
	return -1;
}
int main()
{
	int even[4]={2,4,6,8};
	int odd[4]={1,3,5,7};
	int evenindex=binary(4,even,6);
	printf("index of 6 is %d",evenindex);
	printf("\n");
	int oddindex=binary(4,odd,3);
	printf("index of 3 is %d",oddindex);
	return 0;
}
