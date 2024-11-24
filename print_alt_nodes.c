//  DISPLAY ALTERNATE NODES

#include<stdio.h>
#include <stdlib.h>
typedef struct list {
    int data;
    struct list* next;
}sl ;
 sl* insert(sl*);
 void print_alt_nodes(sl*);
 int main(){
    sl* l=NULL;
    int ch;
    do{
        printf("1-insert\n2-print alternte nodes\n");
        printf("enter choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            l=insert(l);
            break;
            case 2:
            print_alt_nodes(l);
            break;
            default:
            printf("invalid choice");
        }
    }while(ch<=2);
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
    void print_alt_nodes(sl* l) {
    if (l == NULL) {
        printf("Empty linked list\n");
        return;
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
    printf("NULL\n");
}
