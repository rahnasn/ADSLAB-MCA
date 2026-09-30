#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *last = NULL;

/* Insert at beginning */
void insertBegin(int value) {
    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->data = value;

    if (last == NULL) {
        last = newNode;
        newNode->next = last;
    } else {
        newNode->next = last->next;
        last->next = newNode;
    }
}

/* Insert at end */
void insertEnd(int value) {
    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->data = value;

    if (last == NULL) {
        last = newNode;
        newNode->next = last;
    } else {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }
}

/* Delete from beginning */
void deleteBegin() {
    struct Node *temp;

    if (last == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = last->next;

    if (last == temp) {
        last = NULL;
    } else {
        last->next = temp->next;
    }

    free(temp);
}

/* Delete from end */
void deleteEnd() {
    struct Node *temp;

    if (last == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = last->next;

    if (temp == last) {
        free(last);
        last = NULL;
        return;
    }

    while (temp->next != last)
        temp = temp->next;

    temp->next = last->next;
    free(last);
    last = temp;
}

/* Search */
void search(int value) {
    struct Node *temp;
    int pos = 1;

    if (last == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = last->next;

    do {
        if (temp->data == value) {
            printf("Element found at position %d\n", pos);
            return;
        }

        temp = temp->next;
        pos++;

    } while (temp != last->next);

    printf("Element not found\n");
}

/* Display */
void display() {
    struct Node *temp;

    if (last == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = last->next;

    printf("Circular List: ");

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != last->next);

    printf("\n");
}

/* Count nodes */
void count() {
    struct Node *temp;
    int c = 0;

    if (last == NULL) {
        printf("Number of nodes = 0\n");
        return;
    }

    temp = last->next;

    do {
        c++;
        temp = temp->next;
    } while (temp != last->next);

    printf("Number of nodes = %d\n", c);
}

int main() {
    int choice, value, n, i;

    while (1) {
        printf("\n--- CIRCULAR LINKED LIST ---\n");
        printf("1. Create\n");
        printf("2. Insert Beginning\n");
        printf("3. Insert End\n");
        printf("4. Delete Beginning\n");
        printf("5. Delete End\n");
        printf("6. Search\n");
        printf("7. Display\n");
        printf("8. Count\n");
        printf("9. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter number of nodes: ");
                scanf("%d", &n);

                for (i = 0; i < n; i++) {
                    printf("Enter value: ");
                    scanf("%d", &value);
                    insertEnd(value);
                }
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertBegin(value);
                break;

            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(value);
                break;

            case 4:
                deleteBegin();
                break;

            case 5:
                deleteEnd();
                break;

            case 6:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(value);
                break;

            case 7:
                display();
                break;

            case 8:
                count();
                break;

            case 9:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
