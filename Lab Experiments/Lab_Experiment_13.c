#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int tree[MAX];
int size = 0;
void init()
{
    for (int i = 0; i < MAX; i++)
        tree[i] = -1;
}

void insert(int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tree[size++]);
    }
}
void preorder(int root)
{                         // ROOT, LEFT , RIGHT
    if (tree[root] == -1) // if the node is empty, return(BASE CONDITION)
        return;
    printf("%d ", tree[root]);
    preorder(2 * root + 1); // left child
    preorder(2 * root + 2); // right child
}

void inorder(int root)
{                         // LEFT, ROOT, RIGHT
    if (tree[root] == -1) // if the node is empty, return(BASE CONDITION)
        return;
    inorder(2 * root + 1); // left child
    printf("%d ", tree[root]);
    inorder(2 * root + 2); // right child
}

void postorder(int root)
{                         // LEFT, RIGHT, ROOT
    if (tree[root] == -1) // if the node is empty, return(BASE CONDITION)
        return;
    postorder(2 * root + 1); // left child
    postorder(2 * root + 2); // right child
    printf("%d ", tree[root]);
}

int search(int target)
{
    for (int i = 0; i < size; i++)
    {
        if (tree[i] == target)
            return i;
    }
    return -1;
}
void delete(int value)
{
    int i = search(value);
    if (i == -1)
    {
        printf("Element not found\n");
    }
    else
    {
        tree[i] = tree[size - 1];
        tree[size - 1] = -1;
        size--;
        printf("Element deleted\n");
    }
}

int main()
{
    system("cls");
    init();
    int n, choice, target;
    printf("1. Insert\n2. Preorder Traversal\n3. Inorder Traversal\n4. Postorder Traversal\n5. Search\n6. Delete\n7. Exit\n");
    while (1)
    {
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value of N :");
            scanf("%d", &n);
            printf("Enter the elements of the tree :\n");
            insert(n);
            break;
        case 2:
            printf("Preorder Traversal :\n");
            preorder(0);
            printf("\n");
            break;
        case 3:
            printf("Inorder Traversal :\n");
            inorder(0);
            printf("\n");
            break;
        case 4:
            printf("Postorder Traversal :\n");
            postorder(0);
            printf("\n");
            break;
        case 5:
            printf("Enter the element to search : ");
            scanf("%d", &target);
            int index = search(target);
            if (index == -1)
            {
                printf("Element not found\n");
            }
            else
            {
                printf("Element found at index %d\n", index);
            }
            break;
        case 6:
            printf("Enter the element to delete : ");
            scanf("%d", &target);
            delete(target);
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid choice\n");
            break;
        }
    }
    printf("\n");
    return 0;
}
