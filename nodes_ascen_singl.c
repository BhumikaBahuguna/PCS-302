//PRINT NODES IN ASCENDING ORDER

#include <stdio.h>
#include <stdlib.h>
typedef struct list
{
    int data;
    struct list *next;
    struct list *prev;
} ll;

ll *insertion(ll *, ll *);
ll *deletion(ll *);
void display(ll *);
int main()
{
    ll *l = NULL, *r = NULL, *w = NULL;
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
            w = insertion(l, r);
            if (l == NULL)
                l = r = w;
            else if (w->prev == NULL)
                l = w;
            else if (w->next == NULL)
                r = w;
            break;
        case 2:
            l = deletion(l);
            if (l == NULL)
                r = l;
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

ll *insertion(ll *l, ll *r)
{
    ll *p = NULL, *t = NULL, *w = NULL;
    p = (ll *)malloc(sizeof(ll));
    if (p == NULL)
    {
        printf("Couldn't Allocate Memory!\n");
        return NULL;
    }
    else
    {
        printf("Enter data: ");
        scanf("%d", &(p->data));
        p->prev = NULL;
        p->next = NULL;

        if (r == NULL)
        {
            w = p;
        }
        else if (p->data <= l->data)
        {
            p->next = l;
            l->prev = p;
            w = p;
        }
        else if (p->data >= r->data)
        {
            p->prev = r;
            r->next = p;
            w = p;
        }
        else
        {
            t = l;
            while (t->data < p->data)
                t = t->next;

            p->next = t;
            p->prev = t->prev;
            t->prev->next = p;
            t->prev = p;
            w = l;
        }
    }
    return w;
}

ll *deletion(ll *l)
{
    ll *p = NULL;
    if (l == NULL)
        printf("Linked List in empty!\n");
    else
    {
        p = l;
        printf("%d is removed from the linked list\n", l->data);
        l = l->next;
        if (l != NULL)
            l->prev = NULL;
        free(p);
    }
    return l;
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
        } while (l != NULL || !(printf("\n")));
    }
}