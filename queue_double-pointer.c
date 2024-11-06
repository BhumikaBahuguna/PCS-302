//IMPLEMENTING QUEUE USING LL USING DOUBLE POINTER

#include<stdio.h>
#include<stdlib.h>
typedef struct queue
{
    int data;
    struct queue *next;
}q;
void enq(q**,q**);
void deq(q**,q**);
void display(q*);
void peek(q*);
int main(){
    q *f=NULL,*r=NULL;
    int ch;
    do{
        printf("1-enqueue\n2-dequeue\n3-display\n4-peek\n");
        printf("enter choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            enq(&f,&r);
            break;
            case 2:
            deq(&f,&r);
            break;
            case 3:
            display(f);
            break;
            case 4:
            peek(f);
            break;
            default:
            printf("invalid choice");        
    }
}while(ch<=4);
return 0;
}
    void enq(q** f1,q** r1){
    q* p=NULL;
    int x;
    p=(q*)malloc(sizeof(q));
    if(p!=NULL){
    printf("enter value to enqueue:");
    scanf("%d",&x);
    p->data=x;
    if(*f1==NULL && *r1==NULL){
    *f1=*r1=p;
    }
    else{
        (*r1)->next=p;
        *r1=p;
    }
    (*r1)->next=NULL;  
    }
}

    void deq(q** f1,q** r1) {
    q* p=NULL;
    int x;
    if(*f1==NULL)
    printf("empty queue\n");
    else{
        p=*f1;
        printf("dequed element is %d\n",(*f1)->data);
        if(*f1==*r1)
        {
            *f1=*r1=NULL;
        }
        else{
        (*f1)=(*f1)->next;}
        free(p);    
    }
    }

    void display(q* f1){
        if(f1==NULL)
        printf("empty queue\n");
        else{
            while(f1!=NULL){
                printf("%d  ",f1->data);
                f1=f1->next;
            }
        }
        printf("\n");
    }

    void peek(q* f1){
        if(f1==NULL)
        printf("empty queue\n");
        else{
            printf("%d\n",f1->data);
        }
    }