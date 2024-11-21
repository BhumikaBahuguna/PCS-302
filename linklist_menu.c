#include<stdio.h>
#include<stdlib.h>
typedef struct linked_list
{
    int data;
    struct linked_list *next;
}sl;

sl* insertion(sl*);
sl* insert_before_first_node(sl*);
void insert_after_first_node(sl*);
sl* insert_after_last_node(sl*);
sl* insert_before_last_node(sl*,sl*);
sl* deletion(sl*,sl*,int);
void display(sl*,sl*);
void node_count(sl*,sl*,int);

int main()
{
    sl *l=NULL,*r=NULL;
    int ch,count;
    do
    {
        printf("\nEnter the following to do the desired operation:-\n");
        printf("\n1-Insertion\n2-Insert before first node\n3-Insert after first node\n4-Insert after last node\n5-Insert before last node\n6-Deletion from LHS\n7-Deletion from RHS\n8-Display\n9-Count nodes\n10-Count even nodes\n11-Count odd nodes\n12-Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        printf("\n");
        switch(ch)
        {
            case 1: r=insertion(r);
                if(l==NULL)
                    l=r;
                break;

            case 2: l=insert_before_first_node(l);
                break;
            
            case 3: insert_after_first_node(l);
                break;
            
            case 4:r=insert_after_last_node(r);
                break;

            case 5: 
                if(l==r)
                    l=insert_before_last_node(l,r);
                else 
                    r=insert_before_last_node(l,r);
                break;

            case 6: l=deletion(l,r,1);
                if(l==NULL)
                    r=l;
                break;

            case 7: r=deletion(l,r,2);
                if(r==NULL)
                    l=r;
                break;

            case 8: display(l,r);
                break;

            case 9: node_count(l,r,1);
                break;

            case 10: node_count(l,r,2);
                break;

            case 11: node_count(l,r,3);
                break;
            
            case 12: printf("Thank you for using this program!!\n\n");
                exit(0);
                
            default: printf("Incorrect choice\n");
        }
    } 
    while(ch!=12);
    return 0;
}

sl* insertion(sl* r)
{
    sl *p = NULL;
    int val;
    p = (sl*)malloc(sizeof(sl));
    if(p!=NULL)
    {
        printf("Enter data: ");
        scanf("%d",&val);
        p->data = val;
        p->next=r;
        if(r!=NULL)
            r->next=p;
        r=p;
    }
    else
        printf("Couldn't allocate memory\n");
    return r;
}

sl* insert_before_first_node(sl *ptr)
{
	int v;
	sl *p = NULL;
    if(ptr!=NULL)
    {
        p=(sl*)malloc(sizeof(sl));
	    printf("Enter data: ");
	    scanf("%d",&v);
	    p->data=v;
	    p->next=ptr;
	    ptr=p;
    }
	else
        printf("No node present in the linked list\n");
	return ptr;
}

void insert_after_first_node(sl *ptr)
{
	int v;
	sl *p = NULL;
    if(ptr!=NULL)
    {
        p=(sl*)malloc(sizeof(sl));
	    printf("Enter data: ");
	    scanf("%d",&v);
	    p->data=v;
	    p->next=ptr->next;
	    ptr->next=p;
    }
	else
        printf("No node present in the linked list\n");
}

sl* insert_after_last_node(sl *ptr)
{
	int v;
	sl *p = NULL , *t=NULL;
    if(ptr!=NULL)
    {
        p=(sl*)malloc(sizeof(sl));
	    printf("Enter data: ");
	    scanf("%d",&v);
	    p->data=v;
        ptr->next=p;
        ptr=p;
    }
	else
        printf("No node present in the linked list\n");
    return ptr;
}

sl* insert_before_last_node(sl *l,sl *r)
{
	int v;
	sl *p = NULL;
    if(r!=NULL)
    {
        p=(sl*)malloc(sizeof(sl));
	    printf("Enter data: ");
	    scanf("%d",&v);
	    p->data=v;
        p->next=r;
	    if(l==r)
        {
            l=p;
            return l;
        }   
        else
        {
            while(1)
            {
                if(l->next==r)
                {
                    l->next=p;
                    break;
                }
                else
                    l=l->next;
            }
            return r;
        }
    }
	else
        printf("No node present in the linked list\n");
	return r;
}

void display(sl* l,sl* r)
{
    if(r==NULL)
        printf("Linked list in empty\n");
    else
    {
        printf("Contents of the linked list are:-\n");
        while(l!=r)
        {
            printf("%d ",l->data);
            l=l->next;
        }
        printf("%d\n",l->data);
    }
}

sl* deletion(sl* l,sl* r,int n)
{
    char c;
    sl* p=NULL;
    if(r==NULL)
        printf("Linked list in empty\n");
    else
    {
        if(l==r)
        {
            printf("%d is deleted from the list\n",r->data);
            p=r;
            r=NULL;
        }
        else if(n==1)
        {
            printf("%d is deleted from the list\n",l->data);
            p=l;
            r=l->next;
        }
        else
        {
            printf("%d is deleted from the list\n",r->data);
            p=r;
            while(1)
            {
                if(l->next==r)
                {
                    r=l;
                    break;
                }
                else
                    l=l->next;
            }
        }
        free(p);
    }
    return r;
    
}

void node_count(sl* l,sl* r,int n)
{
    int c=1,even,odd;
    if(r==NULL)
        c=0;
    else
    {
        while(l!=r)
        {
            c++;
            l=l->next;
        }
            even=c/2;
            odd=c-even;
        if(n==2)
            c=even;
        else if(n==3)
            c=odd;
    }
    printf("Number of nodes in the linked list is %d\n",c);
}