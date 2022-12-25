#include <stdio.h>
int main()
{
  int c, s,e,mid,n,key,a[100];

  printf("Enter number of elements\n");
  scanf("%d",&n);
  
  printf("Enter %d integers\n",n);
  
  for (c=0;c<n;c++)
    scanf("%d",&a[c]);
    
  printf("Enter value to find\n");
  scanf("%d",&key);
  
  s=0;
  e=n- 1;
  mid=s+(e-s)/2;
  while(s<=e)
  {
    if (a[mid]<key)
      s= mid+1;
    else if (a[mid]==key)
	{
      printf("%d found at location %d.\n", key, mid+1);
      break;
    }
    else
      e=mid-1;
    mid=s+(e-s)/2;
  }
  if (s>e)
    printf("Not found! %d isn't present in the list.\n", key);
  return 0;
}
