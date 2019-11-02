#include <stdio.h>
#define WHITE 0
#define BLACK 1
#define YELLOW 2

#define WIDTH 10
#define HEIGHT 10

int screen[WIDTH][HEIGHT] = {
	 WHITE, WHITE, WHITE, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,
	 BLACK, BLACK, WHITE, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,
	 BLACK, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, BLACK, BLACK, BLACK,
	 BLACK, BLACK, BLACK, BLACK, WHITE, BLACK, WHITE, BLACK, BLACK, BLACK,
	 BLACK, BLACK, BLACK, BLACK, WHITE, BLACK, WHITE, BLACK, BLACK, BLACK,
	 BLACK, BLACK, WHITE, WHITE, WHITE, BLACK, WHITE, WHITE, WHITE, BLACK,
	 BLACK, BLACK, BLACK, BLACK, WHITE, BLACK, WHITE, BLACK, BLACK, BLACK,
	 BLACK, BLACK, BLACK, BLACK, WHITE, BLACK, WHITE, BLACK, WHITE, BLACK,
	 BLACK, BLACK, BLACK, BLACK, WHITE, BLACK, BLACK, BLACK, WHITE, BLACK,
	 BLACK, BLACK, BLACK, BLACK, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE
};

void display()
{
	int x, y;
	for (x = 0; x < WIDTH; x++) {
		for (y = 0; y < HEIGHT; y++)
			printf("%3d", screen[x][y]);
		printf("\n");
	}
}

void flood_fill(int x, int y)
{
	if (x == -1) return;
	if (y == -1) return;
	if (x == HEIGHT) return;
	if (y == WIDTH) return;
	if (screen[x][y] != WHITE) return;

	screen[x][y] = YELLOW;

	flood_fill(x+1, y);
	flood_fill(x-1, y);
	flood_fill(x, y-1);
	flood_fill(x, y+1);
}

int main(void)
{
	int startX = 0, startY = 0;
	printf("미로:\n");
	display();

	flood_fill(startX, startY);

	printf("\n시작점을 (%d %d)으로 한 미로방문(순서표기):\n", startX, startY);
	display();
}