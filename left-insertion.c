//INSERT NODES AT LEFT OF THE LINKED LIST
#include<stdio.h>
#include<stdlib.h>
    typedef struct list {
        int data;
        struct list *next;
    }sl;
int main()
{
    sl *p=NULL,*l= NULL;
    int ch,v,c=0;
    while(1){
        p=(sl*)malloc(sizeof(sl));
        if(p!=NULL)
        {
            printf("enter data:");
            scanf("%d",&v);
            p->data=v;
            p->next=l;
            l=p;
        }
        printf("do you want to continue ? press 1 to continue and zero to stop\n");
        scanf("%d",&ch);
        if(ch==0)
        break;
    }
    p=l;
    while(p!=NULL)
    {
        printf("%d  ",p->data);
        p=p->next;
    }
    return 0;
}