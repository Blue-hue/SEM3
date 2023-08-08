#include <stdio.h>
#include <stdlib.h>

typedef struct termType {
    int coeff, expo;
} termType;

typedef struct poly {
    termType terms[100];
    int noOfTerms;
} poly;

poly* addPoly(poly *p1, poly *p2) {
    int i, j, k, l;
    poly *p3 = malloc(sizeof (poly));

    for (i = 0, j = 0, k = 0; ((i < p1->noOfTerms)&&(j < p2->noOfTerms)); k++) {
        if (p1->terms[i].expo == p2->terms[j].expo) {
            p3->terms[k].coeff = p1->terms[i].coeff + p2->terms[j].coeff;
            p3->terms[k].expo = p1->terms[i].expo;
            i++; j++;
        } else if (p1->terms[i].expo < p2->terms[j].expo) {
            p3->terms[k].coeff = p1->terms[i].coeff;
            p3->terms[k].expo = p1->terms[i].expo;
            i++;
        } else {
            p3->terms[k].coeff = p2->terms[j].coeff;
            p3->terms[k].expo = p2->terms[j].expo;
            j++;
        }
    }

    if (i < p1->noOfTerms) {
        for (l = i; l < p1->noOfTerms; l++, k++) {
            p3->terms[k].coeff = p1->terms[l].coeff;
            p3->terms[k].expo = p1->terms[l].expo;
        }
    } else {
        for (l = j; l < p2->noOfTerms; l++, k++) {
            p3->terms[k].coeff = p2->terms[l].coeff;
            p3->terms[k].expo = p2->terms[l].expo;
        }
    }
    p3->noOfTerms = k;

    return p3;
}

void print(poly* p) {
    int i, c;
    c = 0;
    for (i = 0; i < p->noOfTerms; i++) {
        if (c != 0 && c < p->noOfTerms && p->terms[i].coeff > 0) {
            printf("+");
        }
        printf("%dx^%d", p->terms[i].coeff, p->terms[i].expo);
        c++;
    }
}

/*int eval(poly* p, int x) {
    int i, j, term, res = 0;
    for(i-0; i < p->noOfTerms; i++) {
        term = 1;
        for(j=1; j <= p->terms[i].expo; j++) {
            term *= x;
        } term *= p->terms[i].coeff;
        res += term;
    } return res;
}
*/

int main() {
    poly *p1, *p2, *p3;
    int i, j, x;

    p1 = malloc(sizeof (poly));
    p2 = malloc(sizeof (poly));

    printf("How many terms in poly1 ? : ");
    scanf("%d", &p1->noOfTerms);
    for(i=0;i<p1->noOfTerms;i++) {
        printf("Enter coeff%d : ", i+1);
        scanf("%d", &p1->terms[i].coeff);
        printf("Enter expo%d : ", i+1);
        scanf("%d", &p1->terms[i].expo);
    }

    printf("How many terms in poly2 ? : ");
    scanf("%d", &p2->noOfTerms);
    for(i=0;i<p2->noOfTerms;i++) {
        printf("Enter coeff%d : ", i+1);
        scanf("%d", &p2->terms[i].coeff);
        printf("Enter expo%d : ", i+1);
        scanf("%d", &p2->terms[i].expo);
        }
        p3 = addPoly(p1, p2);
        print(p3);
    
    printf("\nEnter value of x at which you want to evaluate the polynomial : ");
    scanf("%d", &x);
    printf("Value of polynomial at given value  : \n");

    int res=0, term;
    for(i-0; i < p3->noOfTerms; i++) {
        term = 1;
        for(j=1; j <= p3->terms[i].expo; j++) {
            term *= x;
        } term *= p3->terms[i].coeff;
        res += term;
    } 

    printf("%d", res);
    return 0;
}