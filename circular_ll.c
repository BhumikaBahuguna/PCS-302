//CIRCULAR LL USING DOUBLE POINTER

#include<stdio.h>
#include<stdlib.h>
typedef struct cqueue
{
    int data;
    struct cqueue *next;
}cl;
void cenq(cl**,cl**);
void cdeq(cl**,cl**);
void display(cl*);
void peek(cl*);
int main(){
    cl *f=NULL,*r=NULL;
    int ch;
    do{
        printf("1-cenqueue\n2-cdequeue\n3-display\n4-peek\n");
        printf("enter choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            cenq(&f,&r);
            break;
            case 2:
            cdeq(&f,&r);
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
    void cenq(cl** f1,cl** r1){
    cl* p=NULL;
    int x;
    p=(cl*)malloc(sizeof(cl));
    if(p!=NULL){
    printf("enter value to enqueue:");
    scanf("%d",& p->data);
    if(*f1==NULL && *r1==NULL){
    *f1=*r1=p;
    p->next=*f1;
    }
    else{
        (*r1)->next=p;
        *r1=p;
        p->next=*f1;
    } 
    }
}


    void cdeq(cl** f1,cl** r1) {
    cl* p=NULL;
    if(*f1==NULL)
    printf("empty queue\n");
    else{
        p=*f1;
        printf("dequed element is %d\n",(*f1)->data);
        if(*f1==*r1)
        *f1=*r1=NULL;
        else
        {
        *f1=(*f1)->next;
        (*r1)->next=*f1;
        }
        free(p);    
    }
    }

    void display(cl* f){
        cl *p=f;
        if(f==NULL)
        printf("empty queue\n");
        else{
            do{
                printf("%d  ",p->data);
                p=p->next;
            }while(p!=f);
        }
    }

    void peek(cl* f){
        if(f==NULL)
        printf("empty queue\n");
        else{
            printf("%d\n",f->data);
        }
    }
    