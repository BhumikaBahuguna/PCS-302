//IMPLEMENT STACK FROM DEQUEUE

#include <stdio.h>
#define MAX 10

int enq(int[], int);                // INSERTION AT REAR END
int frontdeq(int[], int, int);     // DELETION FROM FRONT
int frontenq(int[], int);          // INSERTION AT FRONT
void display(int[], int, int);      // TO DISPLAY
void peek(int[], int);              // TO PEEK

// Stack operations
int push(int[], int);
int pop(int[], int);
int stackPeek(int[], int);

int main() {
    int dq[MAX], f = -1, r = -1, ch;
    do {
        printf("Enter 1 to push\nEnter 2 to pop\nEnter 3 to display stack\nEnter 4 to peek\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        
        switch (ch) {
            case 1:
                r = push(dq, r);
                if (r == 0) f = 0; // If the first element is added, set front
                break;
            case 2:
                r = pop(dq, r);  // Reset if the stack is empty
                if (r == -1) 
                    f = -1; // Stack is empty after pop
                break;
            case 3:
                display(dq, f, r);
                break;
            case 4:
                stackPeek(dq, f);
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (ch <= 4);
    return 0;
}

int enq(int dq[], int r) {
    int ele;
    if (r == MAX - 1) {
        printf("Overflow\n");
    } else {
        printf("Enter element to enqueue: ");
        scanf("%d", &ele);
        r++;
        dq[r] = ele;
    }
    return r;
}

int frontenq(int dq[], int f) {
    int ele;
    if (f == 0) {
        printf("Overflow\n");
    } else if (f > 0) {
        f--;
        printf("Enter element to enqueue: ");
        scanf("%d", &ele);
        dq[f] = ele;
    }
    return f;
}

int frontdeq(int dq[], int f, int r) {
    int x;
    if (f == -1) {
        printf("Empty queue\n");
    } else {
        x = dq[f];
        printf("Dequeued element is %d\n", x);
        if (f == r) {
            f = r = -1;
        } else {
            f++;
        }
    }
    return f;
}

void display(int dq[], int f, int r) {
    int i;
    if (f == -1) {
        printf("Empty queue\n");
    } else {
        for (i = f; i <= r; i++) {
            printf("%d ", dq[i]);
        }
        printf("\n");
    }
}

void peek(int dq[], int f) {
    if (f == -1) {
        printf("Empty queue\n");
    } else {
        printf("%d\n", dq[f]);
    }
}

int push(int dq[], int r) {
    return enq(dq, r); // Push operation
}

int pop(int dq[], int r) {
    if (r == -1) {
        printf("Stack underflow\n");
        return -1;
    } else {
        int poppedElement = dq[r];
        printf("Popped element is %d\n", poppedElement);
        return r-1; // Return new rear
    }
}

int stackPeek(int dq[], int r) {
    if (r == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Top element is %d\n", dq[r]);
    }
}
