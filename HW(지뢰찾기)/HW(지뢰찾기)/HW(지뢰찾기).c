#include<stdio.h>
#define X_VALUE 5 //2차원 배열의 행의 수
#define Y_VALUE 5 //2차원 배열의 열의 수
void readBombInfo(char grid[][Y_VALUE+1])
{
	int i;	
	// grid 및 지뢰 정보 입력
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
					if (k < 0 || k >= X_VALUE || l < 0 || l >= Y_VALUE) //범위를 벗어난 경우
						continue;

					if (k == i && l == j) //현재 위치는 제외
						continue;

					if(grid[k][l] == '*') //지뢰를 찾은 경우
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
	char grid[X_VALUE][Y_VALUE+1]; //문자열의 경우 마지막에 NULL이 들어가야 하므로
									// 5X5 배열이 아닌 5X6 배열이 되어야 한다.
	int numOfBombs[X_VALUE][Y_VALUE] = {0}; //지뢰의 개수를 넣는 정수형 5X5 배열
	
	readBombInfo(grid);
	countBomb(grid, numOfBombs);
	display_numOfBombs(grid, numOfBombs);
}
