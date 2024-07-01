#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *right,*left;
};
struct node *newnode(int data)
{
    struct node *n=(struct node*)malloc(sizeof(struct node));
    n->data=data;
    n->left=n->right=NULL;
    return n;
}
struct node *insert(struct node *root,int data)
{
    if(root==NULL)
    return newnode(data);
    if(data<root->data)
    root->left=insert(root->left,data);
    if(data>root->data)
    root->right=insert(root->right,data);
    return root;
}
void inorder(struct node *root)
{
    if(root==NULL)
    return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
void preorder(struct node *root)
{
    if(root==NULL)
    return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct node *root)
{
    if(root==NULL)
    return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}
int count(struct node *root)
{
    if(root==NULL)
    return 0;
    else
    return 1 + count(root->left) +count(root->right);
}
struct node *findmin(struct node *root)
{
    struct node *current=root;
    while(current&&current->left!=NULL)
    {
        current=current->left;
    }
    return current;
}
struct node *findmax(struct node *root)
{
    struct node *current=root;
    while(current&&current->right!=NULL)
    {
        current=current->right;
    }
    return current;
}
int main()
{
    struct node *root=NULL;
    int n,d,i;
    printf("ENTER THE ELEMENTS TO PRINT:");
    scanf("%d",&n);
    printf("ELEMENTS:");
    for (i = 0; i < n; i++) {
        scanf("%d", &d);
        root = insert(root, d);
    }
    printf("INORDER TRAVERSAL:");
    inorder(root);
    printf("\n");
    printf("PREORDER TRAVERSAL:");
    preorder(root);
    printf("\n");
    printf("POSTORDER TRAVERSAL:");
    postorder(root);
    printf("\n");
    int countnode=count(root);
    printf("TOtalcount :%d",countnode);
    struct node *max=findmax(root);
    struct node *min=findmin(root);
    printf("\nMinimum element:%d",min->data);
    printf("\nMaximum element:%d",max->data);
    return 0;
}