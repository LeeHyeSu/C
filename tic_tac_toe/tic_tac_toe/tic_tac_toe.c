#include<stdio.h>

void print_board(char board[][3]) //�׸����� ����ϴ� �Լ�
{
	int i;

	printf("     0  1  2\n");
	printf("    --------\n");
	for( i = 0; i < 3; i++ )
		printf("%d |  %c  %c  %c\n", i, board[i][0], board[i][1], board[i][2]);
}

void init_board(char board[][3]) //array �ʱ�ȭ�ϴ� �Լ�
{
	int x, y;

	for (x = 0; x < 3; x++)
		for(y = 0; y < 3; y++)
			board[x][y] = ' ';
}

void player_move(char board[][3], char ch) //�÷��̾��� �������� ó���ϴ� �Լ�
{
	int x, y;

	while(1)
	{
		printf("Player %c(�� ��): ", ch);
		scanf("%d %d", &x, &y);
		if (x < 0 || 2 < x || y < 0 || 2 < y)
			printf("�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ���.\n");
		else if (board[x][y] == ' ')
			break;
		else
			printf("�ߺ� �Է��Դϴ�. �ٽ� �Է��ϼ���.\n");
	}

	board[x][y] = ch;

	print_board(board);
}

char get_winner(char board[][3]) //������ ���ڸ� ã�� �Լ�
{
	int i;

	for(i=0; i<3; i++)
	{
		if( board[0][i] == 'X' && board[1][i] == 'X' && board[2][i] == 'X' ) return 'X';
		if( board[0][i] == 'O' && board[1][i] == 'O' && board[2][i] == 'O' ) return 'O';
	}

	for(i=0; i<3; i++)
	{
		if( board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X' ) return 'X';
		if( board[i][0] == 'O' && board[i][1] == 'O' && board[i][2] == 'O' ) return 'O';
	}

	if( board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X' ) return 'X';
	if( board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O' ) return 'O';
	if( board[0][2] == 'X' && board[1][1] == 'X' &&	board[2][0] == 'X' ) return 'X';
	if( board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O' ) return 'O';

	return ' ';
}

int check_draw(char board[][3]) //���� ������ üũ�ϴ� �Լ�
{
	int r, c;
	
	for(r = 0; r < 3; r++)
		for(c = 0; c < 3; c++)
			if(board[r][c] == ' ')
				return 0;

	return 1;
}

int main(void)
{
	char board[3][3];
	char win, turn = 'O';
	int i;

	init_board(board);
	print_board(board);

	do
	{
		turn = (turn == 'X'? 'O': 'X');
		player_move(board, turn);
		win = get_winner(board);
		if(win == 'O' || win == 'X')
			break;
		if(check_draw(board) == 1)
			break;
	} while(win == ' ');
	
	if(win == 'O')
		printf("Player O wins!\n");
	else if(win == 'X')
		printf("Player X wins!\n");
	else
		printf("Nobody wins!\n");

	return 0;
}