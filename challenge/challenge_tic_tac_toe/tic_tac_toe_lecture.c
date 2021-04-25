#include <stdio.h>
#include <stdlib.h>

char square[10] = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int choice, player;

int check_for_win();
void display_board();
void mark_board(char mark);

int main()
{
    int game_status;
    char mark;
    player = 1;

    do
    {
        display_board();

        // Change turns
        player = (player % 2) ? 1 : 2;

        // Get input
        printf("Player %d, enter a number: ", player);
        scanf("%d", &choice);

        // Set the correct character based on player turn
        mark = (player == 1) ? 'X' : 'O';

        // Set board based on user choice or invalid choice
        mark_board(mark);

        game_status = check_for_win();
        player++;

    } while (game_status == -1);

    if (game_status == 1)
        printf("==>\aPlayer %d win!", --player);
    else
        printf("==>\aGame draw");

    return 0;
}

/*
    FUNCTION TO RETURN GAME STATUS
    1 FOR GAME IS OVER WITH RESULT
    -1 FOR GAME IS IN PROGRESS
    0 GAME IS OVER AND NO RESULT
 */

int check_for_win()
{
    int result = 0;

    if (square[1] == square[2] && square[2] == square[3])
        result = 1;
    else if (square[4] == square[5] && square[5] == square[6])
        result = 1;
    else if (square[7] == square[8] && square[8] == square[9])
        result = 1;
    else if (square[1] == square[4] && square[4] == square[7])
        result = 1;
    else if (square[2] == square[5] && square[5] == square[8])
        result = 1;
    else if (square[3] == square[6] && square[6] == square[9])
        result = 1;
    else if (square[1] == square[5] && square[5] == square[9])
        result = 1;
    else if (square[3] == square[5] && square[5] == square[7])
        result = 1;
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3'
                && square[4] != '4' && square[5] != '5' && square[6] != '6'
                && square[7] != '7' && square[8] != '8' && square[9] != '9')
        result = 0;
    else
        result = -1;

    return result;
}

/*
    FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYERS MARK
 */

void display_board()
{
    printf("\e[1;1H\e[2J"); //  clear screen
    printf("\n\tTic Tac Toe\n\n");
    printf("Player 1 (x)  -  Player 2 (o)\n\n");
    printf("     |     |    \n");
    printf("  %c  |  %c  |  %c \n", (square)[1], (square)[2], (square)[3]);
    printf("_____|_____|_____\n");
    printf("     |     |    \n");
    printf("  %c  |  %c  |  %c \n", (square)[4], (square)[5], (square)[6]);
    printf("_____|_____|_____\n");
    printf("     |     |    \n");
    printf("  %c  |  %c  |  %c \n", (square)[7], (square)[8], (square)[9]);
    printf("     |     |    \n\n");
}

/*
    Set the board with the correct character, x or o
    in the correct spot in the array
 */
void mark_board(char mark)
{
    if (choice == 1 && square[1] == '1')
        square[1] = mark;
    else if (choice == 2 && square[1] == '2')
        square[2] = mark;
    else if (choice == 3 && square[1] == '3')
        square[3] = mark;
    else if (choice == 4 && square[1] == '4')
        square[4] = mark;
    else if (choice == 5 && square[1] == '5')
        square[5] = mark;
    else if (choice == 6 && square[1] == '6')
        square[6] = mark;
    else if (choice == 7 && square[1] == '7')
        square[7] = mark;
    else if (choice == 8 && square[1] == '8')
        square[8] = mark;
    else if (choice == 9 && square[1] == '9')
        square[9] = mark;
    else
    {
        printf("Invalid move ");
        player--;
        // getchar();
    }
}
