#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;

} node;

node *head = NULL;

node *createnode(int ele)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = ele;
    newnode->next = NULL;
    return newnode;
}
void insertNodeInBeg(int ele)
{
    node *newNode = createnode(ele);
    newNode->next = head;
    head = newNode;
    printf("Node Inserted!!!\n");
}
void insertNodeAtEnd(int ele)
{
    node *newNode = createnode(ele);
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        printf("Node Inserted !!!\n");
    }
}

void deleteBegNode(){
    if(head == NULL) printf("List is Empty!!!!\n");

    else {
        node* t = head;
        head = head->next;
        free(t);
        printf("Node Deleted!!!\n");
    }
}

void deleteEndNode(){

    if(head == NULL) printf("List is Empty!!!!\n");

    else {

        node* t;

        if(head->next == NULL){
            t = head;
            head = NULL;
        }

        else {
            node* temp = head;
            while (temp->next->next != NULL){ 
                temp = temp->next;
            }

            t = temp->next;
            temp->next = NULL;
        }
        free(t);
        printf("Element Deleted!!!!\n");
    }
}

void deleteAnyNode(int pos){
    if(head == NULL) printf("List is Empty!!\n");

    else if(pos == 1) deleteBegNode();
    else{
        int i = 1;
        node* temp = head;
        while(i < pos - 1 && temp->next != NULL){
            i++;
            temp = temp->next;
        }
        if (temp->next != NULL && pos > 0)
        {
            node* t = temp->next;
            temp->next = temp->next->next;
            free(t);
            printf("Element Deleted!!!\n");
        }

        else printf("Invalid Position!!!!\n");
        
    }
}

void Display()
{
    if (head == NULL)
    {
        printf("Linked List is Empty !!!\n");
    }
    else
    {
        node *temp = head;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}

void search(int targer){
    if (head == NULL) printf("List is Empty!!!\n");

    else{
        node* temp = head;
        while (temp != NULL)
        {
            
        }
        
    }
    
}


int main()
{
    int target;
    while (1)
    {
        printf("-------- Singly Linked List --------------\n");
        printf("1. Insert Node At Begninning\n");
        printf("2. Insert Node At End\n");
        printf("3. Insert Node At Any position\n");
        printf("4. Delete Node From Begninning\n");
        printf("5. Delete Node From End\n");
        printf("6. Delete Node From Any position\n");
        printf("7. Search Element In List\n");
        printf("8. Sort Elements\n");
        printf("9. Display List\n");
        printf("10. Exit\n");
        int choice,ele,pos;
        printf("Enter Choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter Element: ");
            scanf("%d", &ele);
            insertNodeInBeg(ele);
            break;
        case 2:
            printf("Enter Element: ");
            scanf("%d", &ele);
            insertNodeAtEnd(ele);
            break;
        case 3:
            printf("Enter Element: ");
            scanf("%d", &ele);
            printf("Enter Position: ");
            scanf("%d", &pos);
            break;
        case 4:
            deleteBegNode();
            break;
        case 5:
            deleteEndNode();
            break;
        case 6:
            printf("Enter Position: ");
            scanf("%d", &pos);
                deleteAnyNode(pos);
            break;
        case 7:
            printf("Enter Target: \n");
            scanf("%d", &target);
            search(target);
            break;
        case 9:
            Display();
            break;
        case 10:
            exit(0);

        default:
            printf("Invalid Choice !!!\n");
        }
    }
    return 0;
}
