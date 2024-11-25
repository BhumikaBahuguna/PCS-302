//IMPLEMENTING QUEUE USING DEQUEUE

#include <stdio.h>
#define MAX 10

int enq(int[], int);                // INSERTION AT END
int frontdeq(int[], int, int);     // DELETION FROM FRONT
void display(int[], int, int);      // TO DISPLAY
void peek(int[], int);              // TO PRINT FIRST ELEMENT

int main() {
    int dq[MAX], f = -1, r = -1, ch;
    do {
        printf("Enter 1 to enqueue\nEnter 2 to dequeue from front\nEnter 3 to display\nEnter 4 to peek\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                r = enq(dq, r);
                if (f == -1) f = 0; // If the first element is added, set front
                break;
            case 2:
                f = frontdeq(dq, f, r);
                if (f == -1) r = -1; // Reset if the queue is empty
                break;
            case 3:
                display(dq, f, r);
                break;
            case 4:
                peek(dq, f);
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

int frontdeq(int dq[], int f, int r) {
    int x;
    if (f == -1) {
        printf("Empty queue\n");
    } else {
        x = dq[f];
        printf("Dequeued element from front is %d\n", x);
        if (f == r) {
            f = r = -1; // Reset if the queue becomes empty
        } else {
            f++;
        }
    }
    return f;
}

void display(int dq[], int f, int r) {
    if (f == -1) {
        printf("Empty queue\n");
    } else {
        printf("Queue elements: ");
        for (int i = f; i <= r; i++) {
            printf("%d ", dq[i]);
        }
        printf("\n");
    }
}

void peek(int dq[], int f) {
    if (f == -1) {
        printf("Empty queue\n");
    } else {
        printf("Front element is %d\n", dq[f]);
    }
}
