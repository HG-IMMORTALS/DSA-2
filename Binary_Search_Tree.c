#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode *root = NULL;

void find(int x, TreeNode **loc, TreeNode **par)
{
    TreeNode *ptr, *ptrpar;
    if (root == NULL)
    {
        *par = NULL;
        *loc = NULL;
        return;
    }
    if (x == root->data)
    {
        *par = NULL;
        *loc = root;
        return;
    }
    ptrpar = root;
    if (x < root->data)
        ptr = root->left;
    if (x > root->data)
        ptr = root->right;

    while (ptr != NULL)
    {
        if (x == ptr->data)
        {
            *loc = ptr;
            *par = ptrpar;
            return;
        }
        ptrpar = ptr;
        if (x < ptr->data)
            ptr = ptr->left;
        else if (x > ptr->data)
            ptr = ptr->right;
    }
    *par = ptrpar;
    *loc = ptr;
}
void insert(int x)
{
    TreeNode *newN = (TreeNode *)malloc(sizeof(TreeNode));
    if (newN == NULL)
    {
        printf("Overflow\n");
        return;
    }
    newN->data = x;
    newN->left = NULL;
    newN->right = NULL;
    if (root == NULL)
    {
        root = newN;
        return;
    }
    TreeNode *loc, *par;
    find(x, &loc, &par);
    if (loc != NULL)
    {
        printf("Exists\n");
        return;
    }

    if (x < par->data)
        par->left = newN;

    else if (x > par->data)
        par->right = newN;
}

void inorder(TreeNode *temp)
{
    if (temp == NULL)
    {
        return;
    }
    // LNR
    inorder(temp->left);
    printf("%d ", temp->data);
    inorder(temp->right);
}

// void case1(TreeNode *loc, TreeNode *par)
// {
//     if (par == NULL)
//     {
//         root = NULL;
//         // return;
//     }
//     if (par->left == loc)
//         par->left = NULL;
//     if (par->right == loc)
//         par->right = NULL;
// }

void case1(TreeNode *loc, TreeNode *par)
{
    if (par == NULL)
    {
        root = NULL;
    }
    if (par->left == loc)
    {
        par->left = NULL;
    }
    if (par->right == loc)
    {
        par->right = NULL;
    }
}
void case2(TreeNode *loc, TreeNode *par)
{
    TreeNode *child;
    if (loc->left != NULL)
        child = loc->left;
    else if (loc->right != NULL)
        child = loc->right;

    if (par->left == loc)
        par->left = child;
    if (par->right == loc)
        par->right = child;
}

void case3(TreeNode *loc, TreeNode *par)
{
    TreeNode *succ = loc, *parSucc = par;
    while (succ->left != NULL)
    {
        parSucc = succ;
        succ = succ->left;
    }
    if (succ->right == NULL)
        case1(succ, parSucc);
    else if (succ->right != NULL)
        case2(loc, par);

    if (par->left == loc)
        par->left = succ;
    else if (par->right == loc)
        par->right = succ;

    succ->left = loc->left;
    succ->right = loc->right;

    if (loc == root)
        root = NULL;
}
void delete (int x)
{
    TreeNode *par, *loc;
    find(x, &loc, &par);
    if (loc == NULL)
    {
        printf("Doesn't exist");
        return;
    }
    if (loc->left == NULL && loc->right == NULL)
        case1(loc, par);
    else if (loc->left == NULL && loc->right != NULL)
        case2(loc, par);
    else if (loc->left != NULL && loc->right == NULL)
        case2(loc, par);
    else if (loc->left != NULL && loc->right != NULL)
        case3(loc, par);

    free(loc);
}
int main()
{
    insert(10);
    insert(5);
    insert(50);
    insert(20);
    insert(80);
    insert(70);
    insert(100);
    insert(60);
    TreeNode *temp = root;
    inorder(temp);
    printf("\n");
    delete (20);
    inorder(temp);
    return 0;
}