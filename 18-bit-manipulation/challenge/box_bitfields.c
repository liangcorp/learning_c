#include <stdio.h>

/* primary color */
#define BLUE 4
#define GREEN 2
#define RED 1

/* mixed colors */
#define BLACK 0
#define YELLOW (RED | GREEN)
#define MAGENTA (RED | BLUE)
#define CYAN (GREEN | BLUE)
#define WHITE (RED | GREEN | BLUE)

struct box {
	unsigned : 6;
	unsigned view : 1;
	unsigned color : 3;
	unsigned show_border : 1;
	unsigned border_color : 3;
	unsigned border_line_style : 2;
};

int main()
{
	struct box my_box = { 1, GREEN, 1, WHITE, 1 };

	char *colors[] = { "black", "red",     "green", "yellow",
			   "blue",  "magenta", "cyan",	"white" };
	char *shown[] = { "shown", "not shown" };
    char *style[] = { "solid", "dotted", "dashed" };

    printf("Orignal box:\n");
	printf("Box is %s\n", my_box.view ? "opaque" : "transparent");
	printf("Box color is %s\n", colors[my_box.color]);
	printf("Box border %s\n", shown[my_box.show_border]);
	printf("Box border color is %s\n", colors[my_box.border_color]);
	printf("Box border line is %s\n", style[my_box.border_line_style]);

	my_box.view = 0;
    my_box.color = BLUE;
    printf("\nModified box:\n");
	printf("Box is %s\n", my_box.view ? "opaque" : "transparent");
	printf("Box color is %s\n", colors[my_box.color]);
	printf("Box border %s\n", shown[my_box.show_border]);
	printf("Box border color is %s\n", colors[my_box.border_color]);
	printf("Box border line is %s\n", style[my_box.border_line_style]);

	return 0;
}
