#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

/* Create new node */
struct node* createNode(int value) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

/* Insert at front */
void insertFront() {
    int value;
    printf("Enter value to insert at front: ");
    scanf("%d", &value);

    struct node *newNode = createNode(value);
    newNode->next = head;
    head = newNode;

    printf("Value %d inserted at the front.\n", value);
}

/* Insert at end */
void insertEnd() {
    int value;
    printf("Enter value to insert at end: ");
    scanf("%d", &value);

    struct node *newNode = createNode(value);

    if (head == NULL) {
        head = newNode;
    } else {
        struct node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    printf("Value %d inserted at the end.\n", value);
}

/* Insert at position */
void insertAtPosition() {
    int value, pos, i = 1;
    printf("Enter value to insert: ");
    scanf("%d", &value);
    printf("Enter position: ");
    scanf("%d", &pos);

    struct node *newNode = createNode(value);

    if (pos == 1) {
        newNode->next = head;
        head = newNode;
        printf("Value %d inserted at position %d\n", value, pos);
        return;
    }

    struct node *temp = head;
    while (temp != NULL && i < pos - 1) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    printf("Value %d inserted at position %d\n", value, pos);
}

/* Delete from front */
void deleteFront() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *temp = head;
    head = head->next;
    printf("Element %d deleted from the front.\n", temp->data);
    free(temp);
}

/* Delete from end */
void deleteEnd() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->next == NULL) {
        printf("Element %d deleted from the end.\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    struct node *temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    printf("Element %d deleted from the end.\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
}

/* Delete from position */
void deleteFromPosition() {
    int pos, i = 1;
    printf("Enter position to delete from: ");
    scanf("%d", &pos);

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (pos == 1) {
        struct node *temp = head;
        head = head->next;
        printf("Element %d deleted from position %d\n", temp->data, pos);
        free(temp);
        return;
    }

    struct node *temp = head;
    while (temp->next != NULL && i < pos - 1) {
        temp = temp->next;
        i++;
    }

    if (temp->next == NULL) {
        printf("Invalid position\n");
        return;
    }

    struct node *del = temp->next;
    temp->next = del->next;
    printf("Element %d deleted from position %d\n", del->data, pos);
    free(del);
}

/* Display list */
void display() {
    struct node *temp = head;

    if (temp == NULL) {
        printf("Linked List: NULL\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Insert at Front\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Front\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Position\n");
        printf("7. Display List\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: insertFront(); break;
        case 2: insertEnd(); break;
        case 3: insertAtPosition(); break;
        case 4: deleteFront(); break;
        case 5: deleteEnd(); break;
        case 6: deleteFromPosition(); break;
        case 7: display(); break;
        case 8: exit(0);
        default: printf("Invalid choice\n");
        }
    }

    return 0;
}
