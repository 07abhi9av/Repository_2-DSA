#include <stdlib.h>
#include <stdio.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue(int x){
    struct Node *temp;
    temp = malloc(sizeof(struct Node));
    temp -> data = x;
    if(front == NULL && rear == NULL){
        front = rear = temp;
    }
    else {
        rear -> next = temp;
        rear = temp;
    }
    printf("Node is inserted --> %d",x);
}

int dequeue(){
    if(front == NULL){
        printf("Queue is empty");
        return -1;
    }
    else{
        struct Node *temp = front;
        int temp_data = front->data;
        front = front->next;
        free(temp);
        return temp_data;
    }
}

void display() {
    struct Node *temp = NULL;
    while (temp) {
        printf("%d--->", temp->data);
        printf("%d \t",temp->data);
        temp = temp -> next;
    }
    printf("%d \n", temp->data);

}

int main(){
    enqueue(5);
    //dequeue();

    display();
}