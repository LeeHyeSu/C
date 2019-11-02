#include<stdio.h>
#define MAX(a,b) ((a)>(b))? (a) : (b)
#define MIN(a,b) ((a)<(b))? (a) : (b)
#define MAX_DEGREE 10
typedef struct {
	int degree;
	int coef[MAX_DEGREE];
} polynomial;

polynomial poly_add1(polynomial A, polynomial B);
polynomial poly_subtract1(polynomial A, polynomial B);
void print_poly1(polynomial p);

polynomial poly_add1(polynomial A, polynomial B) // C = A+B
{
    polynomial C;               // 결과 다항식
    int Cpos = 0;   // 배열 인덱스 변수
    int degree_a = A.degree, degree_b = B.degree;
    int i;
    int t=0;
    int min_degree;

    C.degree = MAX(A.degree, B.degree); // 결과 다항식 차수
    min_degree = MIN(A.degree, B.degree);

    if( degree_a == degree_b )
    {
        for( i = 0 ; i <= degree_a ; i++,t++ )
            if ( A.coef[i] + B.coef[i] != 0 ) break;
        C.degree -= t;
    }

    for(i=0;i< C.degree - min_degree; i++, Cpos++ )
    {
        if ( degree_a > degree_b )
            C.coef[Cpos] = A.coef[i];
        else
            C.coef[Cpos] = B.coef[i];
    }

    for(i=0;i <= min_degree; i++)
    {
        if ( t > 0 )
        {
            t--;
        }
        else
        {
            if ( A.degree > B.degree )
                C.coef[Cpos] = A.coef[Cpos] + B.coef[i];
            else if ( A.degree < B.degree )
                C.coef[Cpos] = B.coef[Cpos] + A.coef[i];
            else
                C.coef[Cpos] = B.coef[i] + A.coef[i];
            Cpos++;
        }
    }
    return C;
}

polynomial poly_subtract1(polynomial A, polynomial B) {
	polynomial C;               // 결과 다항식
    int Cpos = 0;   // 배열 인덱스 변수
    int degree_a = A.degree, degree_b = B.degree;
    int i;
    int t=0;
    int min_degree;

    C.degree = MAX(A.degree, B.degree); // 결과 다항식 차수
    min_degree = MIN(A.degree, B.degree);

    if( degree_a == degree_b )
    {
        for( i = 0 ; i <= degree_a ; i++,t++ )
            if ( A.coef[i] - B.coef[i] != 0 ) break;
        C.degree -= t;
    }

    for(i=0;i< C.degree - min_degree; i++, Cpos++ )
    {
        if ( degree_a > degree_b )
            C.coef[Cpos] = A.coef[i];
        else
            C.coef[Cpos] = -B.coef[i];
    }

    for(i=0;i <= min_degree; i++)
    {
        if ( t > 0 )
        {
            t--;
        }
        else
        {
            if ( A.degree > B.degree )
                C.coef[Cpos] = A.coef[Cpos] - B.coef[i];
            else if ( A.degree < B.degree )
                C.coef[Cpos] = A.coef[i] - B.coef[Cpos];
            else
                C.coef[Cpos] = A.coef[i] - B.coef[i];
            Cpos++;
        }
    }
    return C;
}

void print_poly1(polynomial p) {
	int i;

	for(i = 0; i < p.degree + 1; i++) {
		if(p.coef[i] != 0)
			printf("%dx^%d ", p.coef[i], p.degree - i);
	}
	printf("\n");
}

int main(void) {
	polynomial a = { 2, {20, 10, 5}}; polynomial b = { 3, {30, -20, 0, 5}}; 
	polynomial c;
	c = poly_subtract1(a, b);

	printf("a = "); print_poly1(a);
	printf("b = "); print_poly1(b);
	printf("a - b = c = "); print_poly1(c);
	printf("c의 차수는 %d\n", c.degree);

	return 0;
}