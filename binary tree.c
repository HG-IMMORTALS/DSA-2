#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *left;
    struct node *right;
};
struct node *create()
{
	int x;
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("enter the data\n");
	scanf("%d",&x);
	if(x==-1)
	{
		return 0;
	}
	newnode->data=x;
	printf("enter the left child %d\n",x);
	newnode->left=create();
	printf("enter the right child %d\n",x);
	newnode->right=create();
	return newnode;
}
void preorder(struct node *root)
{
	if(!root)
	{
		return ;
	}
	printf("%d ",root->data);
	preorder(root->left);
	printf("\t");
	preorder(root->right);
}
void inorder(struct node *root)
{
	if(!root)
	{
		return ;
	}
	inorder(root->left);
	printf("\t");
	printf("%d ",root->data);
	inorder(root->right);
}
void postorder(struct node *root)
{
	if(!root)
	{
		return ;
	}
	postorder(root->left);
	printf("\t");
	postorder(root->right);
	printf("\t");
	printf("%d ",root->data);
}
int height(struct node* root){
	if(root==NULL){
		return -1;
	} 
		int lefth=height(root->left);
		int righth=height(root->right);
		if(lefth>righth){
			return lefth+1;
		}
		else{
			return righth+1;
		}
	
}
int main()
{
struct node *root;
int ch;
while(1)
{
printf("enter the choice \n1.create\n2.preorder\n3.inorder\n4.postorder\n5.Height of the tree");
scanf("%d",&ch);
switch(ch)
{
	case 1:root=NULL;
           root=create();
	  break;
	case 2:preorder(root);
	  break;
	case 3:inorder(root);
	  break;
	case 4:postorder(root);	
	  break;
	case 5:height(root);
	  break;
	default:printf("invalid choice");
	  break;
}
}
return 0;
}

