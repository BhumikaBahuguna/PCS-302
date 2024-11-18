//circular ll add , delete (from first from last at any specific position)

#include <stdio.h>
#include <stdlib.h>

typedef struct cqueue {
    int data;
    struct cqueue *next;
} cl;

// Function prototypes
void createList(cl **head);
void insertAtBeginning(cl **head);
void insertAtEnd(cl **head);
void insertAtPosition(cl **head);
void deleteAtBeginning(cl **head);
void deleteAtEnd(cl **head);
void deleteAtPosition(cl **head);
void display(cl *head);
void peek(cl *head);

int main() {
    cl *head = NULL; // Initialize the head of the circular linked list
    int choice;

    // Create the initial circular linked list
    createList(&head);

    do {
        printf("\nChoose an operation:\n");
        printf("1 - Insert at Beginning\n");
        printf("2 - Insert at End\n");
        printf("3 - Insert at Specific Position\n");
        printf("4 - Delete from Beginning\n");
        printf("5 - Delete from End\n");
        printf("6 - Delete from Specific Position\n");
        printf("7 - Display List\n");
        printf("8 - Peek\n");
        printf("9 - Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1:
                insertAtBeginning(&head);
                break;
            case 2:
                insertAtEnd(&head);
                break;
            case 3:
                insertAtPosition(&head);
                break;
            case 4:
                deleteAtBeginning(&head);
                break;
            case 5:
                deleteAtEnd(&head);
                break;
            case 6:
                deleteAtPosition(&head);
                break;
            case 7:
                display(head);
                break;
            case 8:
                peek(head);
                break;
            case 9:
                printf("Thank you for using this program!!\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 9);
    return 0;
}

// Function to create an initial circular linked list
void createList(cl **head) {
    int ch, v;
    cl *last = NULL;

    while (1) {
        cl *newNode = (cl *)malloc(sizeof(cl));
        if (newNode != NULL) {
            printf("Input data: ");
            scanf("%d", &v);
            newNode->data = v;

            if (*head == NULL) {
                *head = newNode;
                last = newNode;
                newNode->next = *head; // Point to itself
            } else {
                last->next = newNode;
                newNode->next = *head;
                last = newNode;
            }
        } else {
            printf("Memory allocation failed!\n");
            return;
        }

        printf("Enter 1 to continue and 0 to stop: ");
        scanf("%d", &ch);
        if (ch == 0) break;
    }
}

// Function to insert at the beginning
void insertAtBeginning(cl **head) {
    cl *newNode = (cl *)malloc(sizeof(cl));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("Enter data: ");
    scanf("%d", &(newNode->data));

    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head; // Point to itself
    } else {
        cl *last = *head;
        while (last->next != *head) {
            last = last->next; // Find the last node
        }
        newNode->next = *head;
        last->next = newNode;
        *head = newNode; // Update head
    }
}

// Function to insert at the end
void insertAtEnd(cl **head) {
    cl *newNode = (cl *)malloc(sizeof(cl));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("Enter data: ");
    scanf("%d", &(newNode->data));
    newNode->next = *head; // Point to head

    if (*head == NULL) {
        *head = newNode; // List is empty
    } else {
        cl *last = *head;
        while (last->next != *head) {
            last = last->next; // Find the last node
        }
        last->next = newNode; // Link last node to new node
    }
}

// Function to insert at a specific position
void insertAtPosition(cl **head) {
    int pos;
    printf("Enter position to insert (1-based index): ");
    scanf("%d", &pos);

    if (pos < 1) {
        printf("Invalid position!\n");
        return;
    }
    cl *newNode = (cl *)malloc(sizeof(cl));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("Enter data: ");
    scanf("%d", &(newNode->data));

    cl *current = *head;
    for (int i = 1; i < pos - 1 && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Position out of bounds!\n");
        free(newNode);
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}

// Function to delete from the beginning
void deleteAtBeginning(cl **head) {
    if (*head == NULL) {
        printf("Circular Linked List is empty!\n");
        return;
    }

    cl *temp = *head;
    printf("%d is removed from the circular linked list\n", temp->data);
    if (*head == (*head)->next) { // Only one node
        free(*head);
        *head = NULL; // List is now empty
    } else {
        cl *last = *head;
        while (last->next != *head) {
            last = last->next; // Find the last node
        }
        *head = (*head)->next; // Update head
        last->next = *head; // Link last node to new head
        free(temp);
    }
}

// Function to delete from the end
void deleteAtEnd(cl **head) {
    if (*head == NULL) {
        printf("Circular Linked List is empty!\n");
        return;
    }

    cl *current = *head;
    if (current->next == *head) { // Only one node
        printf("%d is removed from the circular linked list\n", current->data);
        free(current);
        *head = NULL; // List is now empty
        return;
    }

    while (current->next->next != *head) {
        current = current->next; // Find the second last node
    }

    printf("%d is removed from the circular linked list\n", current->next->data);
    free(current->next);
    current->next = *head; // Link second last node to head
}

// Function to delete from a specific position
void deleteAtPosition(cl **head) {
    int pos;
    printf("Enter position to delete (1-based index): ");
    scanf("%d", &pos);

    if (pos < 1 || *head == NULL) {
        printf("Invalid position or list is empty!\n");
        return;
    }
    cl *current = *head;
    for (int i = 1; i < pos - 1 && current->next != *head; i++) {
        current = current->next; // Traverse to the node before the one to delete
    }

    if (current->next == *head) {
        printf("Position out of bounds!\n");
        return;
    }

    cl *temp = current->next;
    printf("%d is removed from the circular linked list\n", temp->data);
    current->next = temp->next; // Bypass the node to delete
    free(temp);
}

// Function to display the circular linked list
void display(cl *head) {
    if (head == NULL) {
        printf("Circular Linked List is empty!\n");
        return;
    }

    cl *current = head;
    printf("Contents of the circular linked list are:\n");
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

// Function to peek at the first element
void peek(cl *head) {
    if (head == NULL) {
        printf("Circular Linked List is empty!\n");
    } else {
        printf("First element is: %d\n", head->data);
    }
}
