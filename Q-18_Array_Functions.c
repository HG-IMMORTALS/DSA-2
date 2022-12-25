#include<stdio.h>
#include<stdlib.h>

void input(int arr[], int n)
{
	int i;
	for(i=0; i<n;i++)
		scanf("%d", &arr[i]);
}

void output(int arr[], int n)
{
	int i;
	for(i=0; i<n;i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void sortAscending(int arr[], int n)
{
	int i,j;
	printf("Sort in ascending\n");
	for(i=0; i<n; i++)
	{
		for(j=i+1; j<n; j++)
		{
			if(arr[j] <= arr[i]){
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

void insert(int arr[], int *n, int data)
{
	arr[(*n)] = data;	
	*n=*n+1;
}

int delete(int arr[], int *n)
{
	int x = arr[*n-1];
	*n = *n -1;
	return x;
}
void sortDescending(int arr[], int n)
{
	int i,j;
	printf("Sort in descennding\n");
	for(i=0; i<n; i++)
	{
		for(j=i+1; j<n; j++)
		{
			if(arr[j] >= arr[i]){
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}


int main()
{
	int n;
	printf("Enter the number of elements\n");
	scanf("%d", &n);
	
	int arr[50];
	input(arr,n);
	output(arr, n);
	sortAscending(arr, n);
	output(arr, n);
	sortDescending(arr, n);
	output(arr, n);
	
	insert(arr, &n, 99);
	output(arr, n);
	delete(arr, &n);
	output(arr, n);
	return 0;
}

