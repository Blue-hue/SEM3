#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    struct node *left, *right;
    int value;
}node;

node* create() {
    int val;
    node *newnode = (node*)malloc(sizeof(node));
    printf("Enter value : ");
    scanf("%d", &val);
    if (val == -1){
        return NULL;
    } else {
        newnode->value = val;
    }
    printf("Left-child of %d :\n", val);
    newnode->left = create();
    printf("Right-child of %d :\n", val);
    newnode->right = create();
    return newnode;
}

void preorder(node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->value);
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->value);
}

void inorder(node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->value);
    inorder(root->right);
}

int main() {
    node* root = create();
    printf("1. Preorder Traversal\n");
    printf("2. Inorder Traversal\n");
    printf("3. Postorder Traversal\n");
    printf("4. Exit\n");
    int ch = 0;
    while (ch != 4) {
        printf("Enter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            preorder(root);
            break;
        case 2:
            inorder(root);
            break;
        case 3:
            postorder(root);
            break;
        case 4:
            printf("Exiting program...");
            break;
        default:
            printf("Incorrect choice.");
            break;
        }
    }
    return 0;   
    }