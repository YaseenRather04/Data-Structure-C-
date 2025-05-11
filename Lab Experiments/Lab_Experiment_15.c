#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node* left;
    int data;
    struct Node* right;
} Node;

Node* createnode(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

Node* insert(Node* root, int value) {
    if (root == NULL) {
        return createnode(value);
    } else {
        Node* queue[10000];
        int front = 0, rear = 0;
        queue[rear++] = root;
        while (front != rear) {
            Node* temp = queue[front++];
            if (temp->left == NULL) {
                temp->left = createnode(value);
                break;
            } else if (temp->right == NULL) {
                temp->right = createnode(value);
                break;
            } else {
                queue[rear++] = temp->left;
                queue[rear++] = temp->right;
            }
        }
        return root;
    }
}

void preorder(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void levelorder(Node* root) {
    if (root == NULL) return;
    Node* queue[10000];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front != rear) {
        Node* temp = queue[front++];
        printf("%d ", temp->data);
        if (temp->left != NULL)
            queue[rear++] = temp->left;
        if (temp->right != NULL)
            queue[rear++] = temp->right;
    }
}

Node* search(Node* root, int value) {
    if (root == NULL) return NULL;
    Node* queue[10000];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front != rear) {
        Node* temp = queue[front++];
        if (temp->data == value)
            return temp;
        if (temp->left != NULL)
            queue[rear++] = temp->left;
        if (temp->right != NULL)
            queue[rear++] = temp->right;
    }
    return NULL;
}

Node* findDeepest(Node* root) {
    Node* queue[10000];
    int front = 0, rear = 0;
    queue[rear++] = root;
    Node* temp;
    while (front != rear) {
        temp = queue[front++];
        if (temp->left != NULL)
            queue[rear++] = temp->left;
        if (temp->right != NULL)
            queue[rear++] = temp->right;
    }
    int i = (rear - 2) / 2;
    if (queue[i]->left == temp)
        queue[i]->left = NULL;
    else
        queue[i]->right = NULL;
    return temp;
}

void delete(Node* root, int value) {
    Node* temp = search(root, value);
    if (temp == NULL) {
        printf("Element Not Found!!!\n");
    } else {
        Node* last = findDeepest(root);
        temp->data = last->data;
        free(last);
        printf("Node Deleted!!!\n");
    }
}

int main() {
    int choice, value;
    Node* root = NULL;
    while (1) {
        printf("\n1. Insert\n");
        printf("2. Preorder\n");
        printf("3. Inorder\n");
        printf("4. Postorder\n");
        printf("5. Levelorder\n");
        printf("6. Search\n");
        printf("7. Delete\n");
        printf("8. Exit\n");
        printf("Your Choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("Preorder: ");
                preorder(root);
                printf("\n");
                break;
            case 3:
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder: ");
                postorder(root);
                printf("\n");
                break;
            case 5:
                printf("Levelorder: ");
                levelorder(root);
                printf("\n");
                break;
            case 6:
                printf("Enter value to search: ");
                scanf("%d", &value);
                if (search(root, value))
                    printf("Found!\n");
                else
                    printf("Not Found!\n");
                break;
            case 7:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                delete(root, value);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid Choice!!!!\n");
        }
    }
    return 0;
}
