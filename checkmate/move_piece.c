#include "checkmate.h"

bool	move(char **chessboard, t_coordinates from, t_coordinates to, bool is_white)
{
	bool	erro = false;

	if (FROM == '.')
            ERROR(4, back);
    if (is_white)
    {
        if (FROM == 'P')
            erro = move_pawn(chessboard, from, to, true);
        else if (FROM == 'R')
            erro = move_rook(chessboard, from, to, true);
        else if (FROM == 'N')
            erro = move_knight(chessboard, from, to, true);
        else if (FROM == 'B')
            erro = move_bishop(chessboard, from, to, true);
        else if (FROM == 'K')
            erro = move_king(chessboard, from, to, true);
        else if (FROM == 'Q')
            erro = move_queen(chessboard, from, to, true);
    }
    else
    {
        if (FROM == 'p')
            erro = move_pawn(chessboard, from, to, false);
        else if (FROM == 'r')
            erro = move_rook(chessboard, from, to, false);
        else if (FROM == 'n')
            erro = move_knight(chessboard, from, to, false);
        else if (FROM == 'b')
            erro = move_bishop(chessboard, from, to, false);
        else if (FROM == 'k')
            erro = move_king(chessboard, from, to, false);
        else if (FROM == 'q')
            erro = move_queen(chessboard, from, to, false);
    }
	if (!erro)
		ERROR(3, back);
	return true;

back:
	return false;
}

bool	move_king(char **chessboard, t_coordinates from, t_coordinates to, bool is_white)
{
    int     i;
    int     x[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int     y[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    
    i = 0;
    while (i < 8)
    {
        if (WHITE && WHITE_OK)
            MOVE
        if (BLACK && BLACK_OK)
            MOVE
        i++;
    }
	return false;
}

bool	move_pawn(char **chessboard, t_coordinates from, t_coordinates to, bool is_white)
{
    int     i;
    int     x[] = {1, 2, 1, 1};
    int     y[] = {0, 0, -1, 1};
    
    i = 0;
	while (i < 4)
	{
		if ((WHITE || BLACK) && TO == '.')
			MOVE
		if ((WHITE && from.x == 1) || (BLACK && from.x == 6))
			MOVE
		if ((WHITE || BLACK) && TO != '.')
			MOVE
		i++;
	}
	return false;
}

bool	move_knight(char **chessboard, t_coordinates from, t_coordinates to, bool is_white)
{
    int     i;
    int     x[] = {-2, -1, 1, 2, -2, -1, 1, 2};
    int     y[] = {-1, -2, -2, -1, 1, 2, 2, 1};
    
    i = 0;
    while (i < 8)
    {
        if (WHITE && WHITE_OK)
            MOVE
        if (BLACK && BLACK_OK)
            MOVE
        i++;
    }
	return false;
}

bool	move_rook(char **chessboard, t_coordinates from, t_coordinates to, bool is_white)
{
    int     i;
    
    i = 1;
    if (from.x == to.x)
    {
        while (from.y > to.y ? from.y - i > to.y : from.y + i < to.y)
        {
            if (MOVING(from.x, from.y + (is_white ? i : -i)) != '.')
                return false;
            i++;
        }
    }
    else if (from.y == to.y)
    {
        while (from.x > to.x ? from.x - i > to.x : from.x + i < to.y)
        {
            if (MOVING(from.x + (is_white ? i : -i), from.y) != '.')
                return false;
            i++;
        }
    }
    if (WHITE_OK)
        MOVE
    else if (BLACK_OK)
        MOVE
	return false;
}

bool	move_bishop(char **chessboard, t_coordinates from, t_coordinates to, bool is_white)
{
    int i;
    
    i = 1;
    if (from.x > to.x)
    {
        if(from.y > to.y)
        {
            while (from.x - i > to.x && from.y - i > to.y)
            {
                if (MOVING(from.x - i, from.y - i) != '.')
                     return false;
                i++;
            }
        }
        else
        {
            while (from.x - i > to.x && from.y + i < to.y)
            {
                if (MOVING(from.x - i, from.y + i) != '.')
                     return false;
                i++;
            }
        }
    }
	else
    {
        if(from.y > to.y)
        {
            while (from.x + i < to.x && from.y - i > to.y)
            {
                if (MOVING(from.x + i, from.y - i) != '.')
                     return false;
                i++;
            }
        }
        else
        {
            while (from.x + i < to.x && from.y + i < to.y)
            {
                if (MOVING(from.x + i, from.y + i) != '.')
                     return false;
                i++;
            }
        }
    }
    if (WHITE_OK)
        MOVE
    else if (BLACK_OK)
        MOVE
	return false;
}

bool	move_queen(char **chessboard, t_coordinates from, t_coordinates to, bool is_white)
{
    int     i;
    
    i = 1;
    if (from.x == to.x)
    {
        while (from.y > to.y ? from.y - i > to.y : from.y + i < to.y)
        {
            if (MOVING(from.x, from.y + (is_white ? i : -i)) != '.')
                return false;
            i++;
        }
    }
    else if (from.y == to.y)
    {
        while (from.x > to.x ? from.x - i > to.x : from.x + i < to.y)
        {
            if (MOVING(from.x + (is_white ? i : -i), from.y) != '.')
                 return false;
            i++;
        }
    }
    i = 1;
    if (from.x > to.x)
    {
        if(from.y > to.y)
        {
            while (from.x - i > to.x && from.y - i > to.y)
            {
                if (MOVING(from.x - i, from.y - i) != '.')
                     return false;
                i++;
            }
        }
        else
        {
            while (from.x - i > to.x && from.y + i < to.y)
            {
                if (MOVING(from.x - i, from.y + i) != '.')
					 return false;
                i++;
            }
        }
    }
	else
    {
        if(from.y > to.y)
        {
            while (from.x + i < to.x && from.y - i > to.y)
            {
                if (MOVING(from.x + i, from.y - i) != '.')
                     return false;
                i++;
            }
        }
        else
        {
            while (from.x + i < to.x && from.y + i < to.y)
            {
                if (MOVING(from.x + i, from.y + i) != '.')
                     return false;
                i++;
            }
        }
    }
    if (WHITE_OK)
        MOVE
    else if (BLACK_OK)
        MOVE
	return false;
}
