#include "checkmate.h"

void    print(char **chessboard, bool is_white)
{
    char    x[] = "12345678";
    char    y[] = "abcdefgh";

    if (is_white)
    {
        printf("\tWhite View\n\n");
        for (int i = 7; i >= 0; i--)
        {
            printf("%c\t", x[i]);
            for (int j = 0; j < 8; j++)
            {
                printf("%c", SQUARE);
                printf("    ");
            }
            printf("\n\n");
        }
        printf("\n    ");
        for (int i = 0; i < 8; i++)
            printf("    %c", y[i]);
        printf("\n\n");
    }
    else
    {
        printf("\tBlack View\n\n");
        for (int i = 0; i < 8; i++)
        {
            printf("%c\t", x[i]);
            for (int j = 7; j >= 0; j--)
            {
                printf("%c", SQUARE);
                printf("    ");
            }
            printf("\n\n");
        }
        printf("\n    ");
        for (int i = 7; i >= 0; i--)
            printf("    %c", y[i]);
        printf("\n\n");
    }
}

char    **create_chessboard(void)
{
    char **chessboard;

    chessboard = malloc(8 * sizeof(char **));
    if (!chessboard)
        ERROR(2, nomemory);
    for (int i = 0; i < 8; i++)
    {
        chessboard[i] = malloc(8 * sizeof(char *));
        if (!chessboard[i])
            ERROR(2, nomemory);
    }
    for (int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
            chessboard[i][j] = '.';
    chessboard[0][0] = 'R';
    chessboard[0][1] = 'N';
    chessboard[0][2] = 'B';
    chessboard[0][3] = 'Q';
    chessboard[0][4] = 'K';
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
    chessboard[7][3] = 'q';
    chessboard[7][4] = 'k';
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

nomemory:
	exit(1);
}
