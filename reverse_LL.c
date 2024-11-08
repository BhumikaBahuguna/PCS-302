//DISPLAY LL IN REVERSEE ORDER(NON TAIL)

#include <stdio.h>
#include <stdlib.h>
typedef struct list {
    int data;
    struct list *next;
} sl;
sl* insert(sl* );
void display(sl* );
sl* reverse(sl* );


int main() {
    sl* l = NULL;
    l = insert(l);
    printf("Original Linked List:\n");
    display(l);
    l = reverse(l);
    printf("Reversed Linked List:\n");
    display(l);
    return 0;
}
sl* insert(sl* l) {
    int c, v;
    while (1) {
        sl *p = NULL;
        sl *r = NULL;
        p = (sl*)malloc(sizeof(sl));
        if (p == NULL) {
            printf("Memory allocation failed\n");
            return l;
        }
        printf("Enter value to insert: ");
        scanf("%d", &v);
        p->data = v;
        p->next = NULL;
        if (l == NULL) {
            l = p;
        } else {
            r = l;
            while (r->next != NULL) {
                r = r->next;
            }
            r->next = p;
        }
        printf("Enter 1 to continue and 0 to stop: ");
        scanf("%d", &c);
        if (c == 0) {
            break;
        }
    }
    return l;
}
void display(sl* l) {
    if (l == NULL) {
        printf("Empty linked list\n");
        return;
    }
    sl *t = l;
    while (t != NULL) {
        printf("%d -> ", t->data);
        t = t->next;
    }
    printf("NULL\n");
}
sl* reverse(sl* l) {
    if (l == NULL || l->next == NULL) {
        return l;
    }
    sl* newl = reverse(l->next);
    sl* front = l->next;
    front->next = l;
    l->next = NULL;
    return newl;
}

