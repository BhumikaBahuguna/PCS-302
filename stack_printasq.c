//PRINT STACK AS QUEUE
#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    int data;
    struct stack *next;
} s;
s* push(s* tp);
s* pop(s* tp);
void displayAsQueue(s* tp);
int main() {
    s* top = NULL;
    int ch;

    do {
        printf("1 - Push\n2 - Pop\n3 - Display as Queue\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        
        switch (ch) {
            case 1:
                top = push(top);
                break;
            case 2:
                top = pop(top);
                break;
            case 3:
                displayAsQueue(top);
                printf("\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (ch <= 3);
    
    return 0;
}
s* push(s* tp) {
    s *p = (s*)malloc(sizeof(s));
    if (p != NULL) {
        int x;
        printf("Enter value to push: ");
        scanf("%d", &x);
        p->data = x;
        p->next = tp;
        tp = p;
    } else {
        printf("No memory\n");
    }
    return tp;
}

s* pop(s* tp) {
    s *p = NULL;
    if (tp == NULL) {
        printf("Stack is empty\n");
    } else {
        p = tp;
        printf("Popped node is %d\n", tp->data);
        tp = tp->next;
        free(p);
    }
    return tp;
}
void displayAsQueue(s* tp) {
    if (tp == NULL) return; 
    else{
    displayAsQueue(tp->next);
    printf("%d ", tp->data);
    }
}