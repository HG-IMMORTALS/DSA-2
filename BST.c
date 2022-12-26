#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *lchild,*rchild;
};
struct node *root = NULL;

void find(int val,struct node **loc,struct node **par){
	struct node *ptrpar,*ptr;
	if(root == NULL){
		*loc = NULL;
		*par = NULL;
		return;
	}
	if(root->data == val){
		*par = NULL;
		*loc = root;
		return;
	}
	ptrpar = root;
	if(val < root->data){
		ptr = root->lchild;
	}
	if(val > root->data){
		ptr = root->rchild;
	}
	while(ptr != NULL){
		if(ptr->data == val){
			*par = ptrpar;
			*loc = ptr;
			return;
		}
		if(val < ptr->data){
			ptrpar = ptr;
			ptr = ptr->lchild;
		}
		else if(val > ptr->data){
			ptrpar = ptr;
			ptr = ptr->rchild;
		}	
	}
	*par = ptrpar;
	*loc = ptr;
}
void insert(int data){
	struct node *loc,*par,*newNode;
	find(data,&loc,&par);
	if(loc != NULL){
		printf("Element Already Present\n");
		return;
	}
	else{
		newNode = (struct node *)malloc(sizeof(struct node));
		newNode->lchild = NULL;
		newNode->rchild = NULL;
		newNode->data = data;
		if(root == NULL){
			root = newNode;
			return;
		}
		if(data > par->data){
			par->rchild = newNode;
		}
		else if(data < par->data){
			par->lchild = newNode;
		}
	}
}
void inorder(struct node *root){
	if(root != NULL){
		inorder(root->lchild);
		printf("%d ",root->data);
		inorder(root->rchild);
	}
}
int main()
{
	insert(50);
	insert(30);
	insert(80);
	inorder(root);

	return 0;
}

