#include <stdio.h>

#define MAX_ARRAY_SIZE 20

typedef struct {
	int row;
	int col;
	int value;
} term;

void add_matrix(term A[], term B[], term C[])
{
	int i = 0;

	C[0].row = A[0].row;
	C[0].col = A[0].col;
	C[0].value = 0;

	for(i = 1; i <= A[0].value; i++) 
	{
		if(A[i].row == B[i].row && A[i].col == B[i].col) 
		{
			C[i].row = A[i].row;
			C[i].col = A[i].col;
			C[i].value = A[i].value + B[i].value;
			C[0].value++;
		}
		else if(A[i].row < B[i].row || (A[i].row == B[i].row && A[i].col < B[i].col))
		{
			C[i].row = A[i].row;
			C[i].col = A[i].col;
			C[i].value = A[i].value;
			i++;
			C[i].row = B[i].row;
			C[i].col = B[i].col;
			C[i].value = B[i].value;

		}
		else if(A[i].row > B[i].row || (A[i].row == B[i].row && A[i].col > B[i].col))
		{
			C[i].row = B[i].row;
			C[i].col = B[i].col;
			C[i].value = B[i].value;
			i++;
			C[i].row = A[i].row;
			C[i].col = A[i].col;
			C[i].value = A[i].value;
		}	
	}

	for(i = 1; i <= C[0].value; i++)
	{
		if(C[i].value == 0)
		{
			C[i] = C[i+1];
			C[0].value--;
		}
	}
}

int partition(term *arr, int p, int r)
{
	int i,j;
	term pivot;
	
	i = p-1;
	pivot = arr[r];

	for(j = p; j < r; j++)
	{
		if (arr[j].row * 5 + arr[j].col < pivot.row * 5 + pivot.col)
		{
			term t;
			i++;
			//swap arr[i] & arr[j]
			t = arr[i];
			arr[i] = arr[j];
			arr[j] = t;
		}
	}

	i++;
	//swap arr[i] & arr[r]
	arr[r] = arr[i];
	arr[i] = pivot;
	return i;
}

void quick_sort(term *arr, int p, int r)
{
	if(p < r)
	{
		int q = partition(arr, p, r);
		quick_sort(arr, p, q-1);
		quick_sort(arr, q+1, r);
	}
}

int a[5][5] = 
{{0, 8, 0, 0, 0},
{6, 0, 0, 0, 0},
{0, 0, 0, 0, 0},
{0, 0, 0, 9, 0},
{2, 3, 4, 0, 0}};

int b[5][5] = 
{{0, 0, 7, 0, 0},
{0, 7, 0, 0, 0},
{0, 0, 0, 0, 1},
{0, 0, 0, 0, 9},
{0, 2, 3, 4, 0}};

void changeToEfficient(int a[][5], term b[])
{
	int i, j, k;

	b[0].col = 5;
	b[0].row = 5;
	b[0].value = 0;
	k = 1;

	for(i = 0; i < 5; i++)
		for(j = 0; j < 5; j++)
			if(a[i][j] != 0)
			{
				b[k].row = i;
				b[k].col = j;
				b[k].value = a[i][j];
				k++;
				b[0].value++;
			}
}

void smTranspose(term a[], term b[])
{
	int i;

	b[0].row = a[0].col;
	b[0].col = a[0].row;
	b[0].value = a[0].value;
	for(i = 1; i <= a[0].value; i++)
	{
		b[i].row = a[i].col;
		b[i].col = a[i].row;
		b[i].value = a[i].value;
	}
}

void displayFull(term t[])
{
	int i, j;
	int k = 1;
	for(i = 0; i < t[0].row; i++)
	{
		for(j = 0; j < t[0].col; j++)
		{
			if(t[k].row == i && t[k].col == j)
			{
				printf("%d ", t[k].value);
				k++;
			}
			else
				printf("0 ");
		}
		printf("\n");
	}
}

void displaySimple(term t[])
{
	int i;
	printf("<%d,%d,%d>\n", t[0].row, t[0].col, t[0].value);
	for(i = 1; i < t[0].value; i++)
		printf("<%d,%d,%d>\n", t[i].row, t[i].col, t[i].value);
}

int main()
{
	term sm1[MAX_ARRAY_SIZE], sm2[MAX_ARRAY_SIZE], sm3[MAX_ARRAY_SIZE];

	changeToEfficient(a, sm1);
	printf("유의미한 정보만:\n");
	displaySimple(sm1);
	printf("\n");
	printf("행렬 표현:\n");
	displayFull(sm1);
	printf("\n");

	smTranspose(sm1, sm2);
	printf("전치 행렬로 바꾼 후\n");
	printf("\n유의미한 정보만:\n");
	displaySimple(sm2);
	printf("\n");

	quick_sort(sm2, 1, sm2[0].value);
	displaySimple(sm2);
	printf("\n");
	printf("행렬 표현:\n");
	displayFull(sm2);

	add_matrix(sm1, sm2, sm3);
	displaySimple(sm3);
}