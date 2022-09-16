#include <stdio.h>
#include <stdlib.h>

struct Node {
    int ele;
    struct Node *flink,*blink;
}*head = NULL, *p;

void insert_begin(int x){
    struct Node *new_node;
    new_node = malloc(sizeof(struct Node));
    new_node -> ele = x;

    if(head == NULL){  // If the linked list is empty
        head = new_node;
        new_node -> flink = NULL;
        new_node -> blink = NULL;
    }
    else{              // If there is at-least one element present in the linked list
        new_node -> flink = head;
        head -> blink = new_node;
        new_node -> blink = NULL;
        head = new_node;
    }
}

int main(){
    insert_begin(5);
}