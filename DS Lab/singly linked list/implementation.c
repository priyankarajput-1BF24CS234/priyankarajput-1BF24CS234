#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node *head = NULL;

void createlist(int n) {
    struct node *newnode, *temp;
    int data;

    if (n <= 0) {
        printf("Number of nodes should be greater than 0.\n");
        return;
    }

    for (int i = 1; i <= n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        if (newnode == NULL) {
            printf("Memory not allocated.\n");
            return;
        }

        printf("Enter data to be inserted: ");
        scanf("%d", &data);

        newnode->data = data;
        newnode->next = NULL;

        if (head == NULL) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }
}

void insertatbeg(int data) {
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));

    if (newnode == NULL) {
        printf("Memory not allocated.\n");
        return;
    }

    newnode->data = data;
    newnode->next = head;
    head = newnode;
}

void insertatend(int data) {
    struct node *newnode, *temp;
    newnode = (struct node*)malloc(sizeof(struct node));

    if (newnode == NULL) {
        printf("Memory not allocated.\n");
        return;
    }

    newnode->data = data;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void display() {
    struct node *temp = head;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Linked list elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);
    createlist(n);

    display();

    insertatbeg(100);
    printf("After inserting at beginning:\n");
    display();

    insertatend(999);
    printf("After inserting at end:\n");
    display();

    return 0;
}
