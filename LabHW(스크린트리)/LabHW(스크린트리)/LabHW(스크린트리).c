#include <stdio.h>
#define MAX_LEVEL 5
#define MAX_WIDTH 70
char screen[MAX_LEVEL][MAX_WIDTH];

void draw_tree(int row, int left, int right)
{
	int mid;

	if (right - left < 2) 
		return;

	mid = (right + left) / 2;

	//printf("**Å×½ºÆ® %d %d %d %d\n", row, left, right, mid);

	screen[row][mid] = 'X';
	draw_tree(row + 1, left, mid - 1);
	draw_tree(row + 1, mid + 1, right);
}

int main(void)
{
	int i, j, w;
	
	printf("Enter a width(<= 70) of a screen: ");
	scanf("%d", &w);

	for(i = 0; i < MAX_LEVEL; i++)
	{
		for(j = 0; j < MAX_WIDTH; j++)
			screen[i][j] = '-';
	}

	draw_tree(0, 0, w);

	for(i = 0; i < MAX_LEVEL; i++)
	{
		for(j = 0; j < w; j++)
			printf("%c", screen[i][j]);
		printf("\n");
	}
}