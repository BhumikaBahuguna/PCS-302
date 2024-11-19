//DELETE LAST NODE OF DOUBLE LINKED LIST
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} ll;

void insertion(ll **, ll **);
void deleteLastNode(ll **, ll **);
void printList(ll *l);

int main() {
    ll *l= NULL;
    ll *r = NULL;
int ch;
    do
    {
        printf("\nPress the certain keys to do the desired operation:-\n");
        printf("1-Insert\n2-Delete last node\n3-Display\n4-Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        printf("\n");
        switch (ch)
        {
        case 1:
            insertion(&l,&r);
            break;
        case 2:
            deleteLastNode(&l,&r);
            break;

        case 3:
            printList(l);
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
    ll *p = (ll *)malloc(sizeof(ll));
    if (p == NULL) {
        printf("Couldn't Allocate Memory!\n");
    } else {
        printf("Enter data: ");
        scanf("%d", &(p->data));
        if (*r == NULL) { // List is empty
            p->prev = NULL;
            *l = p;
        } else { // List is not empty
            (*r)->next = p;
            p->prev = *r;
        }
        *r = p;
        (*r)->next = NULL; // New node is now the last node
    }
}
void deleteLastNode(ll **l, ll **r) {
    if (*r == NULL) {
        printf("The list is empty. No node to delete.\n");
        return;
    }

    ll *temp = *r; // Pointer to the last node

    if (*l == *r) { // Only one node in the list
        *l = NULL;
        *r = NULL;
    } else {
        *r = (*r)->prev; // Move the tail pointer to the previous node
        (*r)->next = NULL; // Set the next of the new last node to NULL
    }

    free(temp); // Free the last node
    printf("Last node deleted successfully.\n");
}

void printList(ll *l) {
    while (l != NULL) {
        printf("%d ", l->data);
        l = l->next;
    }
    printf("\n");
}

