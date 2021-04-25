/* 
    Author: Chen Liang
    Description: Tic tac toe game
    Date 31-March-2021
 */
#include <stdio.h>

#define BOARD_POSITIONS 9

int check_for_win(int player_no, char (*position)[])
{
    char c = 'x';
    _Bool game_complete = 0;

    if (player_no == 0)
        c = 'x';
    else
        c = 'o';

   if ((*position)[0] == c && (*position)[1] == c && (*position)[2] == c)
        game_complete = 1;
    else if ((*position)[0] == c &&  (*position)[3] == c && (*position)[6] == c)
        game_complete = 1;
    else if ((*position)[0] == c &&  (*position)[4] == c && (*position)[8] == c)
        game_complete = 1;
    else if ((*position)[1] == c &&  (*position)[4] == c && (*position)[7] == c)
        game_complete = 1;
    else if ((*position)[2] == c &&  (*position)[4] == c && (*position)[6] == c)
        game_complete = 1;
    else if ((*position)[2] == c &&  (*position)[5] == c && (*position)[8] == c)
        game_complete = 1;
    else if ((*position)[3] == c &&  (*position)[4] == c && (*position)[5] == c)
        game_complete = 1;
    else if ((*position)[6] == c &&  (*position)[7] == c && (*position)[8] == c)
        game_complete = 1;

    return game_complete;
}

void draw_board(char (*position)[])
{
    printf("\e[1;1H\e[2J"); //  clear screen
    printf("\n\tTic Tac Toe\n\n");
    printf("Player 1 (x)  -  Player 2 (o)\n\n");
    printf("     |     |    \n");
    printf("  %c  |  %c  |  %c \n", (*position)[0], (*position)[1], (*position)[2]);
    printf("_____|_____|_____\n");
    printf("     |     |    \n");
    printf("  %c  |  %c  |  %c \n", (*position)[3], (*position)[4], (*position)[5]);
    printf("_____|_____|_____\n");
    printf("     |     |    \n");
    printf("  %c  |  %c  |  %c \n", (*position)[6], (*position)[7], (*position)[8]);
    printf("     |     |    \n\n");
}

void mark_board(int player_no, int selected_postion, char (*position)[])
{
    if (player_no == 0)
        (*position)[selected_postion - 1] = 'x';
    else
        (*position)[selected_postion - 1] = 'o';
}

int main(void)
{
    _Bool game_complete = 0;
    _Bool invalid_input = 0;
    int player[2] = {1, 2};
    int player_no = 1;
    int select_position = 0;
    int i;
    int no_of_filt_positions = 0;
    char position[BOARD_POSITIONS] = {  '1', '2', '3',
                                        '4', '5', '6',
                                        '7', '8', '9'};
    /*
        Game will go on as long as:
            1. It's not complete
            2. All positions aren't filt
     */
    while (!game_complete && no_of_filt_positions < 9)
    {
        if (player_no == 0)
            player_no = 1;
        else
            player_no = 0;

        draw_board(&position);
        printf("Player %d, enter a number: ", player[player_no]);
        do
        {
            scanf("%d", &select_position);
            if (select_position < 1 || select_position > 9)
            {
                printf("Invalid input. Try again: ");
                invalid_input = 1;
            }
            else if (position[select_position - 1] == 'x' ||
                    position[select_position - 1] == 'o')
            {
                printf("Postion already taken. Try again: ");
                invalid_input = 1;
            }
            else
                invalid_input = 0;

        // Won't skip player with an invalid input
        } while (invalid_input && !game_complete);

        mark_board(player_no, select_position, &position);

        game_complete = check_for_win(player_no, &position);

        no_of_filt_positions = 0;

        for (i=0; i<BOARD_POSITIONS; i++)
        {
            if(position[i] == 'x' || position[i] == 'o')
                no_of_filt_positions++;
        }
    }

    draw_board(&position);

    if (game_complete)
        printf("=> Player %d win!\n", player[player_no]);
    else
        printf("=> Draw!\n");

    return 0;
}
