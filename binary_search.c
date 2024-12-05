#include<stdio.h>
#define max 100
int binary_search(int [],int ,int);
int main(){
    int a[max],n,i,key,res;
    printf("enter no to elements to store:");
    scanf("%d",&n);
    printf("enter elements(in sorted order):");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("enter number to e searched:");
    scanf("%d",&key);
    res=binary_search(a,n,key);
    if(res==-1)
    printf("not found");
    else
    printf("Element found at position: %d\n", res + 1);
    return 0;
}
int binary_search(int a[],int n,int key){
    int l=0,r=n-1,mid=0;
    while(l<=r){
    mid=(l+r)/2;
    if(key==a[mid])
    return mid;
    else if(key<a[mid])
    r=mid-1;
    else
    l=mid+1;
    }
    return -1;
}