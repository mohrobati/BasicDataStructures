#include <stdio.h>
#include <math.h>

int heapSize = 10;

int parent(int i){
    return (i-1)/2;
}

int left(int i){
    return 2*i+1;
}

int right(int i){
    return 2*i+2;
}

void maxHeapify(int* A,int n , int i) {
    int largest = i;
    int l = left(i);
    int r = right(i);
    if(l<n && A[l]>A[largest])
        largest = l;
    if(r<n && A[r]>A[largest])
        largest = r;
    if(largest!=i){
        int tmp = A[largest];
        A[largest] = A[i];
        A[i] = tmp;
        maxHeapify(A,n,largest);
    }
}

void buildMaxHeap(int* A, int n) {
    for(int i=(heapSize-1)/2;i>=0;i--)
        maxHeapify(A,n,i);
}

void insert(int* A, int data) {
    A[heapSize++] = data;
    int i = heapSize-1;
    while(i!=0 && A[parent(i)]<A[i]){
        int tmp = A[i];
        A[i] = A[parent(i)];
        A[parent(i)] = tmp;
        i = parent(i);
    }
}

int peek(int *A) {
    return A[0];
}

/*int poll(int *A) {
    int tmp = A[0];
    A[0] = A[heapSize-1];
    heapSize--;
    maxHeapify(A,n,0);
    return tmp;
}*/

void print(int *A) {
    for(int i=0;i<heapSize;i++) {
        printf("%d ",A[i]);
    }
    printf("\n");
}

void heapSort(int* arr,int n){
    int heapSize = n;
    while(heapSize!=0){
        int tmp = arr[heapSize-1];
        arr[heapSize-1] = arr[0];
        arr[0] = tmp;
        maxHeapify(arr,heapSize-1,0);
        heapSize--;
    }
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
}


int main() {
    int a = 2;
    int b = 4;
    if (a<b) goto l4;
    goto l5;
    l4 : printf("salam");
    l5 :
    return 0;
}