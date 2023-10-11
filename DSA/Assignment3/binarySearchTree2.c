#include <stdio.h>
#include <stdlib.h>
 
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}node;
 
node* createNode(int data) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
 
node* insert(node* root, int data) {
    if (root == NULL)
        return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}


 
node* search(node* root, int key) {
    if (root == NULL || root->data == key)
        return root;
    if (key < root->data)
        return search(root->left, key);
    return search(root->right, key);
}
 
void findInorderPreSuc(node* root, node** pre, node** suc, int key) {
    if (root == NULL)
        return;
 
    if (root->data == key) {
        if (root->left != NULL) {
            node* temp = root->left;
            while (temp->right)
                temp = temp->right;
            *pre = temp;
        }
        if (root->right != NULL) {
            node* temp = root->right;
            while (temp->left)
                temp = temp->left;
            *suc = temp;
        }
        return;
    }
 
    if (root->data > key) {
        *suc = root;
        findInorderPreSuc(root->left, pre, suc, key);
    } else {
        *pre = root;
        findInorderPreSuc(root->right, pre, suc, key);
    }
}
 
node* deleteNode(node* root, int key) {
    if (root == NULL)
        return root;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            node* temp = root->left;
            free(root);
            return temp;
        }
        node* temp = root->right;
        while (temp && temp->left != NULL)
            temp = temp->left;
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inOrderTraversal(node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

int main() {
    node* root = NULL;
    int choice, key, n, i;
    node* pre = NULL;
    node* suc = NULL;
 
    do {
        printf("\nMenu:\n");
        printf("1. Create Binary Search Tree from given array\n");
        printf("2. Insert a key into the binary search tree\n");
        printf("3. Search for a key in the binary search tree\n");
        printf("4. Find in-order predecessor and successor for a key\n");
        printf("5. Delete a key from the binary search tree\n");
        printf("6. Display elements of tree in in-order traversal\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
 
        switch (choice) {
            case 2:
                printf("Enter the key to insert: ");
                scanf("%d", &key);
                root = insert(root, key);
                break;
 
            case 3:
                printf("Enter the key to search: ");
                scanf("%d", &key);
                if (search(root, key) != NULL)
                    printf("Key %d has been found in the tree!!\n", key);
                else
                    printf("Key %d not found :(\n", key);
                break;
 
            case 4:
                printf("Enter the desired key: ");
                scanf("%d", &key);
                findInorderPreSuc(root, &pre, &suc, key);
                if (pre != NULL)
                    printf("Predecessor of %d : %d\n", key, pre->data);
                else
                    printf("No predecessor found.\n");
                if (suc != NULL)
                    printf("Successor of %d : %d\n", key, suc->data);
                else
                    printf("No successor found.\n");
                break;
 
            case 5:
                printf("Enter the key to delete: ");
                scanf("%d", &key);
                root = deleteNode(root, key);
                break;
 
            case 1:               
                printf("How many nodes in BST? : ");
                scanf("%d", &n);
                printf("Enter elements : ");
                int *arr = (int*)malloc(sizeof(int)*n);
                for (i = 0; i < n; i++){
                    scanf("%d", arr + i);
                }
                for (i = 0; i < n; i++){
                    root = insert(root, arr[i]);
                }
                printf("Binary Search Tree created!!");
                break;
            case 6:
                printf("In-order Traversal: ");
                inOrderTraversal(root);
                printf("\n");
                break;
            case 7:
                printf("Exiting program...");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (1);
}