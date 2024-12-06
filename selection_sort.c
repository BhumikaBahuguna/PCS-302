#include<stdio.h>
#define max 100
void sel_sort(int [],int );
int main(){
    int a[max],n,i=0;
    printf("enter no to elements to store:");
    scanf("%d",&n);
    printf("enter elements:");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sel_sort(a,n);
    for(i=0;i<n;i++){
        printf("%d  ",a[i]);
    }
    return 0;
}
void sel_sort(int a[],int n){
    int i=0,j=0,min=0,pos=0;
    for(i=0;i<n-1;i++){
        min=a[i];
        pos=i;
        for(j=i+1;j<n;j++){
            if(min>a[j]){
                min=a[j];
                pos=j;
            }
        }
        if(pos!=i){
            a[pos]=a[i];
            a[i]=min;
        }
    }
}