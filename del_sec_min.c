#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct linked_list
{
    int data;                     // Data value of the node
    struct linked_list *next;      // Pointer to the next node in the linked list
} ll;

ll* create(ll*);                  // Function to create a linked list
ll* delete_second_min(ll*);       // Function to delete the node with second minimum data
void display(ll*);                // Function to display the linked list

int main()
{
    ll* head = NULL;              // Initialize the head pointer to NULL
    int ch;                        // Variable to store the user's choice
    do
    {
        printf("\n\n-------Linked List Menu-------\n");
        printf("1-Create a linked list\n2-Delete node with second");
        printf("minimum data\n3-Display Linked List\n4-Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);          // Get user input for menu selection
        printf("\n");
        switch (ch)
        {
            case 1: 
                head = create(head);  // Create a linked list
                break;
            case 2: 
                head = delete_second_min(head);  // Delete second min node
                break;
            case 3: 
                display(head);        // Display the linked list
                break;
            case 4: 
                printf("Exiting.......\n");  // Exit the program
                break;
            default: 
                printf("Wrong choice!!\n");  // Invalid choice
        }
    } 
    while (ch != 4);  // Repeat until the user selects exit (option 4)
    return 0;
}

ll* create(ll *head)
{
    int ch = 1;           // Variable to control the loop for creating nodes
    ll *p = NULL, *r = head; // Temporary pointer to traverse the list 
    while (ch)
    {
        p = (ll*)malloc(sizeof(ll)); // Allocate memory for a new node
        if (p == NULL)
        {
            printf("Memory not allocated\n"); // Memory allocation failed
            return head;
        }
        printf("\nEnter data: ");
        scanf("%d", &(p->data));   // Get data for the new node
        p->next = NULL;             // Set the next pointer to NULL
        if (head == NULL)
            head = p;
        else
            r->next = p;  // Otherwise, link the new node to the last node
        r = p;  // Move the pointer r to the new node
        printf("\nEnter any number to continue or 0 to stop: ");
        scanf("%d", &ch);
    }
    return head; // Return the updated head of the list
}

ll* delete_second_min(ll* head)
{
    if (head == NULL || head->next == NULL)
    {
        printf("List Doesn’t have enough nodes to delete\n");
        return head;
    }
    int smallest = INT_MAX, ssmallest = INT_MAX;
    ll* cur = head;              // Pointer to traverse the list
    ll* prev = NULL, *sprev = NULL, *ssprev = NULL;
    while (cur != NULL)
    {
        if (cur->data < smallest)  // If current data is smaller than smallest
        {
            ssmallest = smallest;  // Update second smallest
            ssprev = sprev;        // Update second smallest node
            smallest = cur->data; // Update smallest data
            sprev = prev;         // Update smallest node's previous pointer
        }
        else if (cur->data < ssmallest && cur->data > smallest)
        {
            ssmallest = cur->data;  // Update second smallest
            ssprev = prev;          // Update second smallest node’s pointer
        }
        prev = cur;  // Move prev pointer to the current node
        cur = cur->next;  // Move to the next node
    }

    if (ssmallest == INT_MAX)
        printf("No distinct elements to determine second minimum.\n");
    else
    {
        cur = NULL;
        if (ssprev != NULL)
        {
            cur = ssprev->next;       // Second smallest node to be deleted
            ssprev->next = ssprev->next->next;
        }
        else  // If second smallest node is the head, remove the head
        {
            cur = head;
            head = head->next;  // Move the head pointer to the next node
        }
        printf("Deleting second smallest node with data: %d\n", cur->data);
        free(cur);  // Free the memory of the deleted node
    }
    return head; // Return the updated head of the list
}

void display(ll* head)
{
    if (head == NULL)
        printf("Linked List is empty!\n");
    else
    {
        printf("Contents of the linked list are:\n");
        while (head != NULL)
        {
            printf("%d ", head->data);
            head = head->next;  // Move to the next node
        }
        printf("\n");
    }
}
