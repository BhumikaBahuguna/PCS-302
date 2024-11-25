//TWO STACK WITH THE HELP OF ONE ARRAY
#include <stdio.h>
#define MAX 100
int push1(int s[], int top1);
int pop1(int s[], int top1);
int push2(int s[], int top2);
int pop2(int s[], int top2);
void display(int s[], int top1, int top2);
int main() {
    int ch, s[MAX], top1 = -1, top2 = MAX;  // Changed to MAX for consistency
    do {
        printf("\n1: push1\n2: pop1\n3: push2\n4: pop2\n5: display\n0: exit\n");
        printf("Enter your choice :");
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                top1 = push1(s, top1);
                break;
            case 2:
                top1 = pop1(s, top1);
                break;
            case 3:
                top2 = push2(s, top2);
                break;
            case 4:
                top2 = pop2(s, top2);
                break;
            case 5:
                display(s, top1, top2);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while(ch != 0);
    return 0;
}
int push1(int s[], int top1) {
    int x;
    if(top1 == (MAX / 2) - 1) {
        printf("Stack 1 overflow\n");
    } else {
        top1++;
        printf("Input element to be pushed into stack 1: ");
        scanf("%d", &x);
        s[top1] = x;
    }
    return top1;
}
int pop1(int s[], int top1) {
    int x;
    if(top1 == -1) {
        printf("Stack 1 underflow\n");
    } else {
        x = s[top1];
        printf("Element popped from stack 1: %d\n", x);
        top1--;
    }
    return top1;
}
int push2(int s[], int top2) {
    int x;
    if(top2 == (MAX / 2)) {
        printf("Stack 2 overflow\n");
    } else {
        top2--;
        printf("Input element to be pushed into stack 2: ");
        scanf("%d", &x);
        s[top2] = x;
    }
    return top2;
}
int pop2(int s[], int top2) {
    int x;
    if(top2 == MAX) {
        printf("Stack 2 underflow\n");
    } else {
        x = s[top2];
        printf("Element popped from stack 2: %d\n", x);
        top2++;
    }
    return top2;
}
void display(int s[], int top1, int top2) {
    int i;
    printf("Displaying stack 1:\n");
    if(top1 == -1) {
        printf("Stack 1 is empty\n");
    } else {
        for(i = top1; i >= 0; i--) {
            printf("%d ", s[i]);
        }
        printf("\n");
    }
    
    printf("Displaying stack 2:\n");
    if(top2 == MAX) {
        printf("Stack 2 is empty\n");
    } else {
        for(i = top2; i < MAX; i++) {
            printf("%d ", s[i]);
        }
        printf("\n");
    }
}