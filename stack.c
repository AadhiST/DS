#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void push(struct node **head,int n)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Stack overflow\n");
        return;
    }
    newnode->data=n;
    newnode->next=*head;
    *head=newnode;
}
int pop(struct node **head)
{
    if(*head==NULL)
    {
        printf("stack underflow\n");
        return -1;
    }
    struct node *temp = *head;
    int pop = temp->data;
    *head = (*head)->next;
    free(temp); // Free the old head
    return pop;
}
int count(struct node *head)
{
    int count=0;
    while(head!=NULL)
    {
        count++;
        head=head->next;
    }
    return count;
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
    struct node *stack=NULL;
    push(&stack,1);
    push(&stack,2);
    push(&stack,3);
    push(&stack,4);
    printf("after push:\n");
    print(stack);
    pop(&stack);
    pop(&stack);
    printf("after pop:\n");
    print(stack);
    printf("total count:%d\n",count(stack));
    return 0;
}