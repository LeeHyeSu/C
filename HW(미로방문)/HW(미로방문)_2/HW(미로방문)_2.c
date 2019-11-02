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

int count = 0;
void flood_fill(int x, int y)
{
	if (x < 0 || y < 0 || x > HEIGHT - 1 || y > WIDTH - 1)
		return;

	if (screen[x][y] != WHITE) return;

	count++;
	screen[x][y] = count;
	flood_fill(x, y+1);
	flood_fill(x+1, y);
	flood_fill(x, y-1);
	flood_fill(x-1, y);
}

int main(void)
{
	int startX = 0, startY = 0;
	printf("�̷�:\n");
	display();

	flood_fill(startX, startY);

	printf("\n�������� (%d %d)���� �� �̷ι湮(����ǥ��):\n", startX, startY);
	display();
}