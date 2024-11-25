#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100
int enq(int[], int);
int deq(int[], int, int);
void display(int[], int, int);
void peek(int[], int);
bool isPalindrome(int[], int, int);
int main() {
    int queue[MAX], f = -1, r = -1, ch;
    do {
        printf("Enter 1 to enqueue\nEnter 2 to dequeue\nEnter 3 to display\nEnter 4 to peek\nEnter 5 to check palindrome\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                r = enq(queue, r);
                if (f == -1) f = 0; 
                break;
            case 2:
                f = deq(queue, f, r);
                if (f == -1) r = -1; 
                break;
            case 3:
                display(queue, f, r);
                break;
            case 4:
                peek(queue, f);
                break;
            case 5:
                if (isPalindrome(queue, f, r)) {
                    printf("The queue is a palindrome.\n");
                } else {
                    printf("The queue is not a palindrome.\n");
                }
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (ch <= 5);
    return 0;
}
int enq(int queue[], int r) {
    int ele;
    if (r == MAX - 1) {
        printf("Overflow\n");
    } else {
        printf("Enter element to enqueue: ");
        scanf("%d", &ele);
        r++;
        queue[r] = ele;
    }
    return r;
}
int deq(int queue[], int f, int r) {
    if (f == -1) {
        printf("Empty queue\n");
    } else if (f == r) {
        f = r = -1; 
    } else {
        f++;
    }
    return f;
}
void display(int queue[], int f, int r) {
    if (f == -1) {
        printf("Empty queue\n");
    } else {
        printf("Queue elements: ");
        for (int i = f; i <= r; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}
void peek(int queue[], int f) {
    if (f == -1) {
        printf("Empty queue\n");
    } else {
        printf("Front element: %d\n", queue[f]);
    }
}
bool isPalindrome(int queue[], int f, int r) {
    if (f == -1) return true; 
    int len = r - f + 1;
    int *stack = (int *)malloc(len * sizeof(int)); 
    int top = -1;
    for (int i = f; i <= r; i++) {
        stack[++top] = queue[i];
    }
    for (int i = f; i <= r; i++) {
        if (queue[i] != stack[top--]) {
            free(stack); 
            return false; 
        }
    }
    free(stack); 
    return true; 
}
