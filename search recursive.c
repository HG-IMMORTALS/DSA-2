#include <stdio.h>
int recursiveBinarySearch(int a[], int s, int e, int key){
   if (e >= s){
      int middle = s + (e - s )/2;
      if (a[middle] == key)
         return middle;
      if (a[middle] > key)
         return recursiveBinarySearch(a, s, middle-1, key);
      return recursiveBinarySearch(a, middle+1, e, key);
   }
   return -1;
}
int main(void){
   int a[] = {1, 4, 7, 9, 16, 56, 70};
   int n = 7;
   int key = 9;
   int found = recursiveBinarySearch(a, 0, n-1, key);
   if(found == -1 ) {
      printf("key not found in the a ");
   }
   else {
      printf("key found at index : %d",found);
   }
   return 0;
}
