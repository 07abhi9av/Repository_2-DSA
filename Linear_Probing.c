#include <stdio.h>
#define SIZE 10

int hash(int key){
    return key%SIZE;
}

int probe(int H[], int key){
    int index = hash(key);
    int i=0;
    while(H[(index+i)%SIZE] != 0){
        i++;
    }
    return(index+i)%SIZE;
}

void insert(int H[], int key){
    int index = hash(key);
    if(H[index]!=0){
        index = probe(H,key);
    }
    H[index] = key;
}

int search(int H[], int key){
    int index = hash(key);
    int i=0;
    while (H[index+i]%SIZE!=key){
        i++;
    }
    return H[index+i]%SIZE;
}

int main(){
    int HT[10] = {0};
    insert(HT,5);
    insert(HT,12);
    insert(HT,35);
    insert(HT,16);

    printf("Key found : %d",search(HT,12));
}