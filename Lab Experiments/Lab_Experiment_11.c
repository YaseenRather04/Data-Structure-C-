#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

Node* front = NULL;
Node* rear = NULL;

Node* create(int data){

    Node* newnode = (Node*)malloc(sizeof(Node));
    if(newnode == NULL){
        printf("Stack Overflow!!!!\n");
        return NULL;
    }

    else {
        newnode->data = data;
        newnode->next = NULL;
        return newnode;
    }
}

void enqueue(int data){
    if(front == NULL){
        front = create(data);
        rear = front;
        printf("Elemented Inserted!!!!!\n");
    }
    else{
        Node* temp = create(data);
        if(front->next == NULL){
            front->next = temp;
            rear = temp;
            printf("Elemented Inserted!!!!!\n");
        }
        else{
            rear->next = temp;
            rear = temp;
            printf("Elemented Inserted!!!!!\n");
        }
    }
}

void dequeue(){
    if(front == NULL) printf("Queue is Empty!!!!\n");

    else if(front->next == NULL){
        front = NULL;
        printf("dequeued!!!!\n");
    }

    else{
        Node* temp = front;
        front = front->next;
        free(temp);
        printf("Dequeued!!!!\n");
    }
}

void peek(){
    if(front == NULL) printf("Queue is Empty!!!!\n");
    else printf("%d\n", front->data);
}

void show(){
    if(front == NULL) printf("Queue is Empty!!!!\n");
    else{
        Node* temp = front;
        while(temp!= NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main(){
    
    printf("------------Queue-----------\n");
    printf("1) Enqueue\n");
    printf("2) Dequeue\n");
    printf("3) Peek\n");
    printf("4) Show\n");
    printf("5) Exit\n");

    while(1){

        int a, data;
        scanf("%d", &a);

        switch(a){
            case 1:
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;            
            case 4:
                show();
                break;
            case 5:
                return 0;
                break;
            default: printf("Invalid Choise!!!!\n");
        }
    }

    return 0;
}
