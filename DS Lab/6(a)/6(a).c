#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head1 = NULL;
struct node *head2 = NULL;

void display(struct node *head) {
    if (head == NULL) {
        printf("\nList is empty\n");
        return;
    }
    struct node *temp = head;
    printf("\nList: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct node* createList() {
    int n;
    struct node *head = NULL, *temp, *newnode;

    printf("\nEnter number of nodes: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL)
            head = temp = newnode;
        else {
            temp->next = newnode;
            temp = newnode;
        }
    }

    printf("\nList created successfully.");
    display(head);
    return head;
}

void sortList(struct node *head) {
    struct node *i, *j;
    int temp;

    if (head == NULL) return;

    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    printf("\nList sorted.");
    display(head);
}

struct node* reverseList(struct node *head) {
    struct node *prev = NULL, *curr = head, *next;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    printf("\nList reversed.");
    display(prev);
    return prev;
}

struct node* concatenate(struct node *h1, struct node *h2) {
    if (h1 == NULL) {
        printf("\nList concatenated.");
        display(h2);
        return h2;
    }

    struct node *temp = h1;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = h2;

    printf("\nLists concatenated.");
    display(h1);
    return h1;
}

int main() {
    int choice;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Create List 1\n");
        printf("2. Create List 2\n");
        printf("3. Sort List 1\n");
        printf("4. Reverse List 1\n");
        printf("5. Concatenate Lists\n");
        printf("6. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head1 = createList();
                break;
            case 2:
                head2 = createList();
                break;
            case 3:
                sortList(head1);
                break;
            case 4:
                head1 = reverseList(head1);
                break;
            case 5:
                head1 = concatenate(head1, head2);
                break;
            case 6:
                return 0;
            default: printf("Invalid choice");
        }
    }
}
