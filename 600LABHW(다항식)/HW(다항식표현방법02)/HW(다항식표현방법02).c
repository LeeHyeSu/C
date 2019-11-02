#include<stdio.h>
#define MAX_TERMS 11
#define COMPARE(a,b) (((a) < (b)) ? -1: ((a) == (b))? 0: 1)
typedef struct {
	int coef;
	int expon;
} term;

int poly_add2(term t1[], int t1Size, term t2[], int t2Size, term t3[]) {
	int startA = 0, startB = 0;
	int finishA = t1Size - 1, finishB = t2Size - 1;
	int sizeC = 0;
	int coefficient =0;

	while(startA <= finishA && startB <= finishB)
	{
		switch(COMPARE(t1[startA].expon, t2[startB].expon)) 
		{
			case -1:
				t3[sizeC].coef = t2[startB].coef;
				t3[sizeC++].expon = t2[startB].expon;
				startB++;
				break;
			case 0:
				coefficient = t1[startA].coef + t2[startB].coef;
				if(coefficient) 
				{
					t3[sizeC].coef = coefficient;
					t3[sizeC++].expon = t1[startA].expon;
				}
				startA++;
				startB++;
				break;
			case 1:
				t3[sizeC].coef = t1[startA].coef;
				t3[sizeC++].expon = t1[startA].expon;
				startA++;
		}
	}

	for(; startA <= finishA; startA++) {
		t3[sizeC].coef = t1[startA].coef;
		t3[sizeC++].expon = t1[startA].expon;
	}
	for(; startB <= finishB; startB++) {
		t3[sizeC].coef = t2[startB].coef;
		t3[sizeC++].expon = t2[startB].expon;
	}
	return sizeC;
}

void print_poly2(term t[], int tSize) 
{
	int i;

	for(i = 0; i < tSize; i++)
		printf("%dx^%d ", t[i].coef, t[i].expon);
	printf("\n");
}

int main(void)
{
	term a[] = {{60, 6}, {50, 5}, {40, 4}}; int aSize = sizeof(a) / sizeof(a[0]); term b[] = {{40, 4}, {20, 2}}; int bSize = sizeof(b) / sizeof(b[0]); 
	term c[MAX_TERMS]; 
	int cSize;

	cSize = poly_add2(a, aSize, b, bSize, c);
	printf("a = "); print_poly2(a, aSize); 
	printf("b = "); print_poly2(b, bSize); 
	printf("a + b = c = "); print_poly2(c, cSize);
	printf("c 항의 개수는 %d\n", cSize);

	return 0;
}