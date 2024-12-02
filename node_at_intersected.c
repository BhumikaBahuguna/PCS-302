/*
Q5. Write a C program to find the node in the double linked list , at which the two linked list are intersected.
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct doubly_linked_list 
{
    int data;
    struct doubly_linked_list* prev;
    struct doubly_linked_list* next;
} dll;
dll* create(dll* head);
dll* create_intersection(dll* head1, dll* head2);
dll* find_intersection(dll* head1, dll* head2);
void display(dll* head);
int main() 
{
    dll* list1 = NULL;
    dll* list2 = NULL;
    dll* intersection = NULL;
    int choice;
    do
    {
        printf("\n\n-------Doubly Linked List Menu-------\n");
        printf("1-Create List 1\n2-Create List 2\n");
        printf("3-Create Intersection\n4-Find Intersection\n");
        printf("5-Display List 1\n6-Display List 2\n7-Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice) 
        {
            case 1:
                list1 = create(list1);
                break;
            case 2:
                list2 = create(list2);
                break;
            case 3:
                list2 = create_intersection(list1, list2);
                break;
            case 4:
                intersection = find_intersection(list1, list2);
                if (intersection != NULL)
                    printf("Lists intersect at node: %d\n", intersection->data);
                else
                    printf("Lists do not intersect.\n");
                break;
            case 5:
                printf("List 1: ");
                display(list1);
                break;
            case 6:
                printf("List 2: ");
                display(list2);
                break;
            case 7:
                printf("Exiting.......\n");
                break;
            default:
                printf("Wrong choice!!\n");
        }
    } 
    while (choice != 7);
    return 0;
}

dll* create(dll* head) 
{
    int data, cont = 1;
    dll *new_node, *tail = head;
    while (cont) 
    {
        new_node = (dll*)malloc(sizeof(dll));
        if (!new_node) 
        {
            printf("Memory not allocated.\n");
            return head;
        }
        printf("Enter data: ");
        scanf("%d", &data);
        new_node->data = data;
        new_node->next = NULL;
        new_node->prev = NULL;
        if (head == NULL)
            head = new_node;
        else
            tail->next = new_node;
        tail = new_node;
        printf("Enter any number to continue or 0 to stop: ");
        scanf("%d", &cont);
    }
    return head;
}

dll* create_intersection(dll* head1, dll* head2) 
{
    if (!head1 || !head2) 
    {
        printf("Both lists must be non-empty to create an intersection.\n");
        return head2;
    }
    int position;
    dll *temp1 = head1, *temp2 = head2;
    printf("Enter the position in List 1 for intersection: ");
    scanf("%d", &position);
    for (int i = 1; i < position && temp1; i++)
        temp1 = temp1->next;
    if (!temp1) 
    {
        printf("Invalid position. Intersection not created.\n");
        return head2;
    }
    while (temp2->next)
        temp2 = temp2->next;
    temp2->next = temp1;
    temp1->prev = temp2;
    printf("Intersection created at node with data: %d\n", temp1->data);
    return head2;
}
dll* find_intersection(dll* head1, dll* head2) 
{
    dll *temp1 = head1, *temp2 = head2;
    int len1 = 0, len2 = 0;
    while (temp1) 
    {
        len1++;
        temp1 = temp1->next;
    }
    while (temp2) 
    {
        len2++;
        temp2 = temp2->next;
    }
    temp1 = head1;
    temp2 = head2;
    if (len1 > len2) 
    {
        for (int i = 0; i < len1 - len2; i++)
            temp1 = temp1->next;
    } 
    else if (len2 > len1) 
    {
        for (int i = 0; i < len2 - len1; i++)
            temp2 = temp2->next;
    }
    while (temp1 && temp2) 
    {
        if (temp1 == temp2)
            return temp1;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return NULL; // No intersection
}

void display(dll* head) 
{
    if (!head) 
    {
        printf("List is empty!\n");
        return;
    }
    dll* temp = head;
    while (temp) 
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

