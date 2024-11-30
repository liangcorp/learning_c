#include <stdio.h>
#include <stdlib.h>

void draw_board(char *position)
{
	printf("\tTic Tac Toe\n\n");
	printf("Player 1 (X)  -  Player 2 (O)\n\n");
	printf("   |   |   \n");
	printf(" %c | %c | %c\n", position[0], position[1], position[2]);
	printf("___|___|___\n");
	printf("   |   |   \n");
	printf(" %c | %c | %c\n", position[0], position[1], position[2]);
	printf("___|___|___\n");
	printf("   |   |   \n");
	printf(" %c | %c | %c\n", position[0], position[1], position[2]);
	printf("   |   |   \n");
}

int winner(char *p)
{
	int winning_position = -1;

	if (p[0] == p[1] && p[1] == p[2])
		winning_position = 0;
	else if (p[0] == p[4] && p[4] == p[8])
		winning_position = 0;
	else if (p[0] == p[3] && p[3] == p[6])
		winning_position = 0;
	else if (p[1] == p[4] && p[4] == p[7])
		winning_position = 0;
	else if (p[2] == p[4] && p[4] == p[6])
		winning_position = 0;
	else if (p[2] == p[5] && p[5] == p[8])
		winning_position = 0;
	else if (p[3] == p[4] && p[4] == p[5])
		winning_position = 0;
	else if (p[6] == p[7] && p[7] == p[8])
		winning_position = 0;
	else
		winning_position = -1;

	return winning_position;
}

int main()
{
	char positions[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
	int winner_position = -1;
	int input_position = 0;
	char player_mark = 'X';

	int i = 1;

	for (; i < 10; i++) {
		system("cls");
		draw_board(positions);

		if (i % 2 != 0) {
			player_mark = 'X';
			printf("Player 1, enter a number: ");
		} else {
			player_mark = 'O';
			printf("Player 2, enter a number: ");
		}

		scanf("%d", &input_position);
		positions[input_position - 1] = player_mark;

		if ((winner_position = winner(positions)) != -1)
			break;
	}

	system("cls");
	draw_board(positions);

	if (winner_position != -1)
		if (i % 2 != 0)
			printf("==> Player 1 win\n");
		else
			printf("==> Player 2 win\n");
	else
		printf("==> It's a draw");

	return 0;
}
