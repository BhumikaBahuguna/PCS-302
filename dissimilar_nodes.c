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

// Function to print dissimilar nodes of two linked lists
void printDissimilarNodes(sl* list1, sl* list2) {
    sl* temp1 = list1;
    sl* temp2;

    printf("Dissimilar nodes in List 1: ");
    while (temp1 != NULL) {
        temp2 = list2;
        int found = 0;
        while (temp2 != NULL) {
            if (temp1->data == temp2->data) {
                found = 1; // Node found in list2
                break;
            }
            temp2 = temp2->next;
        }
        if (!found) {
            printf("%d  ", temp1->data);
        }
        temp1 = temp1->next;
    }
    printf("\n");

    printf("Dissimilar nodes in List 2: ");
    temp2 = list2;
    while (temp2 != NULL) {
        temp1 = list1;
        int found = 0;
        while (temp1 != NULL) {
            if (temp2->data == temp1->data) {
                found = 1; // Node found in list1
                break;
            }
            temp1 = temp1->next;
        }
        if (!found) {
            printf("%d  ", temp2->data);
        }
        temp2 = temp2->next;
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

    // Print dissimilar nodes
    printDissimilarNodes(list1, list2);


    return 0;
}
