#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node  *newnode(int data) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

struct node* insert(struct node *node, int data) {
    if (node == NULL) {
        return newnode(data);
    }
    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    }
    return node;
}

void inorder(struct node *root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

bool search(struct node *root, int key) {
    if (root == NULL) {
        return false;
    }
    if (root->data == key) {
        return true;
    }
    if (key < root->data) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

int main() {
    struct node *root = NULL;
    int elements[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(elements) / sizeof(elements[0]);
    
    for (int i = 0; i < n; i++) {
        root = insert(root, elements[i]);
    }
    
    printf("INORDER: ");
    inorder(root);
    printf("\n");
    
    for (int i = 0; i < n; i++) {
        if (search(root, elements[i])) {
            printf("%d found\n", elements[i]);
        } else {
            printf("%d not found\n", elements[i]);
        }
    }
    
    return 0;
}
