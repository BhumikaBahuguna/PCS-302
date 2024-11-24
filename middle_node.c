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

// Function to find and print the middle node of the linked list
void printMiddleNode(sl* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    sl* slow = head;
    sl* fast = head;

    // Move fast pointer twice as fast as slow pointer
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;        // Move slow pointer by 1
        fast = fast->next->next; // Move fast pointer by 2
    }

    printf("Middle node data: %d\n", slow->data);
}

int main() {
    sl* list = NULL;

    printf("Create Linked List:\n");
    insertNodes(&list); // Insert nodes into the linked list

    printf("Original Linked List: ");
    printList(list);

    // Print the middle node
    printMiddleNode(list);

    // Free the allocated memory (not shown here for brevity)
    // Add code to free the linked list

    return 0;
}
