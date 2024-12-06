#include<stdio.h>
#define max 100
void msort(int [],int[],int ,int );
void merge(int [],int [],int,int,int);
int main(){
    int a[max],t[max],n,i;
    printf("enter no to elements to store:");
    scanf("%d",&n);
    printf("enter elements:");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    msort(a,t,0,n-1);
    for(i=0;i<n;i++){
        printf("%d  ",a[i]);
    }
    return 0;
}
/*void msort(int a[],int t[],int lb,int ub){
   int mid=0;
   if(lb<ub){
    mid=(lb+ub)/2;
    msort(a,t,lb,mid);
    msort(a,t,mid+1,ub);
    merge(a,t,lb,mid,ub);
   }
}
void merge(int a[],int t[],int lb,int mid,int ub){
    int k=lb,i=lb,j=ub,le=mid;
    while(lb<=le && mid+1<=ub){
        if(a[lb]<a[mid+1]){
            t[k++]=a[lb];
            lb++;
        }
        else{
            t[k++]=a[mid+1];
            mid++;
        }
    }
    while(lb<=le){
        t[k++]=a[lb];
        lb++;
    }
    while(mid+1<=ub){
        t[k]=a[mid+1];
        k++;
        mid++;
    }
    for(i=lb;i<ub;i++){
        a[i]=t[i];
    }
}
*/
void msort(int a[], int t[], int lb, int ub) {
    int mid = 0;
    if (lb < ub) { // Base condition: Stop if the segment has 1 or 0 elements
        mid = (lb + ub) / 2;
        msort(a, t, lb, mid);      // Sort the left half
        msort(a, t, mid + 1, ub); // Sort the right half
        merge(a, t, lb, mid, ub); // Merge the two halves
    }
}

void merge(int a[], int t[], int lb, int mid, int ub) {
    int i = lb, j = mid + 1, k = lb;

    // Merge elements from the two halves into the temporary array `t`
    while (i <= mid && j <= ub) {
        if (a[i] <= a[j]) {
            t[k++] = a[i++];
        } else {
            t[k++] = a[j++];
        }
    }

    // Copy remaining elements from the left half (if any)
    while (i <= mid) {
        t[k++] = a[i++];
    }

    // Copy remaining elements from the right half (if any)
    while (j <= ub) {
        t[k++] = a[j++];
    }

    // Copy the sorted elements back into the original array
    for (i = lb; i <= ub; i++) {
        a[i] = t[i];
    }
}
