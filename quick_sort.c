#include<stdio.h>
#define max 100
void qsort(int [],int,int );
int main(){
    int a[max],n,i;
    printf("enter no to elements to store:");
    scanf("%d",&n);
    printf("enter elements:");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    qsort(a,0,n-1);
    for(i=0;i<n;i++){
        printf("%d  ",a[i]);
    }
    return 0;
}
void qsort(int a[],int lb, int ub){
    int key=a[lb],i=lb,j=ub,t=0;
    if(lb>ub)
        return;
    while(i<j){
        while(key>=a[i] && i<j)
            i++;
        while(key<a[j])
            j--;
        if(i<j){
            t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
    }
    a[lb]=a[j];
    a[j]=key;
    qsort(a,lb,j-1);
    qsort(a,j+1,ub);
}