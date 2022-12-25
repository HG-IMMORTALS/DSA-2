#include<stdio.h>
#include<stdlib.h>
typedef struct emp{
	char name[30];
	int age;
	double salary;
}data;

int main(){
	int n,i;
	printf("ENTER THE NUMBER OF EMPLOYEES :- \n");
	scanf("%d",&n);
	data *emp_data;
	emp_data=(data*)calloc(sizeof(data),n);
	for(i=0;i<n;i++){
		printf("ENTER THE NAME \n");
		fflush(stdin);
		gets(emp_data[i].name);
		
		printf("ENTER THE SALARY \n");
		scanf("%d",&emp_data[i].salary);
		printf("ENTER THE AGE\n");
		scanf("%d",&emp_data[i].age);
		
	}
	for(i=0;i<n;i++){
		printf("\nTHE DETAILS ARE \n%s\n%ld\n%d ",emp_data[i].name,emp_data[i].salary,emp_data[i].age);
	}	
}
