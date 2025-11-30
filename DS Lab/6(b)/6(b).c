#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;      
struct node *front = NULL;    
struct node *rear = NULL;

void displayStack() {
    struct node *temp = top;
    printf("\nSTACK: ");
    if (temp == NULL) {
        printf("EMPTY\n");
        return;
    }
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void displayQueue() {
    struct node *temp = front;
    printf("\nQUEUE: ");
    if (temp == NULL) {
        printf("EMPTY\n");
        return;
    }
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void push() {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter data to push: ");
    scanf("%d", &newnode->data);
    newnode->next = top;
    top = newnode;
    printf("Pushed successfully.");
    displayStack();
}

void pop() {
    if (top == NULL) {
        printf("\nStack Underflow\n");
        return;
    }

    struct node *temp = top;
    printf("\nPopped: %d", temp->data);
    top = top->next;
    free(temp);

    displayStack();
}

void enqueue() {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter data to enqueue: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    if (rear == NULL)
        front = rear = newnode;
    else {
        rear->next = newnode;
        rear = newnode;
    }

    printf("Enqueued successfully.");
    displayQueue();
}


void dequeue() {
    if (front == NULL) {
        printf("\nQueue Underflow\n");
        return;
    }

    struct node *temp = front;
    printf("\nDequeued: %d", temp->data);
    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);

    displayQueue();
}

int main() {
    int choice;

    while (1) {
        printf("\n--- STACK & QUEUE MENU ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Enqueue\n");
        printf("4. Dequeue\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: enqueue(); break;
            case 4: dequeue(); break;
            case 5: return 0;
            default: printf("Invalid choice");
        }
    }
}
