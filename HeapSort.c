#include <stdio.h>

void heapify(int *arr, int n, int i)
{
    int largest = i;
    int leftChild = (2 * i) + 1;
    int rightChild = (2 * i) + 2;

    if (leftChild < n && arr[largest] < arr[leftChild])
        largest = leftChild;
    if (rightChild < n && arr[largest] < arr[rightChild])
        largest = rightChild;
    if (largest != i)
    {
        int temp = arr[largest];
        arr[largest] = arr[i];
        arr[i] = temp;

        heapify(arr, n, largest);
    }
}
void heapSort(int *arr, int n)
{
	int i;
    for (i = n / 2 - 1; i > 0; i--)
    {
        heapify(arr, n, i);
    }

    for (i = n - 1; i >= 0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}
int main()
{
    int arr[15] = {3, 7, 0, 1, 5, 8, 2, 34, 66, 87, 23, 12, 12, 12};
    int n = 15;
    int i; 
    heapSort(arr, n);
    for (i= 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
