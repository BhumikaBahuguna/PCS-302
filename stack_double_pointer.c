//STACK IMPLEMENTATION USING LL USING DOUBLE POINTER
#include<stdio.h>
#include<stdlib.h>
typedef struct stack {
    int data;
    struct stack *next;
}s;
void push(s**);
void pop(s**);
void display(s*);
void peek(s*);
int main()
{
    s* top=NULL;
    int ch;
    do{
        printf("1-push\n2-pop\n3-display\n4-peek\n");
        printf("enteer choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            push(&top);
            break;
            case 2:
            pop(&top);
            break;
            case 3:
            display(top);
            break;
            case 4:
            peek(top);
            break;
            default:
            printf("invalid choice");
        }
    }while(ch<=4);
    return 0;
}
void push(s** tp){
    s *p=NULL;
    p=(s*)malloc(sizeof(s));
    if(p!=NULL)
    {
        int x;
        printf("enter value to push:");
        scanf("%d",&x);
        p->data=x;
        p->next=*tp;
        *tp=p;
    }
    else {
        printf("no memory");
    }
}
void pop(s** tp) {
    s *p=NULL;
    if(*tp==NULL){
        printf("stack is empty");}
        else{
            p=*tp;
            printf("popped node is %d\n",(*tp)->data);
            *tp=(*tp)->next;
            free(p);
        }
}
void display(s* tp){
    if(tp==NULL)
    printf("stack is empty\n");
    else{
        while(tp!=NULL)
        {
            printf("%d ",tp->data);
            tp=tp->next;
        }
        printf("\n");
    }
}
void peek(s* tp){
    if(tp==NULL)
    printf("stack is empty\n");
    else{
        printf("%d\n",tp->data);
        }
    }