//INSERTION OF A NODE AT A PARTICULAR POSITION + DELETION FROM RIGHT

#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} sl;

sl *insertion(sl *, int *);
sl *deletion(sl *, sl *, int *);
void display(sl *, sl *);
sl *insertion_at_node(sl *, sl *, int *, int);

int main()
{
    sl *l = NULL, *r = NULL;
    int ch, n, c = 0;
    do
    {
        printf("\nEnter the following to do the desired operation:-\n");
        printf("\n1-Insertion\n2-Insert node at particular postion\n3-Deletion\n4-Display\n5-Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        printf("\n");
        switch (ch)
        {
        case 1:
        lmao:
            r = insertion(r, &c);
            if (l == NULL)
                l = r;
            break;

        case 2:
            printf("Enter postion at which node is to be inserted: ");
            scanf("%d", &n);
            if (n == c + 1)
                goto lmao;
            else
                l = insertion_at_node(l, r, &c, n);
            break;

        case 3:
            r = deletion(l, r, &c);
            if (r == NULL)
                l = r;
            break;

        case 4:
            display(l, r);
            break;

        case 5:
            printf("Thank you for using this program!!\n\n");
            exit(0);

        default:
            printf("Incorrect choice\n");
        }
    } while (ch != 5);
    return 0;
}

sl *insertion(sl *r, int *c)
{
    sl *p = NULL;
    int val;
    p = (sl *)malloc(sizeof(sl));
    if (p != NULL)
    {
        printf("Enter data: ");
        scanf("%d", &val);
        p->data = val;
        p->next = r;
        if (r != NULL)
            r->next = p;
        r = p;
        (*c)++;
    }
    else
        printf("Couldn't allocate memory\n");
    return r;
}

sl *insertion_at_node(sl *l, sl *r, int *c, int n)
{
    sl *p = NULL, *temp = NULL;
    int i = 1, val;
    if (n > (*c + 1))
        printf("Position not available\n");
    else
    {
        p = (sl *)malloc(sizeof(sl));
        if (p != NULL)
        {
            printf("Enter data: ");
            scanf("%d", &val);
            p->data = val;
            if (n == 1)
            {
                p->next = l;
                l = p;
            }
            else
            {
                temp = l;
                while (i < (n - 1))
                {
                    temp = temp->next;
                    i++;
                }
                p->next = temp->next;
                temp->next = p;
            }
            (*c)++;
        }
        else
            printf("Couldn't allocate memory\n");
    }
    return l;
}

sl *deletion(sl *l, sl *r, int *c)
{
    sl *p = NULL;
    if (r == NULL)
        printf("Linked list in empty\n");
    else
    {
        if (l == r)
        {
            printf("%d is deleted from the list\n", r->data);
            p = r;
            r = NULL;
        }
        else
        {
            printf("%d is deleted from the list\n", r->data);
            p = r;
            while (1)
            {
                if (l->next == r)
                {
                    r = l;
                    break;
                }
                else
                    l = l->next;
            }
        }
        (*c)--;
        free(p);
    }
    return r;
}

void display(sl *l, sl *r)
{
    if (r == NULL)
        printf("Linked list in empty\n");
    else
    {
        printf("Contents of the linked list are:-\n");
        while (l != r)
        {
            printf("%d ", l->data);
            l = l->next;
        }
        printf("%d\n", l->data);
    }
}