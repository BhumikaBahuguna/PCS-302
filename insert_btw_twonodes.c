#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    int data;
    struct list *next;
} sl;

// Function to insert nodes into a linked list
void insertNodes(sl** head) {
    int v, ch;
    sl* p;
    sl* r;

    while (1) {
        p = (sl*)malloc(sizeof(sl));
        if (p != NULL) {
            printf("Input data: ");
            scanf("%d", &v);
            p->data = v;
            p->next = NULL; // Initialize next to NULL

            // Append new node to the end of the list
            if (*head == NULL) {
                *head = p; // If the list is empty, new node becomes the head
            } else {
                r = *head;
                while (r->next != NULL) {
                    r = r->next; // Traverse to the end
                }
                r->next = p; // Link the new node
            }
        } else {
            printf("Memory allocation failed.\n");
            return;
        }

        // Ask user whether to continue or stop
        printf("Enter 1 to continue and 0 to stop: ");
        scanf("%d", &ch);
        if (ch == 0) break;
    }
}

// Function to print the linked list
void printList(sl* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Function to insert a node between two specified nodes
void insertBetween(sl** head, int newValue, int afterValue) {
    sl* current = *head;

    // Find the node after which to insert the new node
    while (current != NULL && current->data != afterValue) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Node with value %d not found.\n", afterValue);
        return; // Node with afterValue not found
    }

    // Create the new node
    sl* newNode = (sl*)malloc(sizeof(sl));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = newValue;
    newNode->next = current->next; // Link to the next node
    current->next = newNode; // Link the new node after current
}

int main() {
    sl* list = NULL;

    printf("Create Linked List:\n");
    insertNodes(&list); // Insert nodes into the linked list

    printf("Original Linked List: ");
    printList(list);

    int newValue, afterValue;
    printf("Enter value to insert: ");
    scanf("%d", &newValue);
    printf("Enter the value after which to insert: ");
    scanf("%d", &afterValue);

    // Insert the new node
    insertBetween(&list, newValue, afterValue);

    printf("Linked List after insertion: ");
    printList(list);

    // Free the allocated memory (not shown here for brevity)
    // Add code to free the linked list

    return 0;
}
