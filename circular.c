#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = *head;
}


int sumOfElements(struct Node* head) {
    if (head == NULL) return 0;
    int sum = 0;
    struct Node* temp = head;
    do {
        sum += temp->data;
        temp = temp->next;
    } while (temp != head);
    return sum;
}


void printList(struct Node* head) {
    if (head == NULL) return;
    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

int main() {
    struct Node* head = NULL;
    
    for (int i = 1; i <= 10; i++) {
        insertAtEnd(&head, i);
    }
    
    printf("Circular Linked List:\n");
    printList(head);
    
    int sum = sumOfElements(head);
    printf("Sum of elements in the circular linked list: %d\n", sum);
    return 0;
}

