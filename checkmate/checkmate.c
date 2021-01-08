#include "checkmate.h"

void    game(char **chessboard)
{
    int				move_count = 0;
    char			from_x;
    char			from_y;
    char			to_x;
    char			to_y;
    t_coordinates   from_coordinates;
    t_coordinates   to_coordinates;

    while (true)
    {
        check_end(chessboard);

invalid:
        COUNT ? printf("White: ") : printf("Black: ");
        scanf(" %c%c %c%c%*[^\n]", &from_y, &from_x, &to_y, &to_x);
        if (!right_input(from_x, from_y, to_x, to_y))
            ERROR(3, invalid);
        from_coordinates.x = atoi(&from_x) - 1;
        from_coordinates.y = tolower(from_y) - 'a';
        to_coordinates.x = atoi(&to_x) - 1;
        to_coordinates.y = tolower(to_y) - 'a';
        if (!move(chessboard, from_coordinates, to_coordinates, COUNT ? true : false))
			goto invalid;
        move_count++;
        system("clear");
        print(chessboard, COUNT ? true : false);
    }
}

void    players(void)
{
    char    name_1[N] = {[N - 1] = '\0'};
    char    name_2[N] = {[N - 1] = '\0'};

name:
    printf("Enter First Player Name: \n");
    scanf(" %46[^\n]", name_1);
    if (name_1[N - 1] != '\0')
		ERROR(0, name);
    printf("Enter Second Player Name: \n");
    scanf(" %46[^\n]", name_2);
    if (name_2[N - 1] != '\0')
		ERROR(0, name)
    if (!strcmp(name_1, name_2))
		ERROR(1, name);
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
    chessboard = create_chessboard();
    system("clear");
    print(chessboard, true);
    game(chessboard);
	free(chessboard);
}
