#include<stdio.h>
#include<stdlib.h>

typedef struct linked_list
{
    int data;                  // Data stored in the node
    struct linked_list *next;  // Pointer to the next node
} ll;

ll* create(ll*);            // Function to create a linked list
ll* delete(ll*);            // Function to delete a node from the linked list
ll* reverse(ll*);           // Function to reverse the linked list
void display(ll*);          // Function to display the linked list

int main()
{
    ll* head = NULL; // Initialize the head of the linked list as NULL
    int ch;          // Variable to store user choice
    do
    {
        printf("\n\n-------Linked List Menu-------\n");
        printf("1-Create a linked list\n2-Delete node from Linked List\n");
        printf("3-Reverse the linked list\n");
        printf("4-Display Linked List\n5-Exit\n\nEnter your choice: ");
        scanf("%d",&ch); // Get user input for menu selection
        printf("\n");
        switch(ch)
        {
            case 1: 
                head = create(head);  // Create a linked list
                break;
            case 2: 
                head = delete(head);  // Delete a node from the linked list
                break;
            case 3: 
                head = reverse(head); // Reverse the linked list
                break;
            case 4: 
                display(head);        // Display the linked list
                break;
            case 5: 
                printf("Exiting.......\n");  // Exit the program
                break;
            default: 
                printf("Wrong choice!!\n");  // Invalid choice
        }
    } 
    while(ch != 5);  // Repeat until the user selects exit (option 5)
    return 0;
}

ll* create(ll *head)
{
    int ch = 1;           // Variable to control the loop for creating nodes
    ll *p = NULL, *r = head; // Temporary pointer to traverse the list
    while(head != NULL && r->next != NULL)
        r = r->next;
    while(ch)  // Loop to keep adding nodes until the user chooses to stop
    {
        p = (ll*)malloc(sizeof(ll)); // Allocate memory for a new node
        if(p == NULL)
            printf("Memory not allocated\n"); // Memory allocation failed
        else
        {
            printf("\nEnter data: ");
            scanf("%d",&(p->data)); // Get data for the new node
            p->next = NULL; // New node's next is NULL

            if(head == NULL)  // If list is empty, the new node becomes head
                head = p;
            else
                r->next = p;  // Otherwise, link the new node to the last node    
            r = p;  // Move the pointer r to the new node
        }
        printf("\nEnter any number to continue and 0 to stop: ");
        scanf("%d",&ch);  // Ask the user if they want to continue
    }
    return head; // Return the updated head of the list
}

ll* reverse(ll* head)
{
    ll *prev = NULL, *nxt = NULL, *cur = head; // Initialize pointer to rev
    if(head == NULL)
        printf("Linked List is empty!\n");  // Check if the list is empty
    else
    {
        while(cur != NULL)  // Traverse the list and reverse the pointers
        {
            nxt = cur->next;   // Save the next node
            cur->next = prev;  // Reverse the current node's next pointer
            prev = cur;        // Move the prev pointer to the current node
            cur = nxt;         // Move to the next node
        }
        printf("Reversed the linked list!\n");
    }
    return prev; // Return the new head of the reversed list
}

ll* delete(ll* head)
{
    ll* p = NULL;
    if(head == NULL)
        printf("Linked List is empty!\n");  // Check if the list is empty
    else
    {
        p = head;  // Save the head node to free it later
        printf("Deleting %d from the linked list...\n", head->data); // Show the data being deleted
        head = head->next; // Move the head pointer to the next node
        free(p);  // Free the memory of the old head node
    }
    return head;  // Return the updated head of the list
}

void display(ll* head)
{
    if(head == NULL)
        printf("Linked List is empty!\n");  // Check if the list is empty
    else 
    {
        printf("Contents of the linked list are:-\n");
        while(head != NULL)  // Traverse and print each node's data
        {
            printf("%d ", head->data);
            head = head->next;  // Move to the next node
        }
    }
}
