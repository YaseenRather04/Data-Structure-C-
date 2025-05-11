#include <stdio.h>
#define MAX 100

int tree[MAX];
int size = 0;

void init() {
    for(int i = 0; i < MAX; i++)
        tree[i] = -1;
}

void insert(int value, int root) {
    if(tree[root] == -1)
        tree[root] = value;
    else if(value < tree[root])
        insert(value, 2*root+1);
    else if(value > tree[root])
        insert(value, 2*root+2);
}

void preorder(int root) {
    if(tree[root] == -1)
        return;
    printf("%d ", tree[root]);
    preorder(2*root+1);
    preorder(2*root+2);
}

void inorder(int root) {
    if(tree[root] == -1)
        return;
    inorder(2*root+1);
    printf("%d ", tree[root]);
    inorder(2*root+2);
}

void postorder(int root) {
    if(tree[root] == -1)
        return;
    postorder(2*root+1);
    postorder(2*root+2);
    printf("%d ", tree[root]);
}

int search(int i, int target) {
    if(i >= MAX || tree[i] == -1)
        return -1;
    else if(tree[i] == target)
        return i;
    else if(target < tree[i])
        return search(2*i+1, target);
    else 
        return search(2*i+2, target);
}

int findMin(int i) {
    while(i < MAX && tree[2*i+1] != -1)
        i = 2*i+1;
    return i;
}

int findMax(int i) {
    while(i < MAX && tree[2*i+2] != -1)
        i = 2*i+2;
    return i;
}

void deleteNode(int i, int value) {
    i = search(i, value);
    if(i == -1)
        printf("Element not found!!!!\n");
    else {
        int left = 2*i + 1;
        int right = 2*i + 2;

        if((left >= MAX || tree[left] == -1) && (right >= MAX || tree[right] == -1)) {
            tree[i] = -1; // No children
        }
        else if(tree[right] == -1) {
            int max = findMax(left);
            tree[i] = tree[max];
            deleteNode(max, tree[max]);
        }
        else {
            int min = findMin(right);
            tree[i] = tree[min];
            deleteNode(min, tree[min]);
        }
    }
}

int main() {
    init();
    int n, choice, index;

    while(1) {
        printf("1. Insert elements\n");
        printf("2. Preorder Traversal\n");
        printf("3. Inorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Search element\n");
        printf("6. Delete element\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the value: ");
                scanf("%d", &n);
                insert(n, 0);
                break;

            case 2:
                printf("\nPreorder: ");
                preorder(0);
                printf("\n");
                break;

            case 3:
                printf("\nInorder: ");
                inorder(0);
                printf("\n");
                break;

            case 4:
                printf("\nPostorder: ");
                postorder(0);
                printf("\n");
                break;

            case 5:
                printf("Enter the value: ");
                scanf("%d", &n);
                index = search(0, n);
                if(index == -1)
                    printf("Not Found !!!\n");
                else
                    printf("Found at index %d !!!\n", index);
                break;

            case 6:
                printf("Enter the value: ");
                scanf("%d", &n);
                deleteNode(0, n);
                break;

            case 7:
                return 0;

            default:
                printf("Invalid choice !!!!!\n");
        }
    }
}
