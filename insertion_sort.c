#include<stdio.h>
#define max 100
void ins_sort(int [],int );
int main(){
    int a[max],n,i;
    printf("enter no to elements to store:");
    scanf("%d",&n);
    printf("enter elements:");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    ins_sort(a,n);
    for(i=0;i<n;i++){
        printf("%d  ",a[i]);
    }
    return 0;
}
void ins_sort(int a[],int n){
    int i,j,t=0;
    for(i=1;i<n;i++){
        t=a[i];
        j=i-1;
        while(j>=0 && t<a[j]){
            a[j+1]=a[j];
            j--;
        } 
        a[j+1]=t;
    }
}