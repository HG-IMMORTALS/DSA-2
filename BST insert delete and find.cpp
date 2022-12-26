#include <stdio.h>
#include <stdlib.h>

struct node {
	int key;
	struct node *left, *right;
};
struct node* newNode(int item)
{
	struct node* temp
		= (struct node*)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}
void inorder(struct node* root)
{
	if (root != NULL) {
		inorder(root->left);
		printf("%d ", root->key);
		inorder(root->right);
	}
}
struct node* insert(struct node* root, int key)
{
	if (root == NULL)
		return newNode(key);
	if (key < root->key)
		root->left = insert(root->left, key);
	else
		root->right = insert(root->right, key);
	return root;
}
struct node* minValueNode(struct node* root)
{
	struct node* current = root;
	while (current && current->left != NULL)
		current = current->left;

	return current;
}
struct node* deleteNode(struct node* root, int key)
{
	if (root == NULL)
		return root;
	if (key < root->key)
		root->left = deleteNode(root->left, key);
	else if (key > root->key)
		root->right = deleteNode(root->right, key);
	else {
		if (root->left == NULL) {
			struct node* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			struct node* temp = root->left;
			free(root);
			return temp;
		}
		struct node* temp = minValueNode(root->right);
		root->key = temp->key;
		root->right = deleteNode(root->right, temp->key);
	}
	return root;
}
struct node*search(struct node*root,int key)
{
	if(root==NULL)
	{
		return NULL;
	}
	if(key==root->key)
	{
		return root;
	}
	else if(key<root->key)
	{
		return search(root->left,key);
	}
	else
	return search(root->right,key);
}
int main()
{
	struct node* root = NULL;
	int element;
	int ch,in;
	while(1){
		printf("Enter 1 for Insertion\n");
		printf("Enter 2 for Deletion\n");
		printf("Enter 3 to print Node\n");
		printf("Enter 4 to find Node\n");
	scanf("%d",&ch);
	switch(ch){
		case 1:
			printf("Enter Element to be inserted : \n");
			scanf("%d",&element);
			root = insert(root,element);
			break;
		case 2:
			printf("Enter Element to be deleted : \n");
			scanf("%d",&element);
			root = deleteNode(root, element);
			break;
		case 3:
			printf("Inorder traversal of the given tree \n");
			inorder(root);
			break;
		case 4: struct node *n;
		        int ele;
		        printf("enter the ele\n");
		        scanf("%d",&ele);
		        n=search(root,ele);
		        if(n!=NULL)
		        {
			      printf("found :%d",n->key);
		        }
		        else
		         printf("element not found");
		         break;
		
		default:
			printf("Enter choice from above\n");
			break;
		}
	
		}
		return 0;
	}
	
