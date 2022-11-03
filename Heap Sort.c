#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int a[], int N, int i){
    int largest = i;  //largest as root
    
    int left = 2*i+1;
    int right = 2*i+2;
    
    if(left<N && a[left]>a[largest]){
        largest = left;
    }
    
    if(right<N && a[right]>a[largest]){
        largest = right;
    }
    
    if(largest != i){
        swap(&a[i],&a[largest]);
        heapify(a, N, i);
    }
}

void heap_Sort(int arr[], int N){
    for(int i=N/2-1;i>=0;i--){    //building max heap
        heapify(arr,N,i);
    }
    
    for(int i=N-1;i>=0;i--){     //doing heap sort
        swap(&arr[0],&arr[i]);
        heapify(arr,i,0);
    }
}

void display(int a[], int size){
    for(int i=0;i<size;i++){
        printf("%d\t",a[i]);
    }
}

int main(){
    int a[] ={4,2,7,4,1};
    int size = sizeof(a)/sizeof(a[0]);
    
    heap_Sort(a,size);
    display(a,size);
}
