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
                // If the list is empty, new node becomes the head
                *head = p;
            } else {
                // Traverse to the end of the list and append the new node
                r = *head;
                while (r->next != NULL) {
                    r = r->next;
                }
                r->next = p; // Link the new node
            }
            r=p;
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

// Function to multiply corresponding nodes of two linked lists
void multiplyLists(sl* list1, sl* list2, sl** result) {
    while (list1 != NULL && list2 != NULL) {
        int product = list1->data * list2->data;

        // Create a new node for the result
        sl* p = (sl*)malloc(sizeof(sl));
        if (p != NULL) {
            p->data = product;
            p->next = NULL;

            // Append to the result list
            if (*result == NULL) {
                *result = p; // If result list is empty, set head
            } else {
                sl* r = *result;
                while (r->next != NULL) {
                    r = r->next;
                }
                r->next = p; // Link the new node
            }
        } else {
            printf("Memory allocation failed for result list.\n");
            return;
        }

        // Move to the next nodes
        list1 = list1->next;
        list2 = list2->next;
    }
}

int main() {
    sl* list1 = NULL;
    sl* list2 = NULL;
    sl* result = NULL; // Initialize the result linked list

    printf("Create First Linked List:\n");
    insertNodes(&list1); // Insert nodes into the first linked list

    printf("Create Second Linked List:\n");
    insertNodes(&list2); // Insert nodes into the second linked list

    printf("First Linked List: ");
    printList(list1);
    printf("Second Linked List: ");
    printList(list2);

    // Multiply the lists
    multiplyLists(list1, list2, &result);
    printf("Resultant Linked List (Multiplication): ");
    printList(result);

    // Free the allocated memory (not shown here for brevity)
    // Add code to free the linked lists

    return 0;
}
