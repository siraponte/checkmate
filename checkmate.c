#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define N 46
#define SQUARE chessboard[i][j]
#define ACTUAL chessboard[row][col]

void	print(char **chessboard)
{
	char	x[] = "abcdefgh";
	char	y[] = "12345678";

	printf("\tWhite View\n\n");
	for (int i = 7; i >= 0; i--)
	{
		printf("%c\t", y[i]);
		for (int j = 7; j >= 0; j--)
		{
			printf("%c", SQUARE);
			printf("    ");
		}
		printf("\n\n");
	}
	printf("\n    ");
	for (int i = 0; i < 8; i++)
		printf("    %c", x[i]);
	printf("\n\n");
	free(chessboard);
}

void	check_end(char **chessboard)
{
	bool white_dead = true;
	bool black_dead = true;
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
			if (SQUARE == 'k')
				black_dead = false;
			if (SQUARE == 'K')
				white_dead = false;
		}
	if (white_dead && !black_dead)
	{
		printf("\nBlack wins\n");
		exit (1);
	}
	if (black_dead && !white_dead)
	{
		printf("\nWhite wins\n");
		exit (1);
	}
	if (white_dead && black_dead)
	{
		printf("\nWTF\n");
		exit (1);
	}
}

bool	right_input(char piece, char x, char y)
{
	char	x_check[] = "abcdefgh";
	char	y_check[] = "12345678";
	char	piece_check[] = "rnbqkp";
	bool	is_here;

	is_here = false;
	for (int i = 0; i < 8; i++)
	{
		if (tolower(x) == x_check[i])
			is_here = true;
	}
	if (!is_here)
		return false;
	is_here = false;
	for (int i = 0; i < 8; i++)
	{
		if (y == y_check[i])
			is_here = true;

	}
	if (!is_here)
		return false;
	is_here = false;
	for (int i = 0; i < 6; i++)
	{
		if (tolower(piece) == piece_check[i])
			is_here = true;

	}
	if (!is_here)
		return false;
	return true;
}

void	move_pawn(char **chessboard, char x, char y, bool white)
{}

void	move_rook(char **chessboard, char x, char y, bool white)
{}

void	move_knight(char **chessboard, char x, char y, bool white)
{}

void	move_bishop(char **chessboard, char x, char y, bool white)
{}

void	move_king(char **chessboard, char x, char y, bool white)
{}

void	move_queen(char **chessboard, char x, char y, bool white)
{}

void	move(char **chessboard, char piece, char x, char y, bool white)
{
	int		row = atoi(&y) - 1;
	int		col = tolower(x) - 'a';

	if (white)
	{
		if (!(ACTUAL == piece))
			exit(1);
		if (piece == 'P')
			move_pawn(chessboard, x, y, true);
		else if (piece == 'R')
			move_rook(chessboard, x, y, true);
		else if (piece == 'N')
			move_knight(chessboard, x, y, true);
		else if (piece == 'B')
			move_bishop(chessboard, x, y, true);
		else if (piece == 'K')
			move_king(chessboard, x, y, true);
		else if (piece == 'Q')
			move_queen(chessboard, x, y, true);
	}
	else
	{
		if (!(ACTUAL == piece))
			exit(1);
		if (piece == 'p')
			move_pawn(chessboard, x, y, false);
		else if (piece == 'r')
			move_rook(chessboard, x, y, false);
		else if (piece == 'n')
			move_knight(chessboard, x, y, false);
		else if (piece == 'b')
			move_bishop(chessboard, x, y, false);
		else if (piece == 'k')
			move_king(chessboard, x, y, false);
		else if (piece == 'q')
			move_queen(chessboard, x, y, false);
	}
}

void	game(char **chessboard)
{
	int		move_count = 0;
	char	piece;
	char	x;
	char	y;

	while (true)
	{
		check_end(chessboard);
		if (move_count % 2 == 0)
		{
			printf("White: ");
			scanf(" %c in %c%c", &piece, &x, &y);
			if (!right_input(piece, x, y))
				exit(1);
			move(chessboard, piece, x, y, true);
		}
		else
		{
			printf("Black: ");
			scanf(" %c in %c%c", &piece, &x, &y);
			if (!right_input(piece, x, y))
				exit(1);
			move(chessboard, piece, x, y, false);
		}
		move_count++;
		print(chessboard);
	}
}

char	**create_chessboard(void)
{
	char **chessboard;

	chessboard = malloc(8 * sizeof(char **));
	if (!chessboard)
		exit(1);
	for (int i = 0; i < 8; i++)
	{
		chessboard[i] = malloc(8 * sizeof(char *));
		if (!chessboard[i])
			exit(1);
	}
	for (int i = 0; i < 8; i++)
		for(int j = 0; j < 8; j++)
			chessboard[i][j] = '.';
	chessboard[0][0] = 'R';
	chessboard[0][1] = 'N';
	chessboard[0][2] = 'B';
	chessboard[0][3] = 'K';
	chessboard[0][4] = 'Q';
	chessboard[0][5] = 'B';
	chessboard[0][6] = 'N';
	chessboard[0][7] = 'R';
	chessboard[1][0] = 'P';
	chessboard[1][1] = 'P';
	chessboard[1][2] = 'P';
	chessboard[1][3] = 'P';
	chessboard[1][4] = 'P';
	chessboard[1][5] = 'P';
	chessboard[1][6] = 'P';
	chessboard[1][7] = 'P';
	chessboard[7][0] = 'r';
	chessboard[7][1] = 'n';
	chessboard[7][2] = 'b';
	chessboard[7][3] = 'k';
	chessboard[7][4] = 'q';
	chessboard[7][5] = 'b';
	chessboard[7][6] = 'n';
	chessboard[7][7] = 'r';
	chessboard[6][0] = 'p';
	chessboard[6][1] = 'p';
	chessboard[6][2] = 'p';
	chessboard[6][3] = 'p';
	chessboard[6][4] = 'p';
	chessboard[6][5] = 'p';
	chessboard[6][6] = 'p';
	chessboard[6][7] = 'p';
	return chessboard;
}

void	players(void)
{
	char	name_1[N] = {[N - 1] = '0'};
	char	name_2[N] = {[N - 1] = '0'};

	printf("Enter First Player Name: \n");
	scanf(" %46[^\n]", name_1);
	if (name_1[N - 1] != '0')
		exit(1);
	printf("Enter Second Player Name: \n");
	scanf(" %46[^\n]", name_2);
	if (name_2[N - 1] != '0')
		exit(1);;
	srand(time(0));
	if (rand() % 2 == 1)
		printf("\n%s is White\n%s is Black\n", name_1, name_2);
	else
		printf("\n%s is White\n%s is Black\n", name_2, name_1);
	printf("\nPress any key to start");
	scanf("%*c");
	scanf("%*c");
}

int		main(void)
{
	char **chessboard;

	players();
	system("clear");
	chessboard = create_chessboard();
	print(chessboard);
	game(chessboard);
}
