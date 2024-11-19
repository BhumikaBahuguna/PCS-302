//DOUBLE LL USING DOUBLE POINTER

#include <stdio.h>
#include <stdlib.h>
typedef struct list
{
    int data;
    struct list *next;
    struct list *prev;
} ll;

void insertion(ll **,ll **);
void deletion(ll **,ll **);
void display(ll *);
int main()
{
    ll *l = NULL, *r = NULL;
    int ch;
    do
    {
        printf("\nPress the certain keys to do the desired operation:-\n");
        printf("1-Insert\n2-Delete\n3-Display\n4-Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        printf("\n");
        switch (ch)
        {
        case 1:
            insertion(&l,&r);
            break;
        case 2:
            deletion(&l,&r);
            break;

        case 3:
            display(l);
            break;

        case 4:
            printf("Thank you for using this program!!\n");
            break;

        default:
            printf("Wrong choice\n");
        }
    } while (ch != 4);
    return 0;
}

void insertion(ll **l,ll **r)
{
    ll *p = NULL;
    p = (ll *)malloc(sizeof(ll));
    if (p == NULL)
        printf("Couldn't Allocate Memory!\n");
    else
    {
        printf("Enter data: ");
        scanf("%d", &(p->data));
        if (*r == NULL)
        {
            p->prev = NULL;
            *l=p;
        }
        else
        {
            (*r)->next=p;
            p->prev=*r;
        }
        *r=p;
        (*r)->next = NULL;
    }
}

void deletion(ll **l,ll **r)
{
    ll *p = NULL;
    if (*l == NULL)
        printf("Linked List in empty!\n");
    else
    {
        p = *l;
        printf("%d is removed from the linked list\n", (*l)->data);
        *l=(*l)->next;  
            if(*l!=NULL)
                (*l)->prev=NULL;
            else
                *r=NULL;
        free(p);
    }
}

void display(ll *l)
{
    ll *p = l;
    if (l == NULL)
        printf("Linked List is empty!\n");
    else
    {
        printf("Contents of the linked list are:-\n");
        do
        {
            printf("%d ", l->data);
            l = l->next;
        } while (l != NULL);
    }
}