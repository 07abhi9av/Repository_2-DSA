//Linear Queue
#include <stdio.h>

int front = -1;
int rear = -1;
#define SIZE 10
int queue[SIZE];

void enqueue(int x){
    if(rear == SIZE - 1){
        printf("Queue is Full");
    }
    else {
        if(front == -1){
            rear++;
            queue[rear] = x;
            printf("Element enqueued --> %d \n",x);
        }
    }
}

void dequeue(){
    if(front == -1 && rear == -1){
        printf("Queue is empty!");
    }
    else{
        printf("\nElement is dequeued --> %d \n",queue[front+1]);
        front++;
    }
}

void display(){
    if(front == -1 && rear == -1){
        printf("Queue is empty!");
    }
    else{
        printf("\nThe elements of queue are: \n");
        for(int i=front;i<rear+1;i++){
            printf("%d \t",queue[i]);
        }
    }
}

int main() {
    enqueue(5);
    enqueue(10);
    enqueue(15);

    display();

    dequeue();

    display();

    return 0;
}