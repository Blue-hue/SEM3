#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *left, *right;
}node;

int search(int *arr, int strt, int end, int value)
{
	int i;
	for (i = strt; i <= end; i++) {
		if (arr[i] == value)
			return i;
	}
}

node* newNode(int data)
{
	node* node = (struct node*)malloc(sizeof(node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

node* buildTree(int *in, int *pre, int inStrt, int inEnd)
{
	static int preIndex = 0;
	if (inStrt > inEnd)
		return NULL;

	node* tNode = newNode(pre[preIndex++]);

	if (inStrt == inEnd)
		return tNode;

	int inIndex = search(in, inStrt, inEnd, tNode->data);

	tNode->left = buildTree(in, pre, inStrt, inIndex - 1);
	tNode->right = buildTree(in, pre, inIndex + 1, inEnd);

	return tNode;
}

void printPostorder(node* node)
{
	if (node == NULL)
		return;
	printPostorder(node->left);
	printPostorder(node->right);
    printf("%d ", node->data);
}

int main()
{
	int n, i;
    printf("How many nodes in tree? : ");
    scanf("%d", &n);
    int *in = (int*)(malloc(sizeof(int)*n));
    int *pre = (int*)(malloc(sizeof(int)*n));
    printf("Enter in-order array : ");
    for(i=0; i<n; i++) {
        scanf("%d", in+i);
    }
    printf("Enter pre-order array : ");
    for(i=0; i<n; i++) {
        scanf("%d", pre+i);
    }
	node* root = buildTree(in, pre, 0, n-1);

	printf("Let us see the Post-order traversal of the constructed tree\nto check the correctness of our createTree function -->\n");
	printPostorder(root);
    return 0;
}
