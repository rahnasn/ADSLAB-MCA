#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL;
int count = 0;

/* Push */
void push(int value) {
    struct Node *newNode;

    if (count == MAX) {
        printf("Stack Overflow\n");
        return;
    }

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = top;
    top = newNode;

    count++;

    printf("%d pushed\n", value);
}

/* Pop */
void pop() {
    struct Node *temp;

    if (top == NULL) {
        printf("Stack Underflow\n");
        return;
    }

    temp = top;

    printf("%d popped\n", top->data);

    top = top->next;
    free(temp);

    count--;
}

/* Search */
void search(int value) {
    struct Node *temp = top;
    int pos = 1;

    while (temp != NULL) {
        if (temp->data == value) {
            printf("Element found at position %d\n", pos);
            return;
        }

        temp = temp->next;
        pos++;
    }

    printf("Element not found\n");
}

/* Display */
void display() {
    struct Node *temp = top;

    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack: ");

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- STACK USING SINGLY LINKED LIST ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Search\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(value);
                break;

            case 4:
                display();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
