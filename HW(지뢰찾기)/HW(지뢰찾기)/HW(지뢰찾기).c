#include<stdio.h>
#define X_VALUE 5 //2���� �迭�� ���� ��
#define Y_VALUE 5 //2���� �迭�� ���� ��
void readBombInfo(char grid[][Y_VALUE+1])
{
	int i;	
	// grid �� ���� ���� �Է�
	printf("Input Grid\n");
	for(i = 0 ; i < X_VALUE; i++ )
		scanf( "%s", grid[i] );
}

void countBomb(char grid[][Y_VALUE+1], int numOfBombs[][Y_VALUE])
{
	int i, j, k, l;
	int cnt = 0;

	for (i = 0; i < X_VALUE; i++) {
		for (j = 0; j < Y_VALUE; j++) {
			if (grid[i][j] == '*')
				continue;

			for (k = i - 1; k <= i + 1; k++) {
				for (l = j - 1; l <= j + 1; l++) {
					if (k < 0 || k >= X_VALUE || l < 0 || l >= Y_VALUE) //������ ��� ���
						continue;

					if (k == i && l == j) //���� ��ġ�� ����
						continue;

					if(grid[k][l] == '*') //���ڸ� ã�� ���
						cnt++;
				}
			}

			numOfBombs[i][j] = cnt;
			cnt = 0;
		}
	}
}

void display_numOfBombs(char grid[][Y_VALUE+1], int numOfBombs[][Y_VALUE])
{
	int i, j;
	for (i = 0; i < X_VALUE; i++) {
		for (j = 0; j < Y_VALUE; j++)
			if (grid[i][j] == '*')
				printf("*");
			else
				printf("%d", numOfBombs[i][j]);
		printf("\n");
	}
}

int main(void)
{
	char grid[X_VALUE][Y_VALUE+1]; //���ڿ��� ��� �������� NULL�� ���� �ϹǷ�
									// 5X5 �迭�� �ƴ� 5X6 �迭�� �Ǿ�� �Ѵ�.
	int numOfBombs[X_VALUE][Y_VALUE] = {0}; //������ ������ �ִ� ������ 5X5 �迭
	
	readBombInfo(grid);
	countBomb(grid, numOfBombs);
	display_numOfBombs(grid, numOfBombs);
}
