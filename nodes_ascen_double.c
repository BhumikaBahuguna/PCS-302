//NODES ASCENDING USING LL DOUBLE POINTER

#include <stdio.h>
#include <stdlib.h>
typedef struct list
{
    int data;
    struct list *next;
    struct list *prev;
} dl;
void asc_nodes(dl**,dl**);
void display(dl*);
int main()
{
dl* l=NULL,*r=NULL;
int ch;
do
{
printf("enter 1:insert in ascending order\n2-display\n");
printf("enter choice: ");
scanf("%d",&ch);
switch(ch){
case 1:
asc_nodes(&l,&r);
break;
case 2:
display(l);
break;
default:
printf("invalid choice");
break;
}
}while(ch<=2);
return 0;
}

void asc_nodes(dl **l1,dl **r1)
{
dl *p=NULL,*q=NULL;
p=(dl*)malloc(sizeof(dl));
if(p!=NULL)
{
scanf("%d",&(p->data));
p->prev=NULL;
p->next=NULL;
if(*l1==NULL && *r1==NULL)
{
*l1=*r1=p;
}
else if(p->data<(*l1)->data)
{
p->next=*l1;
(*l1)->prev=p;
*l1=p;
}
else if(p->data>(*r1)->data)
{
(*r1)->next=p;
p->prev=*r1;
*r1=p;
}
else
{
q=*l1;
while(q != NULL && q->data<p->data)
{
q=q->next;
}
p->prev=q->prev;
q->prev->next=p;
q->prev=p;
p->next=q;
}


}
}
void display(dl*l)
{
    dl *p=l;
    if (l == NULL)
        printf("Linked List is empty!\n");
    else
    {
        printf("Contents of the linked list are:-\n");
        do
        {
            printf("%d ", l->data);
            l = l->next;
        } while (l != NULL );
    }
}