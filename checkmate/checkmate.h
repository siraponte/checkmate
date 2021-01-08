#ifndef CHECKMATE
# define CHECKMATE

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define N					46

#define SQUARE				chessboard[i][j]
#define FROM				chessboard[from.x][from.y]
#define TO					chessboard[to.x][to.y]
#define MOVE_TO(x, y)		chessboard[x][y]

#define	MOVING_BISHOP		(from.x > to.x ? from.x - i > to.x : from.x + i < to.x) && (from.y > to.y ? from.y - i > to.y : from.y + 1 < to.y)
#define	NOT_VALID_BISHOP	(MOVE_TO(from.x > to.x ? from.x - i : from.x + i, from.y > to.y? from.y - i : from.y + i) != '.')

#define	MOVING_ROOK			(from .x == to.x ? (from.y > to.y ? from.y - i > to.y : from.y + i < to.y) : 0 || from.y == to.y ? (from.x > to.x ? from.x - i > to.x : from.x + i < to.y) : 0)
#define	NOT_VALID_ROOK		(MOVE_TO(from.x == to.x ? from.x : from.x + (is_white ? i : -i), from.y == to.y ? from.y : from.y + (is_white ? i : -i)) != '.')

#define MOVE				{TO = FROM; FROM = '.'; return true;}

#define	COUNT				(move_count % 2 == 0)
#define WHITE				((from.x + x[i] == to.x && from.y + y[i] == to.y) && is_white)
#define BLACK				((from.x - x[i] == to.x && from.y - y[i] == to.y) && !is_white)
#define WHITE_OK			((islower(TO) || TO == '.') && is_white)
#define BLACK_OK			((isupper(TO) || TO == '.') && !is_white)

#define	ERROR(x, y)			{error(x); goto y;}

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
