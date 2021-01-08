#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define N           46
#define SQUARE      chessboard[i][j]
#define FROM        chessboard[from.x][from.y]
#define TO          chessboard[to.x][to.y]
#define MOVING(x, y)    chessboard[x][y]
#define WHITE       from.x + x[i] == to.x && from.y + y[i] == to.y
#define BLACK       from.x - x[i] == to.x && from.y - y[i] == to.y
#define MOVE        {TO = FROM; FROM = '.'; return ;}
#define WHITE_OK    (islower(TO) || TO == '.')
#define BLACK_OK    (isupper(TO) || TO == '.')


typedef struct      s_coordinates
{
    int x;
    int y;
}               t_coordinates;

int     error()
{
	return (0);
}

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

void    check_end(char **chessboard)
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

bool    right_input(char from_x, char from_y, char to_x, char to_y)
{
    char    x_check[] = "12345678";
    char    y_check[] = "abcdefgh";
    bool    from_x_is_here;
    bool    to_x_is_here;
    bool    from_y_is_here;
    bool    to_y_is_here;

    from_x_is_here = false;
    to_x_is_here = false;
    from_x_is_here = false;
    to_y_is_here = false;
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

void    move_pawn(char **chessboard, t_coordinates from, t_coordinates to, bool is_white)
{
    int     i;
    int     x[] = {1, 2, 1, 1};
    int     y[] = {0, 0, -1, 1};
    
    i = 0;
    if (is_white)
    {
        if (WHITE && TO == '.')
            MOVE
        i++;
        if (WHITE && from.x == 1)
            MOVE
        i++;
        if (WHITE && TO != '.')
            MOVE
        i++;
        if (WHITE && TO != '.')
            MOVE
    }
    else
    {
        if (BLACK && TO == '.')
            MOVE
        i++;
        if (BLACK && from.x == 6)
            MOVE
        i++;
        if (BLACK && TO != '.')
            MOVE
        i++;
        if (BLACK && TO != '.')
            MOVE
    }
}

void    move_rook(char **chessboard, t_coordinates from, t_coordinates to, bool is_white)
{
    int     i;
    
    i = 1;
    if (from.x == to.x)
    {
        while (from.y > to.y ? from.y - i > to.y : from.y + i < to.y)
        {
            if (MOVING(from.x, from.y + (is_white ? i : -i)) != '.')
                exit(1);
            i++;
        }
    }
    else if (from.y == to.y)
    {
        while (from.x > to.x ? from.x - i > to.x : from.x + i < to.y)
        {
            if (MOVING(from.x + (is_white ? i : -i), from.y) != '.')
                exit(1);
            i++;
        }
    }
    if (is_white && WHITE_OK)
        MOVE
    else if (!is_white && BLACK_OK)
        MOVE
}

void    move_knight(char **chessboard, t_coordinates from, t_coordinates to, bool is_white)
{
    int     i;
    int     x[] = {-2, -1, 1, 2, -2, -1, 1, 2};
    int     y[] = {-1, -2, -2, -1, 1, 2, 2, 1};
    
    i = 0;
    while (i < 8)
    {
        if (is_white && WHITE && WHITE_OK)
            MOVE
        if (!is_white && BLACK && BLACK_OK)
            MOVE
        i++;
    }
}

void    move_bishop(char **chessboard, t_coordinates from, t_coordinates to, bool is_white)
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
                    exit(1);
                i++;
            }
        }
        else
        {
            while (from.x - i > to.x && from.y + i < to.y)
            {
                if (MOVING(from.x - i, from.y + i) != '.')
                    exit(1);
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
                    exit(1);
                i++;
            }
        }
        else
        {
            while (from.x + i < to.x && from.y + i < to.y)
            {
                if (MOVING(from.x + i, from.y + i) != '.')
                    exit(1);
                i++;
            }
        }
    }
    if (is_white && WHITE_OK)
        MOVE
    else if (!is_white && BLACK_OK)
        MOVE
}

void    move_king(char **chessboard, t_coordinates from, t_coordinates to, bool is_white)
{
    int     i;
    int     x[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int     y[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    
    i = 0;
    while (i < 8)
    {
        if (is_white && WHITE && WHITE_OK)
            MOVE
        if (!is_white && BLACK && BLACK_OK)
            MOVE
        i++;
    }
}

void    move_queen(char **chessboard, t_coordinates from, t_coordinates to, bool is_white)
{
    int     i;
    
    i = 1;
    if (from.x == to.x)
    {
        while (from.y > to.y ? from.y - i > to.y : from.y + i < to.y)
        {
            if (MOVING(from.x, from.y + (is_white ? i : -i)) != '.')
                exit(1);
            i++;
        }
    }
    else if (from.y == to.y)
    {
        while (from.x > to.x ? from.x - i > to.x : from.x + i < to.y)
        {
            if (MOVING(from.x + (is_white ? i : -i), from.y) != '.')
                exit(1);
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
                    exit(1);
                i++;
            }
        }
        else
        {
            while (from.x - i > to.x && from.y + i < to.y)
            {
                if (MOVING(from.x - i, from.y + i) != '.')
                    exit(1);
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
                    exit(1);
                i++;
            }
        }
        else
        {
            while (from.x + i < to.x && from.y + i < to.y)
            {
                if (MOVING(from.x + i, from.y + i) != '.')
                    exit(1);
                i++;
            }
        }
    }
    if (is_white && WHITE_OK)
        MOVE
    else if (!is_white && BLACK_OK)
        MOVE
}

void    move(char **chessboard, t_coordinates from, t_coordinates to, bool is_white)
{
    if (is_white)
    {
        if (FROM == '.')
            exit(1);
        if (FROM == 'P')
            move_pawn(chessboard, from, to, true);
        else if (FROM == 'R')
            move_rook(chessboard, from, to, true);
        else if (FROM == 'N')
            move_knight(chessboard, from, to, true);
        else if (FROM == 'B')
            move_bishop(chessboard, from, to, true);
        else if (FROM == 'K')
            move_king(chessboard, from, to, true);
        else if (FROM == 'Q')
            move_queen(chessboard, from, to, true);
    }
    else
    {
        if (FROM == '.')
            exit(1);
        if (FROM == 'p')
            move_pawn(chessboard, from, to, false);
        else if (FROM == 'r')
            move_rook(chessboard, from, to, false);
        else if (FROM == 'n')
            move_knight(chessboard, from, to, false);
        else if (FROM == 'b')
            move_bishop(chessboard, from, to, false);
        else if (FROM == 'k')
            move_king(chessboard, from, to, false);
        else if (FROM == 'q')
            move_queen(chessboard, from, to, false);
    }
}

void    game(char **chessboard)
{
    int         move_count = 0;
    char        from_x;
    char        from_y;
    char        to_x;
    char        to_y;
    t_coordinates   from_coordinates;
    t_coordinates   to_coordinates;

    while (true)
    {
        check_end(chessboard);
        if (move_count % 2 == 0)
        {
            printf("White: ");
            scanf(" %c%c %c%c", &from_y, &from_x, &to_y, &to_x);
            if (!right_input(from_x, from_y, to_x, to_y))
                exit(1);
            from_coordinates.x = atoi(&from_x) - 1;
            from_coordinates.y = tolower(from_y) - 'a';
            to_coordinates.x = atoi(&to_x) - 1;
            to_coordinates.y = tolower(to_y) - 'a';
            move(chessboard, from_coordinates, to_coordinates, true);
        }
        else
        {
            printf("Black: ");
            scanf(" %c%c %c%c", &from_y, &from_x, &to_y, &to_x);
            if (!right_input(from_x, from_y, to_x, to_y))
                exit(1);
            from_coordinates.x = atoi(&from_x) - 1;
            from_coordinates.y = tolower(from_y) - 'a';
            to_coordinates.x = atoi(&to_x) - 1;
            to_coordinates.y = tolower(to_y) - 'a';
            move(chessboard, from_coordinates, to_coordinates, false);
        }
        move_count++;
        system("clear");
        print(chessboard, move_count % 2 == 0 ? true : false);
    }
}

char    **create_chessboard(void)
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
}

void    players(void)
{
    char    name_1[N] = {[N - 1] = '0'};
    char    name_2[N] = {[N - 1] = '0'};

    printf("Enter First Player Name: \n");
    scanf(" %46[^\n]", name_1);
    if (name_1[N - 1] != '0')
        exit(1);
    printf("Enter Second Player Name: \n");
    scanf(" %46[^\n]", name_2);
    if (name_2[N - 1] != '0')
        exit(1);
    if (!strcmp(name_1, name_2))
        exit(1);
    srand(time(0));
    if (rand() % 2 == 1)
        printf("\n%s is White\n%s is Black\n", name_1, name_2);
    else
        printf("\n%s is White\n%s is Black\n", name_2, name_1);
    printf("\nPress any key to start");
    scanf("%*c");
    scanf("%*c");
}

int         main(void)
{
    char **chessboard;

    players();
    chessboard = create_chessboard();
    system("clear");
    print(chessboard, true);
    game(chessboard);
	free(chessboard);
}
