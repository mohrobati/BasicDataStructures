#include <stdio.h>

/*// Recursively
int binarySearch(int A[] ,int l ,int h ,int x){
    if(h>=l){
        int mid = l + (h-l)/2;
        if(A[mid]==x) return 1;
        if(A[mid]>x) return binarySearch(A,l,mid-1,x);
        if(A[mid]<x) return binarySearch(A,mid+1,h,x);
    }
    return 0;
}*/

// Iterative
int binarySearch(int *A, int n,int x){
    int l = 0;
    int h = n-1;
    int mid;
    while (h>=l){
        mid = l+(h-l)/2;
        if(A[mid]==x) return 1;
        if(A[mid]>x) h=mid-1;
        if(A[mid]<x) l=mid+1;
    }
    return 0;
}

int main() {
    int n;
    scanf("%d",&n);
    int A[n],i;
    for(i=0;i<n;i++) scanf("%d",&A[i]);
    printf("%d",binarySearch(A,n,7));
    return 0;
}