#include <stdio.h>
int recursiveBinarySearch(int array[], int s, int e, int key){
   if (e >= s){
      int middle = s + (e - s )/2;
      if (array[middle] == key)
         return middle;
      if (array[middle] > key)
         return recursiveBinarySearch(array, s, middle-1, key);
      return recursiveBinarySearch(array, middle+1, e, key);
   }
   return -1;
}
int main(void){
   int array[] = {1, 4, 7, 9, 16, 56, 70};
   int n = 7;
   int key = 9;
   int found = recursiveBinarySearch(array, 0, n-1, key);
   if(found == -1 ) {
      printf("key not found in the array ");
   }
   else {
      printf("key found at index : %d",found);
   }
   return 0;
}
