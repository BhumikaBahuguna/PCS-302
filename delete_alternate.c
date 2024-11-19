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

// Function to delete alternate nodes from the linked list
void deleteAlternateNodes(sl** head) {
    if (*head == NULL) return; // If the list is empty

    sl* current = *head;
    sl* temp;

    while (current != NULL && current->next != NULL) {
        // Skip the next node
        temp = current->next; // Node to be deleted
        current->next = temp->next; // Link to the node after the next
        free(temp); // Free the deleted node
        current = current->next; // Move to the next node
    }
}

int main() {
    sl* head = NULL;

    printf("Create Linked List:\n");
    insertNodes(&head); // Insert nodes into the linked list

    printf("Original Linked List: ");
    printList(head);

    // Delete alternate nodes
    deleteAlternateNodes(&head);
    printf("Linked List after deleting alternate nodes: ");
    printList(head);

    // Free the allocated memory (not shown here for brevity)
    // Add code to free the linked list

    return 0;
}
