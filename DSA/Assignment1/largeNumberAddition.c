#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define M 1000000000

typedef struct node{
    int val ;
    struct node *next ;
}node ;

node* makeNode(int x){
    node* newnode = (node*) malloc(sizeof(node)) ;
    newnode->val = x;
    newnode->next = NULL;
    return newnode;
}

node* arr2Node(char *c, int n){
    node* head = (node*) malloc(sizeof(node));
    node *temp = head;
    int i;
    for(i=n-1;i>=0;i=i-9){
        int j,k,num = 0;
        for(j=i,k=1;j>i-9 && j>=0;j--,k=k*10){
            int a = (int)(c[j]-'0');
            num += a*k;
        }
        node *newnode = makeNode(num) ;
        temp->next = newnode ;
        temp = temp->next ;
    }
    return head->next ;
}

node* largeNumAdd(node *head1, node *head2){
    node* head = (node*) malloc(sizeof(node));
    node* temp = head;
    node* temp1 = head1;
    node* temp2 = head2;
    int carry = 0 ;
    while(temp1 || temp2){
        int sum =0;
        if(temp1 && temp2){
            sum = temp1->val + temp2->val + carry ;
            carry = sum/M ;
            sum %= M ;
            temp1 = temp1->next ;
            temp2 = temp2->next ;
        }else if(temp1){
            sum = temp1->val + carry ;
            carry = sum/M ;
            sum = sum%M ;
            temp1 = temp1->next ;
        }else{
            sum = temp2->val + carry ;
            carry = sum/M ;
            sum = sum%M ;
            temp2 = temp2->next ;
        }
        node *newnode = makeNode(sum) ;
        temp->next = newnode ;
        temp = temp->next ;
    }
    if(carry){
        node *newnode = makeNode(carry) ;
        temp->next = newnode ;
        temp = temp->next ;
    }
    return head->next ;
}

void print(node *head){
    while(head->next == NULL){
        printf("%d", head->val);
        return ;
    }
    print(head->next);
    printf("%09d", head->val);
    return ;
}

int main(){
    char num1[100],num2[100] ;
    printf("Enter first number : ") ;
    scanf("%s",num1) ;
    printf("Enter second number : ") ;
    scanf("%s",num2) ;
    node *lst1,*lst2 ;
    lst1 = arr2Node(num1,strlen(num1)) ;
    lst2 = arr2Node(num2,strlen(num2)) ;
    node *res = largeNumAdd(lst1,lst2) ;
    printf("First number : ") ;
    print(lst1);
    printf("\n");
    printf("Second number : ") ;
    print(lst2);
    printf("\n");
    printf("The sum of these two numbers is : ");
    print(res);
    return 0;
}