//DISPALY DOUBLE LL WITHOUT OVERLAPPING
#include <stdio.h>
#include <stdlib.h>
typedef struct list
{
    int data;
    struct list *next;
    struct list *prev;
} ll;

ll* insertion(ll *);
ll* deletion(ll *);
void display(ll *,ll*);
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
            r=insertion(r);
            if(l==NULL)
                l=r;
            break;
        case 2:
            l=deletion(l);
            if(l==NULL)
                r=l;
            break;

        case 3:
            display(l,r);
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
ll* insertion(ll *r)
{
    ll *p = NULL;
    p = (ll *)malloc(sizeof(ll));
    if (p == NULL)
        printf("Couldn't Allocate Memory!\n");
    else
    {
        printf("Enter data: ");
        scanf("%d", &(p->data));
        if (r == NULL)
            p->prev = NULL;
        else
        {
            r->next=p;
            p->prev=r;
        }
        r=p;
        r->next = NULL;
    }
    return r;
}

ll* deletion(ll *l)
{
    ll *p = NULL;
    if (l == NULL)
        printf("Linked List in empty!\n");
    else
    {
        p = l;
        printf("%d is removed from the linked list\n", l->data);
        l=l->next;
            if(l!=NULL)
                l->prev=NULL;
        free(p);
    }
    return l;
}

void display(ll *l,ll* r)
{
    if (l == NULL)
        printf("Linked List is empty!\n");
    else
    {
        printf("Contents of the linked list are:-\n");
        while(1)
        {
            printf("%d ",l->data);
            if(l==r)
                break;
            printf("%d ",r->data);
            l=l->next;
            if(l==r)
                break;
            r=r->prev;
        }
        printf("\n");
    }
}