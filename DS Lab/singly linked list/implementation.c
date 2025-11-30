#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void createlist() {
    struct node *newnode, *temp;
    int n;
    printf("\nEnter number of elements in the list: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }

    printf("\nLinked list created successfully.\n");
}

void insertatbeg() {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter data: ");
    scanf("%d", &newnode->data);
    newnode->next = head;
    head = newnode;
    printf("\nNode inserted at beginning.\n");
}

void insertatend() {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        struct node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }
    printf("\nNode inserted at end.\n");
}

void insertatpos() {
    int pos;
    struct node *temp = head;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    printf("\nEnter data: ");
    scanf("%d", &newnode->data);
    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos < 1) {
        printf("Invalid position\n");
        return;
    } else if (pos == 1) {
        newnode->next = head;
        head = newnode;
    } else {
        for (int i = 1; i < pos - 1 && temp != NULL; i++)
            temp = temp->next;

        if (temp == NULL) {
            printf("Invalid position\n");
            free(newnode);
            return;
        }

        newnode->next = temp->next;
        temp->next = newnode;
    }

    printf("Node inserted at position %d\n", pos);
}

void display() {
    if (head == NULL) {
        printf("\nList is empty.\n");
        return;
    }

    struct node *temp = head;
    printf("\nLinked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int choice;
    printf("Linked List Menu:\n");
    printf("1. Create Linked List\n");
    printf("2. Insert at Beginning\n");
    printf("3. Insert at End\n");
    printf("4. Insert at Position\n");
    printf("5. Display\n");
    printf("6. Exit\n");

    while (1) {
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createlist();
            break;
            case 2: insertatbeg();
            break;
            case 3: insertatend();
            break;
            case 4: insertatpos();
            break;
            case 5: display();
            break;
            case 6:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;

