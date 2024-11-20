//INSERT NEW NODE BETWEEN FIRST AND LAST NODE OF A DOUBLE LINKED LIST

#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    int data;
    struct list *next;
    struct list *prev;
} ll;

void insertion(ll **, ll **);
void deletion(ll **, ll **);
void display(ll *);
void insertBetween(ll **, ll **);

int main() {
    ll *l = NULL, *r = NULL;
    int ch;
    do {
        printf("\nPress the certain keys to do the desired operation:\n");
        printf("1-Insert\n2-Delete\n3-Display\n4-Insert Between\n5-Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        printf("\n");
        switch (ch) {
            case 1:
                insertion(&l, &r);
                break;
            case 2:
                deletion(&l, &r);
                break;
            case 3:
                display(l);
                break;
            case 4:
                insertBetween(&l, &r);
                break;
            case 5:
                printf("Thank you for using this program!\n");
                break;
            default:
                printf("Wrong choice\n");
        }
    } while (ch != 5);
    return 0;
}

void insertion(ll **l, ll **r) {
    ll *p = (ll *)malloc(sizeof(ll));
    if (p == NULL) {
        printf("Couldn't Allocate Memory!\n");
    } else {
        printf("Enter data: ");
        scanf("%d", &(p->data));
        p->next = NULL;
        if (*r == NULL) { // List is empty
            p->prev = NULL;
            *l = p;
        } else { // List is not e1mpty
            (*r)->next = p;
            p->prev = *r;
        }
        *r = p;
    }
}

void deletion(ll **l, ll **r) {
    if (*l == NULL) {
        printf("Linked List is empty!\n");
        return;
    }
    ll *p = *l;
    printf("%d is removed from the linked list\n", (*l)->data);
    *l = (*l)->next;  
    if (*l != NULL) {
        (*l)->prev = NULL;
    } else {
        *r = NULL;
    }
    free(p);
}

void display(ll *l) {
    if (l == NULL) {
        printf("Linked List is empty!\n");
        return;
    }
    printf("Contents of the linked list are:\n");
    while (l != NULL) {
        printf("%d ", l->data);
        l = l->next;
    }
    printf("\n");
}

void insertBetween(ll **l, ll **r) {
    if (*l == NULL || *l == *r|| (*l)->next == NULL) { // Less than 2 nodes
        printf("Cannot insert between. The list must have at least 2 nodes.\n");
        return;
    }

    ll *newNode = (ll *)malloc(sizeof(ll));
    if (newNode == NULL) {
        printf("Couldn't Allocate Memory!\n");
        return;
    }
    
    printf("Enter data for the new node: ");
    scanf("%d", &(newNode->data));

    // Inserting between first and last
    newNode->prev = *l; // Previous of new node points to first node
    newNode->next = (*r)->prev; // Next of new node points to second last node
    if ((*r)->prev != NULL) {
        (*r)->prev->next = newNode; // Update the second last node's next
    }
    (*l)->next = newNode; // Update the first node's next
    (*r)->prev = newNode; // Update the last node's prev

    printf("Node with data %d inserted between first and last nodes.\n", newNode->data);
}
