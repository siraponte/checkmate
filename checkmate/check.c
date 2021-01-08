#include "checkmate.h"

bool    right_input(char from_x, char from_y, char to_x, char to_y)
{
    char    x_check[] = "12345678";
    char    y_check[] = "abcdefgh";
    bool    from_x_is_here = false;
    bool    to_x_is_here = false;
    bool    from_y_is_here = false;
    bool    to_y_is_here = false;

    for (int i = 0; i < 8; i++)
    {
        if (from_x == x_check[i])
            from_x_is_here = true;
        if (to_x == x_check[i])
            to_x_is_here = true;
        if (tolower(from_y) == y_check[i])
            from_y_is_here = true;
        if (tolower(to_y) == y_check[i])
            to_y_is_here = true;
    }
    if (!from_x_is_here || !to_x_is_here || !from_y_is_here || !to_y_is_here)
        return false;
    return true;
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
		free(chessboard);
        exit (1);
    }
    if (black_dead && !white_dead)
    {
        printf("\nWhite wins\n");
		free(chessboard);
        exit (1);
    }
}
