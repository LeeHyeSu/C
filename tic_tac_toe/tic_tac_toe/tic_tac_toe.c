#include<stdio.h>

void print_board(char board[][3]) //그림판을 출력하는 함수
{
	int i;

	printf("     0  1  2\n");
	printf("    --------\n");
	for( i = 0; i < 3; i++ )
		printf("%d |  %c  %c  %c\n", i, board[i][0], board[i][1], board[i][2]);
}

void init_board(char board[][3]) //array 초기화하는 함수
{
	int x, y;

	for (x = 0; x < 3; x++)
		for(y = 0; y < 3; y++)
			board[x][y] = ' ';
}

void player_move(char board[][3], char ch) //플레이어의 움직임을 처리하는 함수
{
	int x, y;

	while(1)
	{
		printf("Player %c(행 열): ", ch);
		scanf("%d %d", &x, &y);
		if (x < 0 || 2 < x || y < 0 || 2 < y)
			printf("잘못된 입력입니다. 다시 입력하세요.\n");
		else if (board[x][y] == ' ')
			break;
		else
			printf("중복 입력입니다. 다시 입력하세요.\n");
	}

	board[x][y] = ch;

	print_board(board);
}

char get_winner(char board[][3]) //게임의 승자를 찾는 함수
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

int check_draw(char board[][3]) //비기는 조건을 체크하는 함수
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