#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int hash_table[SIZE] = {};

void insert(){
    int index, key, h_key, i;
    printf("\nenter value to insert: ");
    scanf("%d",&key);
    
    h_key = key%SIZE;
    
    for(i=0;i<SIZE;i++){
        index = (h_key+i)%SIZE;
        if(hash_table[index] == NULL){
            hash_table[index] = key;
            break;
        }
    }
    if(i==SIZE){
        printf("\ncannot insert\n");
    }
}

void search(){
    int index, key, h_key, i;
    printf("\nenter value to search: ");
    scanf("%d",&key);
    
    h_key = key%SIZE;
    
    for(i=0;i<SIZE;i++){
        index = (h_key+i)%SIZE;
        if(hash_table[index] == key){
            printf("\nelement found at index %d\n",index);
            break;
        }
    }
    if(i==SIZE){
        printf("\nnot found\n");
    }
}

void display(){
    for(int i=0;i<SIZE;i++){
        printf("\nvalue %d found at index %d\n",i,hash_table[i]);
    }
}

int main(){
    int choice;
    while(1){
        scanf("%d",&choice);
        switch(choice){
            case 1:
            insert();
            break;
            case 2:
            display();
            break;
            case 3:
            search();
            break;
            case 4:
            exit(0);
            break;
        }
    }
}


