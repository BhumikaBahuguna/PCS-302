//CIRCULAR LL USING SINGLE POINTER
//ADDING NODES AFTER LINKED LIST

#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
} sl;

void addNode(sl* , int );
void displayList(sl* );

int main() {
    sl* last = NULL; 
    sl* p = NULL; 
    int ch, v;

    while (1) {
        printf("Input data: ");
        scanf("%d", &v);
        // Update the last pointer to the newly added node
        if (last == NULL) {
            sl* p = (sl*)malloc(sizeof(sl));
            if (p == NULL) {
                printf("Memory allocation failed\n");
                return 1;
            }
            p->data = v;
            p->next = p;
            last = p; // If the list was empty, initialize last
        } else {
            addNode(last, v);
            last = last->next; // Move last to the new node
        }

        // Ask user whether to continue or stop
        printf("Enter 1 to continue and 0 to stop: ");
        scanf("%d", &ch);
        if (ch == 0) break;
    }

    // Display the circular linked list
    displayList(last);

    return 0;
}

// Function to add a node at the end of the circular linked list using a single pointer
void addNode(sl* last, int data) {
    sl* p = (sl*)malloc(sizeof(sl));
    if (p == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    p->data = data;

    if (last == NULL) { // If the list is empty
        p->next = p; // Point to itself
    } else {
        p->next = last->next; // New node points to the first node
        last->next = p; // Last node points to new node
    }
    last=p;
}

// Function to display the circular linked list
void displayList(sl* last) {
    if (last == NULL) return; // If the list is empty

    sl* temp = last->next; // Start from the first node
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
    printf("(back to %d)\n", last->next->data); // Show it's circular
}

