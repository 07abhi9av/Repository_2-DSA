#include <stdio.h>
#include <stdlib.h>

//structure of a node
struct node {
    int element;
    struct node *next;
}*head=NULL,*p;

struct node *findprevious(int s) {
    p=head;
    while(p->next!=head && p->next->element!=s)
        p=p->next;
    return p;
}

struct node *find(int s) {
    p=head;
    while(p->next!=head && p->element!=s)
        p=p->next;
    return p;
}

//Insertion
void insertbegin(int x) {
    struct node *newnode;
    newnode=malloc(sizeof(struct node));
    newnode->element=x;
    if(head==NULL) { // inserting an element into empty list
        head=newnode;
        newnode->next=head;
    }
    else {
        newnode->next=head;
        p=head;
        while(p->next!=head) {
            p = p->next;
        }
        p->next=newnode;
        head=newnode;
    }
}

void insertmiddle(int x) {
    struct node *newnode;
    int pos;
    newnode=malloc(sizeof(struct node));
    newnode->element=x;

    printf("\nEnter the value after which the element to be inserted:");
    scanf("%d",&pos);
    p=*find(pos);
    newnode->next=p->next;
    p->next=newnode;
}


void insert_last(int x) {
    struct node *new_node;
    new_node=malloc(sizeof(struct node));
    new_node->element=x;
    p=head;
    while(p->next!=head) {
        p = p->next;
    }
    p->next=new_node;
    new_node->next=head;
}


//Deletion
void deletion(int x) {
    struct node *temp;
    p=head;
    if(p->element==x) {
        if(p->next!=head) {
            temp=p;

            while(p->next!=head) {  //searching for last element
                p = p->next;
            }
            p->next=temp->next; //  3's next is 1
            head=temp->next;// 1 is head
            free(temp);
        }
        else { //works only one element is there in the list
            temp=p;
            head=NULL;
            free(temp);
        }
    }
    else {
        p=findprevious(x);   //If last node is to be deleted
        if(p->next!=head) {
            temp=p->next;
            p->next=temp->next;
            printf("\n The deleted element is%d", temp->element);
            free(temp);
        }
        else
            printf("\n Element not found in the list");
    }
}


int main(){
    insertbegin(5);
}
