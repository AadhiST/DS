#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *createnode(int data)
{
    struct node *n=(struct node*)malloc(sizeof(struct node));
    n->data=data;
    n->next=NULL;
    return n;
}
void insert(struct node **head,int data)
{
    struct node *n=createnode(data);
    if(*head==NULL){
    *head=n;
    return;
    }
    struct node *temp=*head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
}
void print(struct node *head)
{
    while(head!=NULL)
    {
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}
int main()
{
    struct node *head=NULL;
    for(int i=1;i<=10;i++)
    {
        insert(&head,i);
    }
    print(head);
    return 0;
}

