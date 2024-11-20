//REVERSE WITHOUT RECURSION

#include<stdio.h>
#include<stdlib.h>
typedef struct linked_list
{
    int data;
    struct linked_list *next;
}ll;

ll* create(ll*);
ll* delete(ll*);
ll* reverse(ll*);
void display(ll*);

int main()
{
    ll* head =NULL;
    int ch;
    do
    {
        printf("\n\n-------Linked List Menu-------\n");
        printf("1-Create a linked list\n2-Delete node from Linked List\n3-Reverse the linked list\n");
        printf("4-Display Linked List\n5-Exit\n\nEnter your choice: ");
        scanf("%d",&ch);
        printf("\n");
        switch(ch)
        {
            case 1: head = create(head);
            break;

            case 2: head = delete(head);
            break;

            case 3: head=reverse(head);
            break;

            case 4: display(head);
            break;

            case 5: printf("Exiting.......\n");
            break;

            default: printf("Wrong choice!!\n");
        }
    } 
    while(ch!=5);
    return 0;
    
}

ll* create(ll *head)
{
    int ch=1;
    ll *p = NULL,*r=head;
    while(head!=NULL && r->next!=NULL)
        r=r->next;
    while(ch)
    {
        p = (ll*)malloc(sizeof(ll));
        if(p==NULL)
            printf("Memory not allocated\n");
        else
        {
            printf("\nEnter data: ");
            scanf("%d",&(p->data));
            p->next = NULL;
            if(head==NULL)
                head = p;
            else
                r->next = p;
            r=p;
        }
        printf("\nEnter any number to continue and 0 to stop: ");
        scanf("%d",&ch);
    }
    return head;
}

ll* reverse(ll* head)
{
    ll *prev=NULL,*nxt =NULL,*cur=head;
    if(head==NULL)
        printf("Linked List is empty!\n");
    else
    {
        while(cur!=NULL)
        {
            nxt = cur->next;
            cur->next = prev; 
            prev = cur;
            cur=nxt;  
        }
        printf("Reversed the linked list!\n");
    }
    return prev;
}

ll* delete(ll* head)
{
    ll* p = NULL;
    if(head==NULL)
        printf("Linked List is empty!\n");
    else
    {
        p=head;
        printf("Deleting %d from the linked list...\n",head->data);
        head=head->next;
        free(p);
    }
    return head;
}

void display(ll* head)
{
    if(head==NULL)
        printf("Linked List is empty!\n");
    else 
    {
        printf("Contents of the linked list are:-\n");
        while(head!=NULL)
        {
            printf("%d ",head->data);
            head=head->next;
        }
    }
}