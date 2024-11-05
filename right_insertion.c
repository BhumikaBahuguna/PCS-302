//TO INSERT NODES AT RIGHT
#include <stdio.h>
#include <stdlib.h>
typedef struct list {
    int data;
    struct list *next;
} sl;
int main() {
    sl *l = NULL; // Initialize the head of the list to NULL
    sl *t = NULL; // Temporary pointer for traversing
    sl *r = NULL; // Pointer to keep track of the last node
    int ch, v, c = 0;
    while (1) {
        sl * p = (sl*)malloc(sizeof(sl));
        if (p!=NULL) {
        printf("input data: ");
        scanf("%d", &v);
        p->data = v;
        p->next = NULL;} // Initialize next to NULL
        // Append new node to the end of the list
        if (l == NULL) {
            // If the list is empty, new node becomes the head
            l = p;
        } else {
            // Traverse to the end of the list and append the new node
            r=l;
            while(r->next!=NULL){
                r=r-> next;}
            r->next = p;
        }
        // Ask user whether to continue or stop
        printf("enter 1 to continue and 0 to stop: ");
        scanf("%d", &ch);
        if (ch == 0) break;
    }
    // Print the list
    t = l;
    while (t != NULL) {
        printf("%d  ", t->data);
        t = t->next;
    }
    return 0;
}