//OUTPUT RESTRICTED QEQUEUE

#include<stdio.h>
#define MAX 100
int enq(int[],int);//INSERTION AT REAR END
int frontdeq(int[],int,int);//DELETION FROM FRONT
int frontenq(int[],int);//INSERTION AT FRONT
void display(int[],int,int);//TO DISPLAY
void peek(int[],int);//TO PEEK
int main(){
    int dq[MAX],f=-1,r=-1,ch;
    do{
    printf("enter 1 to enqueue\nenter 2 to dequeue from front\nenter 3 to enque from front\nenter 4 to display\nenter 5 to peek\n");
    printf("enter choice:");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        r=enq(dq,r);
        if(r==0)
        f=0;
        break;
        case 2:
        f=frontdeq(dq,f,r);
        if(f==-1)
        f=r=-1;
        break;
        case 3:
        f=frontenq(dq,f);
        break;
        case 4:
        display(dq,f,r);
        break;
        case 5:
        peek(dq,f);
        break;
        default:
        printf("invalid choice\n");
      }
    }while(ch<=5);
    return 0;
}
int enq(int dq[],int r ){
   int ele;
   if(r==MAX-1)
   printf("overflow\n");
   else{
       printf("enter element to enqueue:");
       scanf("%d",&ele);
       r++;
       dq[r]=ele;
   }
   return r;
   }
   int frontenq(int dq[],int f ){
   int ele;
        if(f==0)
            printf("overflow\n");
         else if(f>0){
         f--;
         printf("enter element to enqueue:");
         scanf("%d",&ele);
         dq[f]=ele;
         }
         return f;
   }
int frontdeq(int dq[],int f,int r){
    int x;
    if(f==-1)
    printf("empty queue\n");
    else{
        x=dq[f];
        printf("dequed element is %d\n",x);
        if(f==r)
        f=r=-1;
        else
        f++;
        }
    return f;
}
void display(int dq[],int f,int r){
     int i;
    if(f==-1)
    printf("empty queue\n");
    else{
        for(i=f;i<=r;i++)
        {
        printf("%d ",dq[i]);
    }
}
}
void peek(int dq[],int f){
    if(f==-1)
    printf("empty queue\n");
    else{
        printf("%d\n",dq[f]);
    }
}