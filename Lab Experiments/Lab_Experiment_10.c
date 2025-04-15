#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

Node* top = NULL;

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

void push(int data){

    if(top == NULL){
        top = create(data);
        printf("Element pushed\n");
    }

    else{

        Node* temp = create(data);
        temp->next = top;
        top = temp;
        printf("Element pushed\n");
    }
}

void pop(){
    if(top == NULL) printf("Stack is Empty!!!!!!\n");

    else{
        Node* temp = top;
        top = top->next;
        free(temp);
        printf("Element Poped!!!!!\n");
    }
}

void peek(){
    if(top == NULL) printf("Stack is Empty!!!!\n");
    else printf("Top is %d\n", top->data);
}

void show(){
    if(top == NULL) printf("Stack is Empty\n");
    else{
        Node* temp = top;
        while(temp != NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main(){
    
    printf("------------Stack-----------\n");
    printf("1) Push\n");
    printf("2) Pop\n");
    printf("3) Peek\n");
    printf("4) Show\n");
    printf("5) Exit\n");

    while(1){

        int a, data;
        scanf("%d", &a);

        switch(a){
            case 1:
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                pop();
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
