#include<stdio.h>
#include<stdlib.h>

int map[4][4] = {{6, 7, 12, 5}, {5, 3, 11, 18}, {7, 17, 3, 3}, {8, 10, 14, 9}};

struct memo_element{
	int value;
	int cached;
	int bp;
};
#define START 0
#define LEFT 1
#define UP 2

int mat(int i, int j)
{
	if (i == 0 && j == 0) return map[0][0];
	else if (i == 0) return mat(i, j-1) + map[i][j];
	else if (j == 0) return mat(i-1, j) + map[i][j];
	else
	{
		int a, b;
		a = mat(i-1, j);
		b = mat(i, j-1);
		return ((a<b)?a:b) + map[i][j];
	}
}

int mat_memo(int i, int j, struct memo_element **M)
{
	int ret;
	if (M[i][j].cached != 0) return M[i][j].value;
	if (i == 0 && j == 0)
	{
		ret = map[0][0];
		M[i][j].bp = START;
	}
	else if (i == 0)
	{
		ret = mat_memo(i, j-1, M) + map[i][j];
		M[i][j].bp = LEFT;
	}
	else if (j == 0)
	{
		ret = mat_memo(i-1, j, M) + map[i][j];
		M[i][j].bp = UP;
	}
	else
	{
		int a, b;
		a = mat_memo(i-1, j, M);
		b = mat_memo(i, j-1, M);
		ret = ((a<b)?a:b) + map[i][j];
		M[i][j].bp = ((a<b)?UP:LEFT);
	}
	M[i][j].value = ret;
	return M[i][j].value;
}

void print_path(int i, int j, struct memo_element **M)
{
	switch( M[i][j].bp )
	{
	case START:
		printf("<0,0>");
		return;
	case UP:
		print_path(i-1, j, M);
		break;
	case LEFT:
		print_path(i, j-1, M);
		break;
	}
	printf(" -> <%d,%d>", i, j);
}

int main()
{
	struct memo_element **M;
	int i = 0;
	int j = 0;

	M = (struct memo_element **) malloc(sizeof(struct memo_element*) * 4);
	for(i = 0; i < 4; i++)
		M[i] = (struct memo_element*) malloc(sizeof(struct memo_element) * 4);
	for(i = 0; i < 4; i++)
		for(j = 0; j < 4; j++)
			M[i][j].cached = 0;

	printf("Min path score : %d\n", mat_memo(3, 3, M));
	print_path(3, 3, M);
	printf("\n");
	return 0;
}