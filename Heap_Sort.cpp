#include<bits/stdc++.h>
using namespace std;

void heapify(int arr[], int size, int i)
{
    //i is the current parent
    int largest = i;
    int leftChild = 2*i+1;
    int rightChild = 2*i+2;

    //choose the largest element from current parent and left Child and right Child
    if(leftChild < size && arr[largest] < arr[leftChild])
        largest = leftChild;
    if(rightChild < size && arr[largest] < arr[rightChild])
        largest = rightChild;
    
    //if largest is not root
    if(largest !=i){
        swap(arr[largest], arr[i]);
        heapify(arr,size,largest);
    }
}
void heapSort(int arr[], int n)
{
    //Create a Max Heap
    for(int i=(n/2)-1; i<n; i++)
        heapify(arr,n,i);
    //One by one extract element from array and replace max element(0 indexed) with last index 
    for(int i=n-1; i>=0; i--)
    {
        //Move current root to end
        swap(arr[0], arr[i]);

        //recursively call heap sort on reduced heap and make 0 index as the parent;
        heapify(arr,i,0);
    }
}
int main()
{
    int n;
    cout<<"Enter the number of elements\n";
    cin>>n;

    int arr[50];
    cout<<"Enter the elements\n";
    for(int i=0; i<n; i++)
    cin>>arr[i];

    heapSort(arr, n);

    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    return 0;
}