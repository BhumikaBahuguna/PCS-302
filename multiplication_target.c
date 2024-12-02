/*
Q4. Write a C program to   create a single linked list, then find whether there exist any two nodes in the linked list whose multiplication is less than the target value.
Input: Linked-List=12->15->3->4->6,Target=20 || Output: Yes
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct linked_list 
{
    int data; // Data stored in the node
    struct linked_list *next; // Pointer to the next node
} ll;
ll* create(ll* head); // Creates a linked list
void check_multiplication(ll* head); 
void display(ll* head); // Displays the contents of the linked list
int main() 
{
    ll* head = NULL; // Initialize the head of the linked list to NULL
    int ch; // Variable to store the user's choice
    do
    {
        printf("\n\n-------Linked List Menu-------\n");
        printf("1-Create a linked list\n2-Check if any two nodes have ");
        printf("multiplication less than target\n3-Display Linked List\n");
        printf("4-Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        printf("\n");
        switch (ch) 
        {
            case 1: 
                head = create(head); // Create a linked list
                break;
            case 2:
                check_multiplication(head); // Check multiplication condition
                break;
            case 3:
                display(head); // Display the linked list
                break;
            case 4:
                printf("Exiting.......\n"); // Exit the program
                break;
            default:
                printf("Wrong choice!!\n"); // Handle invalid input
        }
    } 
    while (ch != 4); // Loop until the user chooses to exit
    return 0;
}
ll* create(ll* head) 
{
    int ch = 1; // Variable to control the loop
    ll *p = NULL, *r = head;
    while (ch) 
    {
        p = (ll*)malloc(sizeof(ll));
        if (p == NULL) 
        {
            printf("Memory not allocated\n");
            return head;
        }
        printf("Enter data: ");
        scanf("%d", &(p->data)); // Input data for the new node
        p->next = NULL; // Initialize the next pointer to NULL
        if (head == NULL)
            head = p;
        else
            r->next = p; // Link the new node to the previous node
        r = p; // Update the tail pointer to the new node
        printf("Enter any number to continue or 0 to stop: ");
        scanf("%d", &ch); // Check if the user wants to continue adding nodes
    }
    return head; // Return the updated head of the linked list
}
void check_multiplication(ll* head) 
{
    int target; // Target value for comparison
    ll* cur1 = NULL, *cur2 = NULL;
    if (head == NULL) 
        printf("Linked list is empty.\n");
    else
    {
        printf("Enter the target value: ");
        scanf("%d", &target);
        cur1 = head; // Start from the first node
        while (cur1 != NULL) 
        {
            cur2 = cur1->next; // Start from the next node
            while (cur2 != NULL) 
            {
                if (cur1->data * cur2->data < target)
                {
                    printf("Yes\n");
                    return; // Exit if condition is met
                }
                cur2 = cur2->next; // Move to the next node
            }
            cur1 = cur1->next; // Move to the next node
        }
        printf("No\n"); // Print "No" if no such pair is found
    }
}
void display(ll* head) //Display function to display list
{
    if (head == NULL) 
        printf("Linked List is empty!\n"); // Handle empty list
    else
    {
        printf("Contents of the linked list are:\n");
        while (head != NULL) 
        {
            printf("%d ", head->data); // Print the data in the current node
            head = head->next; // Move to the next node
        }
        printf("\n");
    }
}
