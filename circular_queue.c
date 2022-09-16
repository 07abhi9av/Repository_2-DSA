#include <stdio.h>

#define SIZE 5
int c_queue[SIZE];
int front = -1;
int rear = -1;

void enqueue(int x){
    if(front == (rear+1)%SIZE){
        printf("\nCircular queue is full!");
    }
    else{
        rear = (rear+1)%SIZE;
        c_queue[rear] = x;
        printf("\nElement enqueued --> %d",x);
        if(front == -1){
            front++;
        }
    }
}

void dequeue(){
    if(front == -1 && rear == -1){
        printf("\nCircular queue is empty!");
    }
    else {
        printf("\nElement dequeued --> %d", c_queue[front]);
        front++;
    }
}

void display(){
    if(front == -1 && rear == -1){
        printf("\nCircular queue is empty!");
    }
    else{
        printf("\nThe elements of the queue are: ");
        for(int i=front;i<rear+1;i++){
            printf("%d ",c_queue[i]);
        }
    }
}


int main(){
    enqueue(5);
    enqueue(10);
    enqueue(15);

    display();

    dequeue();

    display();

}