#include<bits/stdc++.h>
using namespace std;

vector<int> pq;
bool isEmpty(){
    return pq.size()==0;
}

int getMin(){
    return pq[0];
}
int getSize(){
    return pq.size();
}

void insert(int element)
{
    pq.push_back(element);
    int childIndex = pq.size()-1;
    while(childIndex > 0)
    {
        int parentIndex = (childIndex-1)/2;
        if(pq[childIndex] < pq[parentIndex])
            swap(pq[childIndex], pq[parentIndex]);
        else
            break;
        childIndex = parentIndex;
    }
}

int removeMin()
{
    int size = pq.size();
    int topItem = pq[0];
    int parentIndex = 0;
    pq[0]=pq[size-1];
    pq.pop_back();
    while((2*(parentIndex)+1 < size) && (2*(parentIndex)+2 < size) )
    {
        int childIndex1 = 2*(parentIndex)+1;
        int childIndex2 = 2*(parentIndex)+2;
        int minIndex;
        minIndex = min(childIndex1, childIndex2);

        if(pq[minIndex] < pq[parentIndex]){
            swap(pq[minIndex], pq[parentIndex]);
        }
        else
        break;

        parentIndex=minIndex;
    }
    return topItem;
}

int main()
{
    //priority queue
    // min heap
    int n,x;
    cout<<"Enter the no of elements\n";
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>x;
        insert(x);
        // cout<<"Top Element in Min Heap: "<<getMin()<<endl;
    }
    for(auto i: pq){
        cout<<removeMin()<<endl;
    }
}