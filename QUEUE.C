#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Define the structure for the queue
struct Queue {
    struct Node *front, *rear;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize the queue
void initQueue(struct Queue* q) {
    q->front = q->rear = NULL;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* q) {
    return q->front == NULL;
}

// Function to enqueue an element into the queue
void enqueue(struct Queue* q, int data) {
    struct Node* newNode = createNode(data);
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

// Function to dequeue an element from the queue
int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue underflow\n");
        return -1;
    }
    struct Node* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return data;
}

// Function to get the number of elements in the queue
int size(struct Queue* q) {
    int count = 0;
    struct Node* temp = q->front;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Function to display the elements in the queue
void display(struct Queue* q) {
    struct Node* temp = q->front;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Queue q;
    initQueue(&q);

    // Enqueue elements 1, 2, 3, and 4 into the queue
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);

    printf("Queue after enqueuing 1, 2, 3, 4:\n");
    display(&q);

    // Perform dequeue operation twice
    dequeue(&q);
    dequeue(&q);

    printf("Queue after dequeuing two elements:\n");
    display(&q);

    // Display the number of elements in the queue
    printf("Number of elements in the queue: %d\n", size(&q));

    return 0;
}
