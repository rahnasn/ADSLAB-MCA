#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

/* Insert at Front */
void insertFront()
{
    struct node *newnode;
    int value;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter value: ");
    scanf("%d", &value);

    newnode->data = value;
    newnode->prev = NULL;
    newnode->next = head;

    if (head != NULL)
        head->prev = newnode;

    head = newnode;

    printf("Node inserted at front.\n");
}

/* Insert at End */
void insertEnd()
{
    struct node *newnode, *temp;
    int value;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter value: ");
    scanf("%d", &value);

    newnode->data = value;
    newnode->next = NULL;

    if (head == NULL)
    {
        newnode->prev = NULL;
        head = newnode;
        printf("Node inserted at end.\n");
        return;
    }

    temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newnode;
    newnode->prev = temp;

    printf("Node inserted at end.\n");
}

/* Insert at Any Position */
void insertPosition()
{
    struct node *newnode, *temp;
    int value, pos, i;

    printf("Enter position: ");
    scanf("%d", &pos);

    printf("Enter value: ");
    scanf("%d", &value);

    if (pos <= 0)
    {
        printf("Invalid position.\n");
        return;
    }

    if (pos == 1)
    {
        newnode = (struct node *)malloc(sizeof(struct node));

        newnode->data = value;
        newnode->prev = NULL;
        newnode->next = head;

        if (head != NULL)
            head->prev = newnode;

        head = newnode;

        printf("Node inserted at position %d.\n", pos);
        return;
    }

    temp = head;

    for (i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Invalid position.\n");
        return;
    }

    newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = value;

    newnode->next = temp->next;
    newnode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newnode;

    temp->next = newnode;

    printf("Node inserted at position %d.\n", pos);
}

/* Delete from Front */
void deleteFront()
{
    struct node *temp;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    printf("%d deleted from front.\n", temp->data);

    free(temp);
}

/* Delete from End */
void deleteEnd()
{
    struct node *temp;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    if (temp->prev != NULL)
        temp->prev->next = NULL;
    else
        head = NULL;

    printf("%d deleted from end.\n", temp->data);

    free(temp);
}

/* Delete from Any Position */
void deletePosition()
{
    struct node *temp;
    int pos, i;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos <= 0)
    {
        printf("Invalid position.\n");
        return;
    }

    temp = head;

    for (i = 1; i < pos && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Invalid position.\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    printf("%d deleted from position %d.\n", temp->data, pos);

    free(temp);
}

/* Display */
void display()
{
    struct node *temp;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = head;

    printf("Doubly Linked List:\n");

    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

/* Main Function */
int main()
{
    int choice;

    while (1)
    {
        printf("\n===== DOUBLY LINKED LIST =====\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Any Position\n");
        printf("4. Delete at Front\n");
        printf("5. Delete at End\n");
        printf("6. Delete at Any Position\n");
        printf("7. Display\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insertFront();
                break;

            case 2:
                insertEnd();
                break;

            case 3:
                insertPosition();
                break;

            case 4:
                deleteFront();
                break;

            case 5:
                deleteEnd();
                break;

            case 6:
                deletePosition();
                break;

            case 7:
                display();
                break;

            case 8:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}

