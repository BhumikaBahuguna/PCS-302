//Write a menu driven c program to create a ll by inserting nodes at rhs , Sort the ll in ascending order, Reverse the ll, Display the ll .

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function prototypes
void insertAtEnd(Node** head, int value);
void sortList(Node** head);
void reverseList(Node** head);
void displayList(Node* head);

int main() {
    Node* head = NULL;
    int choice, value;

    do {
        printf("\nMenu:\n");
        printf("1. Insert Node at Right Hand Side\n");
        printf("2. Sort List in Ascending Order\n");
        printf("3. Reverse the List\n");
        printf("4. Display the List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                break;
            case 2:
                sortList(&head);
                printf("List sorted in ascending order.\n");
                break;
            case 3:
                reverseList(&head);
                printf("List reversed.\n");
                break;
            case 4:
                displayList(head);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

// Function to insert a node at the end of the list
void insertAtEnd(Node** head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to sort the linked list in ascending order
void sortList(Node** head) {
    if (*head == NULL) return; // Empty list

    Node *current, *index;
    int temp;

    for (current = *head; current->next != NULL; current = current->next) {
        for (index = current->next; index != NULL; index = index->next) {
            if (current->data > index->data) {
                // Swap data
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
        }
    }
}

// Function to reverse the linked list
void reverseList(Node** head) {
    Node *prev = NULL, *current = *head, *next = NULL;
    while (current != NULL) {
        next = current->next; // Store next node
        current->next = prev; // Reverse current node's pointer
        prev = current;       // Move pointers one position ahead
        current = next;
    }
    *head = prev; // Update head to the new first node
}

// Function to display the linked list
void displayList(Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
