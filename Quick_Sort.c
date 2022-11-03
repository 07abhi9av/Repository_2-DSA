//QUICK SORT

#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int start, int end){
    int pivot = a[end];
    int i = start -1;
    for(int j=start;j<end;j++){
        if(a[j]<=pivot){
            i++;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[i+1],&a[end]);
    return (i+1);
}


void quick_sort(int a[], int start, int end){
    int j;
    if(start<end){
        j = partition(a,start,end);
        quick_sort(a,start,j-1);
        quick_sort(a,j+1,end);
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
    
    quick_sort(a,0,size);
    display(a,size)
}
