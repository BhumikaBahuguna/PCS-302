//PALINDROME CHECK FOR A LINKED LIST 
#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    int data;
    struct list *next;
} sl;

// Function to reverse the linked list
sl* reverseList(sl* head) {
    sl* prev = NULL;
    sl* current = head;
    sl* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev; // New head of the reversed list
}

// Function to check if the linked list is a palindrome
int isPalindrome(sl* head) {
    if (head == NULL || head->next == NULL) {
        return 1; // An empty list or a single node list is a palindrome
    }

    sl *slow = head, *fast = head;
    // Find the middle of the list
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half of the list
    sl* secondHalf = reverseList(slow);
    sl* firstHalf = head;

    // Compare the two halves
    while (secondHalf != NULL) {
        if (firstHalf->data != secondHalf->data) {
            return 0; // Not a palindrome
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }
    return 1; // It's a palindrome
}

int main() {
    sl *l = NULL; // Initialize the head of the list to NULL
    sl *t = NULL; // Temporary pointer for traversing
    sl *r = NULL; // Pointer to keep track of the last node
    int ch, v;

    while (1) {
        sl *p = (sl*)malloc(sizeof(sl));
        if (p != NULL) {
            printf("Input data: ");
            scanf("%d", &v);
            p->data = v;
            p->next = NULL;
        }

        // Append new node to the end of the list
        if (l == NULL) {
            l = p; // New node becomes the head
        } else {
            r = l;
            while (r->next != NULL) {
                r = r->next;
            }
            r->next = p; // Append the new node
        }

        // Ask user whether to continue or stop
        printf("Enter 1 to continue and 0 to stop: ");
        scanf("%d", &ch);
        if (ch == 0) break;
    }

    // Print the list
    t = l;
    printf("The linked list is: ");
    while (t != NULL) {
        printf("%d  ", t->data);
        t = t->next;
    }
    printf("\n");

    // Check if the list is a palindrome
    if (isPalindrome(l)) {
        printf("The linked list is a palindrome.\n");
    } else {
        printf("The linked list is not a palindrome.\n");
    }
    return 0;
}