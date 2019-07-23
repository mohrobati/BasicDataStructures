#include <stdio.h>

/*// Recursively
int interpolationSearch(int *A, int l, int h, int x){
    if(h>=l) {
         int mid = l + ((h-l)/(A[h]-A[l])*(x-A[l]));
         if(A[mid]==x) return 1;
         if(A[mid]>x) return interpolationSearch(A,l,mid-1,x);
         if(A[mid]<x) return interpolationSearch(A,mid+1,h,x);
    }
    return 0;
}*/

// Iterative
int interpolationSearch(int *A, int n, int x){
    int l=0,h=n-1;
    int mid;
    while (h>=l) {
        mid = l + ((h-l)/(A[h]-A[l])*(x-A[l]));
        if(A[mid]==x) return 1;
        if(A[mid]>x) h=mid-1;
        if(A[mid]<x) l=mid+1;
    }
    return 0;
}

int main() {
    int n,i;
    scanf("%d",&n);
    int A[n];
    for (i = 0; i < n; i++) {
        scanf("%d",&A[i]);
    }
    printf("%d",interpolationSearch(A,n,5));
    return 0;
}