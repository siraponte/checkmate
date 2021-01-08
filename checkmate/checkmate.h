#ifndef CHECKMATE
# define CHECKMATE

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define N				46

#define SQUARE			chessboard[i][j]
#define FROM			chessboard[from.x][from.y]
#define TO				chessboard[to.x][to.y]
#define MOVING(x, y)    chessboard[x][y]
#define MOVE            {TO = FROM; FROM = '.'; return true;}

#define	COUNT			move_count % 2 == 0
#define WHITE			((from.x + x[i] == to.x && from.y + y[i] == to.y) && is_white)
#define BLACK			((from.x - x[i] == to.x && from.y - y[i] == to.y) && !is_white)
#define WHITE_OK		((islower(TO) || TO == '.') && is_white)
#define BLACK_OK		((isupper(TO) || TO == '.') && !is_white)

#define	ERROR(x, y)		{error(x); goto y;}

typedef struct      s_coordinates
{
    int x;
    int y;
}					t_coordinates;

//move_piece.c
bool	move(char **, t_coordinates, t_coordinates, bool);
bool	move_king(char **, t_coordinates, t_coordinates, bool);
bool	move_pawn(char **, t_coordinates, t_coordinates, bool);
bool	move_rook(char **, t_coordinates, t_coordinates, bool);
bool	move_knight(char **, t_coordinates, t_coordinates, bool);
bool	move_bishop(char **, t_coordinates, t_coordinates, bool);
bool	move_queen(char **, t_coordinates, t_coordinates, bool);

//check.c
bool	right_input(char, char, char, char);
void	check_end(char **);

//chessboard.c
void	print(char **, bool);
char	**create_chessboard(void);

//error.c
void	error(int);

#endif
