//QUICK SORT

#include <stdio.h>

void swap(int *x,int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int a[], int start, int end){
    int pivot = a[end];
    int i = start-1;
    for(int j=start;j<end-1;j++){
        if(a[j]<=pivot){
            i++;
            swap(&a[i],&a[j]);
        }
    }
    swap(&i+1,&end);
    return (i+1);
}

void quick_sort(int a[], int start, int end){
    int j;
    if(start<end){
        j = partition(a, start, end);
        quick_sort(a, start, j);
        quick_sort(a, j+1,end);
    }
}

void print_arr(int a[], int size){
    for(int i=0;i<size;++i){
        printf("%d\t",a[i]);
    }
}

int main(){
    int data[] = {1,5,2,7,3,8,4,9};
    int size_arr = sizeof(data)/sizeof(data[0]);
    printf("Unsorted Array\n");
    print_arr(data,size_arr);
    quick_sort(data,0,size_arr-1);
    printf("\nSorted array in ascending order: \n");
    print_arr(data,size_arr);
}
