#include<stdio.h>
int main()
{
 int i,j,k;
 float a[3][3],b[3][3],mul[3][3];

 printf("Enter elements of first matrix:\n");
 for(i=0;i<3;i++)
 {
  for(j=0;j<3;j++)
  {
   printf("a[%d][%d]=",i,j);
   scanf("%f",&a[i][j]);
  }
 }
 
 printf("Enter elements of second matrix:\n");
 for(i=0;i<3;i++)
 {
  for(j=0;j<3;j++)
  {
   printf("b[%d][%d]=",i,j);
   scanf("%f",&b[i][j]);
  }
 }
 
 for(i=0;i<3;i++)
 {
  for(j=0;j<3;j++)
  {
   mul[i][j]=0;
   for(k=0;k<3;k++)
   {
    mul[i][j]=mul[i][j]+a[i][k]*b[j][k];
   }
  }
 }
 
 printf("Multiplied matrix is:\n");
 for(i=0;i<3;i++)
 {
  for(j=0;j<3;j++)
  {
   printf("%f\t", mul[i][j]);
  }
  printf("\n");
 }
 return 0;
}


