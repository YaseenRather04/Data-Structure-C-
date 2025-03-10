//to perform queue operations

#include<stdio.h>
#define max 100

int queue[max], front = -1, rear = -1;

int isEmpty(){
    return (front == -1) ? 1 : 0;
}

int isFull(){
    return (rear == max - 1) ? 1 : 0;
}

void enQueue(int data){

    queue[++rear] = data;
    if(front == - 1) front = rear;
    printf("Element Inserted!!!!\n");

}

int deQueue(){

    int ret = queue[front];

    if(front == rear){  
        front = -1; rear = -1;
        return ret;
    }
    else{
        front++;
        return ret;
    }

}

int peek(){

    return queue[front];

}

void display(){

    for(int i = 0; i <= rear; i++) printf("%d ", queue[i]);

    printf("\n");

}

int main(){
    
    while(1){

    printf("1. Enqueue\n");
    printf("2. Dequeue \n");
    printf("3. Peek\n");
    printf("4. Display\n");
    printf("5. Exit\n");

    int choise, data;

    scanf("%d", &choise);

    switch (choise)
    {
    case 1:

        if(isFull()) printf("Queue Overflow!!!\n");

        else{
            scanf("%d", &data);
            enQueue(data);
        }
        break;
    
    case 2:
        if(isEmpty()) printf("Queue Underflow!!!\n");

        else printf("%d is dequeue\n", deQueue());

        break;

    case 3:
        if(isEmpty()) printf("Queue is empty\n");
        
        else printf("%d\n", peek());

        break;

    case 4:
        
        if(isEmpty()) printf("Queue is Empty");

        else display();

        break;

    case 5:
        exit(0);
    
    default:
        break;
    }
}

    return 0;
}
