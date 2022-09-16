#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*top = NULL;;

void push(int x){
    struct Node *new_node;
    new_node = malloc(sizeof(struct Node));
    new_node -> data = x;
    if(top == NULL){
        //top = new_node;
        new_node -> next = NULL;
    }
    else{
        new_node -> next = top;
    }
    top = new_node;
    printf("Node is inserted --> %d\n",x);
}

int pop(){
    struct Node *temp = NULL;
    if(top == NULL){
        printf("Stack is empty");
    }
    else{
        int temp_data = top->data;
        top = top->next;
        free(temp);
        return temp_data;
    }
}

void display(){
    struct Node *temp = top;
    while (temp -> next != NULL){
        printf("%d \t",temp->data);
        temp = temp -> next;
    }
    printf("%d \n", temp->data);
}

int main(){
    push(5);
    push(15);
    push(50);
    display();

    pop();

    display();
}