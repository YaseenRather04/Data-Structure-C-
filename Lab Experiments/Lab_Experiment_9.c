#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *head = NULL;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void insertAtBeg(int data)
{
    Node *newNode = createNode(data);
    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        Node *temp = head;
        while (temp->next != head)
            temp = temp->next;
            newNode->next = head;
            temp->next = newNode;
            head = newNode;
    }
    printf("Node added !!!\n");
}

void insertAtEnd(int data)
{
    Node *newNode = createNode(data);
    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        Node *temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }
    printf("Node added !!!\n");
}

void insertAtPos(int data, int pos)
{
    if (pos < 1)
    {
        printf("Invalid position\n");
        return;
    }
    if (head == NULL && pos > 1)
    {
        printf("List is empty. Cannot insert at position %d\n", pos);
        return;
    }
    if (pos == 1)
    {
        insertAtBeg(data);
        return;
    }
    Node *newNode = createNode(data);
    Node *temp = head;
    int i = 1;
    while (i < pos - 1 && temp->next != head)
    {
        temp = temp->next;
        i++;
    }
    if (i == pos - 1)
    {
        newNode->next = temp->next;
        temp->next = newNode;
        printf("Node added !!!\n");
    }
    else
    {
        printf("Position not found\n");
        free(newNode);
    }
}

void deleteFromBeg()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if (head->next == head)
    {
        free(head);
        head = NULL;
        printf("Node deleted !!!\n");
        return;
    }
    Node *temp = head;
    Node *last = head;
    while (last->next != head)
        last = last->next;
    head = head->next;
    last->next = head;
    free(temp);
    printf("Node deleted !!!\n");
}

void deleteFromEnd()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if (head->next == head)
    {
        free(head);
        head = NULL;
        printf("Node deleted !!!\n");
        return;
    }
    Node *temp = head;
    Node *prev = NULL;
    while (temp->next != head)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = head;
    free(temp);
    printf("Node deleted !!!\n");
}

void deleteAtPos(int pos)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if (pos < 1)
    {
        printf("Invalid position\n");
        return;
    }
    if (pos == 1)
    {
        deleteFromBeg();
        return;
    }
    Node *temp = head;
    Node *prev = NULL;
    int i = 1;
    while (i < pos && temp->next != head)
    {
        prev = temp;
        temp = temp->next;
        i++;
    }
    if (i == pos)
    {
        prev->next = temp->next;
        free(temp);
        printf("Node deleted !!!\n");
    }
    else
    {
        printf("Invalid position\n");
    }
}

void search(int data)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    Node *temp = head;
    int pos = 1;
    do
    {
        if (temp->data == data)
        {
            printf("Element found at position %d\n", pos);
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);
    printf("Element not found in the list\n");
}

void display()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    Node *temp = head;
    printf("Elements in the list are: ");
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main()
{
    system("cls");
    int choice, value, pos;
    while (1)
    {
        printf("----Circular Singly Linked List----\n");
        printf("1. Insert at beginning\n2. Insert at end\n3. Insert at position\n4. Delete from beginning\n5. Delete from end\n6. Delete from position\n7. Search in list\n8. Display\n9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            insertAtBeg(value);
            break;
        case 2:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            insertAtEnd(value);
            break;
        case 3:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            printf("Enter position to insert: ");
            scanf("%d", &pos);
            insertAtPos(value, pos);
            break;
        case 4:
            deleteFromBeg();
            break;
        case 5:
            deleteFromEnd();
            break;
        case 6:
            printf("Enter position to delete: ");
            scanf("%d", &pos);
            deleteAtPos(pos);
            break;
        case 7:
            printf("Enter value to search: ");
            scanf("%d", &value);
            search(value);
            break;
        case 8:
            display();
            break;
        case 9:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
        printf("\n");
    }
    return 0;
}
