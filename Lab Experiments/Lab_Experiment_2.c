#include<stdio.h>
#include<stdlib.h>
#define max 100

int stack[max], top = -1;

int isFull(){
    return top == (max - 1) ? 1 : 0;
}

int isEmpty(){
    return top == -1 ? 1 : 0;
}

void push(){

    if(isFull()) printf("Stack Overflow!!!!\n");
    
    else 
    {
        int a;
        scanf("%d", &a);
        stack[++top] = a;
        printf("Element added\n");
    }
}

void pop(){

    if(isEmpty()) printf("Stack is Empty");

    else{

        stack[top--] = 0;
        printf("Element deleted\n");
    }
}

void peek(){

    if(isEmpty()) printf("Stack is Empty\n");

    else printf("Top element is %d\n", stack[top]);

}

void show(){
    if(isEmpty()) printf("Stack is Empty !!!\n");
    else {
        for (int i = top; i >= 0; i--)
        {
            printf("%d ", stack[i]);
        }
    }
}

int main(){

    int a;

    scanf("%d", &a);

    for(int i = 0; i < a; i++){
        scanf("%d", &stack[i]);
        top++;
    }

    push();
    pop();
    peek();
    show();

    return 0;
}
