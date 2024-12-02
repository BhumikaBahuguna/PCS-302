/*
Q2. Write a menu driven program to delete duplicate name (if any) in the single Link list. The information field of each node should contain name and noll no of students. 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct linked_list
{
    char name[50];               // Name of the student
    int roll_no;                 // Roll number of the student
    struct linked_list *next;    // Pointer to the next node in the linked list
} ll;

ll* create(ll*);                // Function to create a linked list
ll* delete_duplicates(ll*);     // Function to duplicate name nodes
void display(ll*);              // Function to display the linked list

int main()
{
    ll* head = NULL;            // Initialize the head pointer to NULL
    int ch;                      // Variable to store the user's choice
    do
    {
        // Display menu options for the user
        printf("\n\n-------Linked List Menu-------\n");
        printf("1-Create a linked list\n2-Delete duplicate names\n");
        printf("3-Display Linked List\n4-Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);        // Get user input for menu selection
        printf("\n");
        switch (ch)
        {
            case 1: 
                head = create(head);  // Create a linked list
                break;
            case 2: 
                head = delete_duplicates(head);  // Remove duplicate names
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
    ll *p = NULL, *r = head; 
    while (head != NULL && r->next != NULL)
        r = r->next;
    while (ch)
    {
        p = (ll*)malloc(sizeof(ll)); // Allocate memory for a new node
        if (p == NULL)
            printf("Memory not allocated\n"); // Memory allocation failed
        else
        {
            printf("\nEnter student name: ");
            scanf("%s", p->name);
            printf("Enter roll number: ");
            scanf("%d", &(p->roll_no));
            p->next = NULL; // Set the next pointer of the new node to NULL
            if (head == NULL)
                head = p;
            else
                r->next = p;  // Otherwise, link the new node to the last node
            r = p;  // Move the pointer r to the new node
        }
        printf("\nEnter any number to continue or 0 to stop: ");
        scanf("%d", &ch);
    }
    return head; // Return the updated head of the list
}

ll* delete_duplicates(ll* head)
{
    if (head == NULL)
        printf("Linked List is empty!\n");
    else
    {
        ll *current = head, *prev, *temp;
        while (current != NULL && current->next != NULL)
        {
            prev = current;        // Initialize previous pointer
            temp = current->next;  // Initialize temp pointer for comparison
            while (temp != NULL)
            {
                if (strcmp(current->name, temp->name) == 0)  // If names match
                {
                    printf("Deleting duplicate node with name '%s' and ");
	        printf("roll number %d.\n", temp->name, temp->roll_no);
                    prev->next = temp->next;  // Skip the duplicate node
                    free(temp);  // Free memory of the duplicate node
                    temp = prev->next;  // Move to the next node
                }
                else
                {
                    prev = temp;  // Move prev to temp
                    temp = temp->next;  // Move to the next node
                }
            }
            current = current->next;  // Move to the next node in the list
        }
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
            printf("Name: %s, Roll No: %d\n", head->name, head->roll_no);
            head = head->next;  // Move to the next node
        }
    }
}
