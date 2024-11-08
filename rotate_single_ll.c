//ROTATE SINGLE LINKED LIST N TIMES

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
typedef struct sl {
    int data;
    struct sl *next;
} sl;

// Function prototypes
sl* rotateLinkedList(sl* head, int n);
void printLinkedList(sl* head);

int main() {
    sl *l = NULL; // Head of the list
    sl *r = NULL; // Pointer to keep track of the last node
    int ch, v;

    // Create the linked list
    while (1) {
        sl *p = (sl*)malloc(sizeof(sl));
        if (p != NULL) {
            printf("Input data: ");
            scanf("%d", &v);
            p->data = v;
            p->next = NULL;

            // Append new node to the end of the list
            if (l == NULL) {
                l = p; // If the list is empty, new node becomes the head
                r = p; // Last node is also the new node
            } else {
                r->next = p; // Link the last node to the new node
                r = p; // Update last node to new node
            }
        } else {
            printf("Memory allocation failed.\n");
            return 1; // Return an error code
        }
        
        // Ask user whether to continue or stop
        printf("Enter 1 to continue and 0 to stop: ");
        scanf("%d", &ch);
        if (ch == 0) break;
    }

    // Print the original linked list
    printf("Original Linked List: ");
    printLinkedList(l);

    // Get number of rotations from user
    int n;
    printf("Enter the number of rotations: ");
    scanf("%d", &n);

    // Rotate the linked list
    l = rotateLinkedList(l, n);

    // Print the rotated linked list
    printf("Rotated Linked List: ");
    printLinkedList(l);

    return 0;
}

// Function to rotate the linked list n times
sl* rotateLinkedList(sl* head, int n) {
    if (head == NULL || head->next == NULL || n <= 0) {
        return head; // No rotation needed
    }

    // Compute the length of the list
    sl *current = head;
    int length = 1; // Start with 1 for the head node
    while (current->next != NULL) {
        current = current->next;
        length++;
    }
    
    // Make it circular
    current->next = head;

    // Find the new head after rotation
    n = n % length; // Normalize n to prevent extra rotations
    if (n == 0) {
        current->next = NULL; // If no rotation, break the circular link
        return head;
    }
    
    int stepsToNewHead = length - n;
    current = head;

    for (int i = 0; i < stepsToNewHead - 1; i++) {
        current = current->next;
    }

    // Set the new head and break the circular link
    sl *newHead = current->next;
    current->next = NULL;

    return newHead;
}

// Function to print the linked list
void printLinkedList(sl* head) {
    sl *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
