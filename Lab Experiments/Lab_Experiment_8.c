#include<stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;

} node;

node *head = NULL;

node* newnode(int data){
    node* new = (node*)malloc(sizeof(node));
    new->data = data;
    new->next = new->prev = NULL;
    return new;
}

void insertStart(int data){

    if(head == NULL){
        head = newnode(data);
        printf("Element Inserted!!\n");
    }

    else{

        node* temp = newnode(data);
        temp->next = head;
        head->prev = temp;
        head = temp;
        printf("Element Inserted!!!\n");
    }
}

void insertEnd(int data){

    if(head == NULL){
        head = newnode(data);
        printf("Element Added!!!\n");
    }

    else{
        node* t = newnode(data);

        node* temp = head;

        while(temp->next != NULL) temp = temp->next;

        temp->next = t;
        t->prev = temp;
        printf("Element Inserted!!!\n");
    }
}

void insertAnyNode(int data, int k){

    if(k == 1 || head == NULL) insertStart(data);

    else{

        int i = 0;
        node* temp = head;

        while(temp != NULL){
            i++;
            if(temp->next == NULL){
                insertEnd(data);
                break;
            }
            if(i == k){

                node* t = newnode(data);
                t->next = temp;
                t->prev = temp->prev;
                t->prev->next = t;
                temp->prev = t;
                printf("Element Inserted!!!\n");
                break;
            }
            temp = temp->next;

        }
    }
}

void deleteBeg(){
    if(head == NULL) printf("List is Empty\n");

    else if(head->next == NULL){ 
        head = NULL;
        printf("Element Deleted\n");
    }

    else{
        node* temp = head;
        head = temp->next;
        head->prev = NULL;
        free(temp);
        printf("Element Deleted!!!\n");
    }
}

void deleteEnd(){

    if(head == NULL) printf("List is Empty\n");

    else if(head->next == NULL){
        head = NULL;
        printf("Element Deleted!!!\n");
    }

    else{
        node* temp = head;

        while(temp->next->next != NULL) temp = temp->next;

        node* t = temp->next;
        temp->next = NULL;
        free(t);
        printf("Element Deleted!!!\n");

    }
}

void deleteAnyNode(int k){

    if(head == NULL) printf("List is Empty!!!\n");

    else if(k == 1) deleteBeg();

    else{

        int i = 0;
        node* temp = head;

        while(temp != NULL){
            i++;
            if(temp->next == NULL){
                deleteEnd();
                break;
            }

            else if(i == k){
                node* t = temp->prev;
                t->next = temp->next;
                temp->next->prev = t;
                free(temp);
                printf("Element Deleted!!!\n");
                break;
            }

            temp = temp->next;

        }
    }
}

void search(int k){

    if(head == NULL) printf("List is Empty!!!!\n");

    else{
        int i = 0;
        node* temp = head;
        while(temp->next != NULL){
            i++;
            if(temp->data == k){
                printf("Element %d found at Node No : %d \n", k, i);
                break;
            }
            temp = temp->next;
        }
    }
}

void display(){
    node* temp = head;

    if(head == NULL) printf("List is Empty!!!\n");

    else {
        while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
        }
    }
    printf("\n");
}

int main(){

    printf("-------- Doubly Linked List --------------\n");
    printf("2. Insert Node At End\n");
    printf("3. Insert Node At Any position\n");
    printf("4. Delete Node From Begninning\n");
    printf("5. Delete Node From End\n");
    printf("6. Delete Node From Any position\n");
    printf("7. Search Element In List\n");
    printf("8. Display List\n");
    printf("9. Exit\n");
    printf("1. Insert Node At Begninning\n");

    while (1)
    {
        int choice,ele,pos, target;
        printf("Enter Choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter Element: ");
            scanf("%d", &ele);
            insertStart(ele);
            break;
        case 2:
            printf("Enter Element: ");
            scanf("%d", &ele);
            insertEnd(ele);
            break;
        case 3:
            printf("Enter Element: ");
            scanf("%d", &ele);
            printf("Enter Position: ");
            scanf("%d", &pos);
            insertAnyNode(ele, pos);
            break;
        case 4:
            deleteBeg();
            break;
        case 5:
            deleteEnd();
            break;
        case 6:
            printf("Element position : ");
            scanf("%d", &pos);
            deleteAnyNode(pos);
            break;
        case 7:
            printf("Enter Element : ");
            scanf("%d", &target);
            search(target);
            break;
        case 8:
            display();
            break;
        case 9:
            exit(0);

        default:
            printf("Invalid Choice !!!\n");
        }
    }
    return 0;
}
