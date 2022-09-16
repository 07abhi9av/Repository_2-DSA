#include <stdio.h>

int main(){
#define SIZE 5
    int arr[SIZE] = {3,6,2,7,1};

    //Bubble Sort Algorithm
    for(int i=0;i<SIZE-1;i++){
        for(int j=0;j<SIZE-i-1;j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    for(int i=0;i<SIZE;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}