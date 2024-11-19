//Double ll add , delete (from first from last at any specific position)

/*#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    int data;
    struct list *next;
    struct list *prev;
} ll;

void insertion(ll **l, ll **r);
void deletion(ll **l, ll **r);
void display(ll *l);
void insertAtBeginning(ll **l, ll **r);
void insertAtEnd(ll **l, ll **r);
void insertAtPosition(ll **l, ll **r);
void deleteAtBeginning(ll **l, ll **r);
void deleteAtEnd(ll **l, ll **r);
void deleteAtPosition(ll **l, ll **r);

int main() {
    ll *l = NULL, *r = NULL;
    int ch;

    do {
        printf("\nPress the certain keys to do the desired operation:-\n");
        printf("1-Insert\n2-Delete\n3-Display\n4-Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        printf("\n");

        switch (ch) {
        case 1:
            insertion(&l, &r);
            break;
        case 2:
            deletion(&l, &r);
            break;
        case 3:
            display(l);
            break;
        case 4:
            printf("Thank you for using this program!!\n");
            break;
        default:
            printf("Wrong choice\n");
        }
    } while (ch != 4);
    return 0;
}

void insertion(ll **l, ll **r) {
    int choice;
    printf("Choose insertion type:\n");
    printf("1 - At Beginning\n");
    printf("2 - At End\n");
    printf("3 - At Specific Position\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
        insertAtBeginning(l, r);
        break;
    case 2:
        insertAtEnd(l, r);
        break;
    case 3:
        insertAtPosition(l, r);
        break;
    default:
        printf("Invalid choice\n");
    }
}

void deletion(ll **l, ll **r) {
    int choice;
    printf("Choose deletion type:\n");
    printf("1 - From Beginning\n");
    printf("2 - From End\n");
    printf("3 - From Specific Position\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
        deleteAtBeginning(l, r);
        break;
    case 2:
        deleteAtEnd(l, r);
        break;
    case 3:
        deleteAtPosition(l, r);
        break;
    default:
        printf("Invalid choice\n");
    }
}

void insertAtBeginning(ll **l, ll **r) {
    ll *p = (ll *)malloc(sizeof(ll));
    if (p == NULL) {
        printf("Couldn't Allocate Memory!\n");
        return;
    }
    printf("Enter data: ");
    scanf("%d", &(p->data));
    
    p->next = *l;
    p->prev = NULL;

    if (*l != NULL) {
        (*l)->prev = p;
    } else {
        *r = p; // If the list was empty, new node is also the last node
    }
    *l = p; // Update the head
}

void insertAtEnd(ll **l, ll **r) {
    ll *p = (ll *)malloc(sizeof(ll));
    if (p == NULL) {
        printf("Couldn't Allocate Memory!\n");
        return;
    }
    printf("Enter data: ");
    scanf("%d", &(p->data));
    
    p->next = NULL;
    if (*r == NULL) {
        p->prev = NULL;
        *l = p; // If the list is empty, new node becomes the head
    } else {
        (*r)->next = p;
        p->prev = *r;
    }
    *r = p; // Update the last node
}

void insertAtPosition(ll **l, ll **r) {
    int pos;
    printf("Enter position to insert (1-based index): ");
    scanf("%d", &pos);

    if (pos == 1) {
        insertAtBeginning(l, r);
        return;
    }

    ll *p = (ll *)malloc(sizeof(ll));
    if (p == NULL) {
        printf("Couldn't Allocate Memory!\n");
        return;
    }
    printf("Enter data: ");
    scanf("%d", &(p->data));
    
    ll *current = *l;
    for (int i = 1; current != NULL && i < pos - 1; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Position out of bounds!\n");
        free(p);
        return;
    }

    p->next = current->next;
    p->prev = current;

    if (current->next != NULL) {
        current->next->prev = p;
    } else {
        *r = p; // Update last node if we're inserting at the end
    }

    current->next = p;
}

void deleteAtBeginning(ll **l, ll **r) {
    if (*l == NULL) {
        printf("Linked List is empty!\n");
        return;
    }

    ll *p = *l;
    printf("%d is removed from the linked list\n", p->data);
    *l = (*l)->next;

    if (*l != NULL) {
        (*l)->prev = NULL;
    } else {
        *r = NULL; // List is now empty
    }
    
    free(p);
}

void deleteAtEnd(ll **l, ll **r) {
    if (*r == NULL) {
        printf("Linked List is empty!\n");
        return;
    }

    ll *p = *r;
    printf("%d is removed from the linked list\n", p->data);
    *r = (*r)->prev;

    if (*r != NULL) {
        (*r)->next = NULL;
    } else {
        *l = NULL; // List is now empty
    }

    free(p);
}

void deleteAtPosition(ll **l, ll **r) {
    int pos;
    printf("Enter position to delete (1-based index): ");
    scanf("%d", &pos);

    if (pos == 1) {
        deleteAtBeginning(l, r);
        return;
    }

    ll *current = *l;
    for (int i = 1; current != NULL && i < pos; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Position out of bounds!\n");
        return;
    }

    printf("%d is removed from the linked list\n", current->data);
    
    if (current->prev != NULL) {
        current->prev->next = current->next;
    }

    if (current->next != NULL) {
        current->next->prev = current->prev;
    } else {
        *r = current->prev; // Update last node if we're deleting the last one
    }

    free(current);
}

void display(ll *l) {
    if (l == NULL) {
        printf("Linked List is empty!\n");
        return;
    }

    printf("Contents of the linked list are:\n");
    ll *p = l;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    int data;
    struct list *next;
} ll;

void createList(ll **head);
void insertAtBeginning(ll **head);
void insertAtEnd(ll **head);
void insertAtPosition(ll **head);
void deleteAtBeginning(ll **head);
void deleteAtEnd(ll **head);
void deleteAtPosition(ll **head);
void display(ll *head);

int main() {
    ll *head = NULL; // Initialize the head of the list
    int choice;

    // Create the initial singly linked list
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
        printf("8 - Exit\n");
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
            printf("Thank you for using this program!!\n");
            break;
        default:
            printf("Wrong choice\n");
        }
    } while (choice != 8);
    return 0;
}

// Function to create an initial singly linked list
void createList(ll **head) {
    int ch, v;
    ll *r = NULL; // Pointer to keep track of the last node

    while (1) {
        ll *p = (ll *)malloc(sizeof(ll));
        if (p != NULL) {
            printf("Input data: ");
            scanf("%d", &v);
            p->data = v;
            p->next = NULL; // Initialize next to NULL

            // Append new node to the end of the list
            if (*head == NULL) {
                // If the list is empty, new node becomes the head
                *head = p;
                r = p; // Last node is also the new node
            } else {
                // Traverse to the end of the list and append the new node
                r->next = p;
                r = p; // Update the last node to new node
            }
        } else {
            printf("Memory allocation failed!\n");
            return;
        }

        // Ask user whether to continue or stop
        printf("Enter 1 to continue and 0 to stop: ");
        scanf("%d", &ch);
        if (ch == 0) break;
    }
}

// Function to insert at the beginning
void insertAtBeginning(ll **head) {
    ll *newNode = (ll *)malloc(sizeof(ll));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("Enter data: ");
    scanf("%d", &(newNode->data));
    newNode->next = *head;
    *head = newNode;
}

// Function to insert at the end
void insertAtEnd(ll **head) {
    ll *newNode = (ll *)malloc(sizeof(ll));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("Enter data: ");
    scanf("%d", &(newNode->data));
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode; // If the list is empty, new node becomes the head
    } else {
        ll *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode; // Link the last node to the new node
    }
}

// Function to insert at a specific position
void insertAtPosition(ll **head) {
    int pos;
    printf("Enter position to insert (1-based index): ");
    scanf("%d", &pos);

    if (pos < 1) {
        printf("Invalid position!\n");
        return;
    }
    ll *newNode = (ll *)malloc(sizeof(ll));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("Enter data: ");
    scanf("%d", &(newNode->data));

    ll *current = *head;
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
void deleteAtBeginning(ll **head) {
    if (*head == NULL) {
        printf("Linked List is empty!\n");
        return;
    }

    ll *temp = *head;
    printf("%d is removed from the linked list\n", temp->data);
    *head = (*head)->next;
    free(temp);
}

// Function to delete from the end
void deleteAtEnd(ll **head) {
    if (*head == NULL) {
        printf("Linked List is empty!\n");
        return;
    }

    if ((*head)->next == NULL) { // Only one node
        printf("%d is removed from the linked list\n", (*head)->data);
        free(*head);
        *head = NULL; // List is now empty
        return;
    }

    ll *current = *head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    printf("%d is removed from the linked list\n", current->next->data);
    free(current->next);
    current->next = NULL; // Update the last node
}

// Function to delete from a specific position
void deleteAtPosition(ll **head) {
    int pos;
    printf("Enter position to delete (1-based index): ");
    scanf("%d", &pos);

    if (pos < 1 || *head == NULL) {
        printf("Invalid position or list is empty!\n");
        return;
    }
    ll *current = *head;
    for (int i = 1; i < pos - 1 && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL || current->next == NULL) {
        printf("Position out of bounds!\n");
        return;
    }

    ll *temp = current->next;
    printf("%d is removed from the linked list\n", temp->data);
    current->next = temp->next;
    free(temp);
}

// Function to display the linked list
void display(ll *head) {
    if (head == NULL) {
        printf("Linked List is empty!\n");
        return;
    }

    printf("Contents of the linked list are:\n");
    ll *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
