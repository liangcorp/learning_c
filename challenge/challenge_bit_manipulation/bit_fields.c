/* 
    Description: Use bit field to represent a box.
    Attributes:
        opaque: 1
        transparency: 0

        RGB:
            Bit         Decimal     Coloir
            000             0       Black
            001             1       Red
            010             2       Green
            011             3       Yellow
            100             4       Blue
            101             5       Magenta
            110             6       Cyan
            111             7       White

        Show Border: 0 or 1.

        Border:
            Solid: 0
            Dotted: 1
            Dashed: 2      
 */

#include <stdio.h>

struct onscreen_box
{
    unsigned int :4;                    // Padding
    unsigned int transparency:1;        // Transparent or opague
    unsigned int fill_colour:3;         //  RGB
    unsigned int :3;                    //  Padding
    unsigned int show_border:1;         //  Show border?
    unsigned int border_colour:3;       //  RGB
    unsigned int border_style:2;        //  Solid, Dotted or Dashed
};

void display_bits(struct onscreen_box * box)
{
    printf("Transparency: %d\n", box->transparency);
    printf("Filled colour: %d\n", box->fill_colour);
    printf("Show border: %d\n", box->show_border);
    printf("Border colour: %d\n", box->border_colour);
    printf("Border style: %d\n", box->border_style);
}

int main(void)
{
    struct onscreen_box box = {
        .transparency = 1,
        .fill_colour = 3,
        .show_border = 1,
        .border_colour = 2,
        .border_style = 2
    };

    display_bits(&box);

    printf("\n");
    box.transparency = 0;
    box.fill_colour = 7;
    box.show_border = 1;
    box.border_colour = 5;
    box.border_style = 0;

    display_bits(&box);

    return 0;
}