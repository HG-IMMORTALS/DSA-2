#include<stdio.h>
#include<stdlib.h>
void input(int arr[],int n){
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
}
int rep(int arr[],int n){
    int c=0;
    for (int i = 0; i < n; i++) {
        int j;
        for ( j = 0; j < n; j++)
            if (i!=j && arr[i] == arr[j])
                break;
        if (j == n)
            c++;
        if(c==3){
            return arr[i];
        }
    }
    return -1;
}
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    input(arr,n);
    int ans = rep(arr,n);
    printf("%d",ans);
    return 0;
}
