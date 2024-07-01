#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left,*right;
};
struct node *newnode(int data)
{
    struct node *n1=(struct node*)malloc(sizeof(struct node));
    n1->data=data;
    n1->left=n1->right=NULL;
    return n1;
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
int main()
{
    struct node *root =newnode(1);
    root->left=newnode(2);
    root->right=newnode(3);
    root->left->left=newnode(4);
    root->left->right=newnode(5);
    printf("INORDER TRAVERSAL:");
    inorder(root);
    printf("\n");
    printf("PREORDER TRAVERSAL:");
    preorder(root);
    printf("\n");
    printf("POSTORDER TRAVERSAL:");
    postorder(root);
    printf("\n");
    return 0;
}