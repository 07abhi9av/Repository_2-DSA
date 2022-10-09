#include <stdio.h>

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
#define SIZE 5
    int arr[SIZE] = {3,6,2,7,1};

    //Selection Sort Algorithm
    for(int i=0;i<SIZE-1;i++){
        int min = i;
        for(int j=i+1;j<SIZE;j++){
            if(arr[j]<arr[min]){
                min = j;
            }
        }
        swap(&arr[min],&arr[i]);
    }

    for(int i=0;i<SIZE;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}