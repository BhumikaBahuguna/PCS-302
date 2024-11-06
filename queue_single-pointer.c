//IMPLEMENTING QUEUE USING LL USING SINGLE POINTER
#include<stdio.h>
#include<stdlib.h>
typedef struct queue
{
    int data;
    struct queue *next;
}q;
q* enq(q*);
q* deq(q*);
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
            r=enq(r);
            if(f==NULL)
            f=r;
            break;
            case 2:
            f=deq(f);
            if(f==NULL)
            r=NULL;
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
    q* enq(q* r){
    q* p=NULL;
    int x;
    p=(q*)malloc(sizeof(q));
    if(p!=NULL){
    printf("enter value to enqueue:");
    scanf("%d",&x);
    p->data=x;
    if(r==NULL)
    r=p;
    else{
        r->next=p;
        r=p;
    }
    r->next=NULL;
    }
    else {
        printf("no memory");
    }
    return r;    
}

    q* deq(q* f) {
    q* p=NULL;
    int x;
    if(f==NULL)
    printf("empty queue\n");
    else{
        p=f;
        printf("dequed element is %d\n",f->data);
        f=f->next;
        free(p);     
    }
    return f;
}

    void display(q* f){
        if(f==NULL)
        printf("empty queue\n");
        else{
            while(f!=NULL){
                printf("%d  ",f->data);
                f=f->next;
            }
        }
        printf("\n");
    }

    void peek(q*f){
        if(f==NULL)
        printf("empty queue\n");
        else{
            printf("%d\n",f->data);
        }
    }