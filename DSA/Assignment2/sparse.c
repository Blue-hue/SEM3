#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int value;
	int row_position;
	int column_postion;
	struct Node *next;
};

void create_new_node(struct Node** start, int non_zero_element,
					int row_index, int column_index )
{
	struct Node *temp, *r;
	temp = *start;
	if (temp == NULL)
	{
		temp = (struct Node *) malloc (sizeof(struct Node));
		temp->value = non_zero_element;
		temp->row_position = row_index;
		temp->column_postion = column_index;
		temp->next = NULL;
		*start = temp;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;

		r = (struct Node *) malloc (sizeof(struct Node));
		r->value = non_zero_element;
		r->row_position = row_index;
		r->column_postion = column_index;
		r->next = NULL;
		temp->next = r;

	}
}

void PrintList(struct Node* start, int n)
{
	struct Node *temp = start;
	int i = 1, j = 1;
	for(i;i<=n;i++) {
		for(j;j<=n;j++) {
			while(temp != NULL) {
			if ((temp->row_position == i)&&(temp->column_postion == j)) {
				printf("%d ", temp->value);
			} 
			else {
				temp = temp->next;
			}
		}
		if (temp == NULL) {
			printf("0 ");
		}
	}
	printf("\n");
	}
}

int main(){
	int n, non_zero, i = 0, row, col, val;
	struct Node *start = NULL;
	printf("Order of matrix : ");
	scanf("%d", &n);
	printf("How many non-zero elements? : ");
	scanf("%d", &non_zero);
	for(i;i<non_zero;i++) {
		printf("Enter row : ");
		scanf("%d", &row);
		printf("Enter column : ");
		scanf("%d", &col);
		printf("Enter element : ");
		scanf("%d", &val);
		create_new_node(&start, val, row, col);
	}
	PrintList(start,n);
	return 0;
}
