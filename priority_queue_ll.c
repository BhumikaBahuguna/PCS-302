//PRIORITY QUEUE SINGLE LL DOUBLE POINTER

#include<stdio.h>
#include<stdlib.h>
typedef struct queue
{
	int pr;
	int data;
	struct queue *next;
}q;
void enq(q**,q**);
void deq(q**,q**);
void display(q*);
int main()
{
	q* l=NULL,*r=NULL;
	int ch;
	do 
	{
		printf("\nEnter the following to do the desired operations:-\n");
		printf("1-Enqueue\n2-Dequeue\n3-Display\n4-Exit\n");
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		printf("\n");
		switch(ch)
		{
			  case 1: enq(&l,&r);
			  break;
			  
			  case 2: deq(&l,&r);
			  break;
			  
			  case 3: display(l);
			  break;
			  
			  case 4: printf("Thank you for using this program!!\n");
			  exit(0);
			  
			  default: printf("Wrong choice\n");			  
		}
	}
	while(ch!=5);
	return 0;
}

void enq(q** l1,q** r1)
{
	q* p = NULL;
	p = (q*)malloc(sizeof(q));
	if(p==NULL)
		printf("Memory Allocation Failed!\n");
	else
	{
		printf("Enter priority: ");
		scanf("%d",&(p->pr));
		printf("Enter data: ");
		scanf("%d",&(p->data));
		if(*l1==NULL)
			*l1= p;
		else
			(*r1)->next=p;
		p->next = NULL;
		*r1=p;
	}
}


void deq(q** l ,q** r)
{
	int min;
	q* t=NULL,*p=NULL;
	if(*l==NULL)
		printf("Queue is empty!\n");
	else
	{
		min=(*l)->pr;
		t=*l;
		p=*l;
		while(t!=NULL)
		{
			if(t->pr < min)
			{
				min=t->pr;
				p=t;
			}
			t=t->next;
		}
		printf("Dequeued queue element with Priority:%d ;Data:%d\n",p->pr,p->data);
		if(p==*l)
			*l=p->next;
		else
		{
			t=*l;
			while(t->next!=p)
				t=t->next;
			t->next=p->next;
			if(t->next==NULL)
				*r=t;
		}
		free(p);
	}
}
		

void display(q* l)
{
	int c=1;
	if(l==NULL)
		printf("Queue is empty!\n");
	else
	{
		printf("Contents of the queue are:-\n\n");
		while(l!=NULL)
		{
			printf("%d) Priority:%d; Data:%d\n",c++,l->pr,l->data);
			l=l->next;
		}
	}
}

			
		
			
		
	