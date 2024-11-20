//CREATE A LL BY INSERTING NODES AT RHS USING FUNCTION 
//INSERTION,DELETION(from left),DISPLAY,COUNT TOTAL NODES,COUNT EVEN NODES,COUNT ODD NODES,PRINT LL IN ALTERNATE ORDER

#include<stdio.h>
#include <stdlib.h>
typedef struct list {
    int data;
    struct list* next;
}sl ;
 sl* insert(sl*);
 sl* delete(sl*);
 void display(sl*);
 void count_total(sl*);
 void count_even(sl*);
 void count_odd(sl*);
 void print_alt_nodes(sl*);
int main(){
    sl* l=NULL;
    int ch;
    do{
        printf("1-insert\n2-delete\n3-display\n4-count total nodes\n5-count even nodes\n6-count odd nodes\n7-print alternte nodes\n");
        printf("enter choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            l=insert(l);
            break;
            case 2:
            l=delete(l);
            break;
            case 3:
            display(l);
            break;
            case 4:
            count_total(l);
            break;
            case 5:
            count_even(l);
            break;
            case 6:
            count_odd(l);
            break;
            case 7:
            print_alt_nodes(l);
            break;
            default:
            printf("invalid choice");
        }
    }while(ch<=7);
    return 0;
}
    sl* insert(sl* l){
        int c,v;
        while (1) {
        sl *p=NULL;
        sl *r=NULL;
        p=(sl*)malloc(sizeof(sl));
        if(p==NULL){
            printf("memory allocation failed");
            return l;
        }
            printf("enter value to insert:");
            scanf("%d",&v);
            p->data=v;
            p->next = NULL;
        if(l==NULL){
            l=p;
        }
        else{
            r=l;
            while(r->next!=NULL){
            r=r->next;
            }
            r->next=p;
        }
            printf("enter 1 to continue and 0 to stop: ");
            scanf("%d", &c);
            if (c == 0) {
            break;
            }
        }
        return l;
    }


    sl* delete(sl *l){
        if(l==NULL){
        printf("The list is already empty\n");
        return l;
        }
        sl *p=NULL;
        p=l;
        printf("deleted node is %d",p->data);
        l=l->next;
        free(p);
        return l;
    }


    void display(sl*l){
    if (l==NULL)
    printf("empty linked list\n");
    sl *t=NULL;
    t=l;
    while (t != NULL) {
        printf("%d  ", t->data);
        t = t->next;
    }
}

    void count_total(sl* l){
    sl *t=NULL;
    int x=0;
    t = l;
    while (t != NULL) {
        x++;
        t = t->next;
    }
    printf("\ntotal nodes are %d\n", x);
    }

    void count_even(sl* l){
    sl *t=NULL;
    int x=0;
    t = l;
    while (t != NULL) {
        if(t->data%2==0){
        x++;
        }
        t = t->next;
    }
    printf("\ntotal even nodes are %d\n", x);
    }

    void count_odd(sl* l){
    sl *t=NULL;
    int x=0;
    t = l;
    while (t != NULL) {
        if(t->data%2!=0){
        x++;
        }
        t = t->next;
    }
    printf("\ntotal odd nodes are %d\n", x);
    }

    void print_alt_nodes(sl* l) {
    if (l == NULL) {
        printf("Empty linked list\n");
    }
    sl* t=NULL;
    t=l;
    int index = 0;
    while (t != NULL) {
        if (index % 2 == 0) {
            printf("%d -> ", t->data);
        }
        t = t->next;
        index++;
    }
}