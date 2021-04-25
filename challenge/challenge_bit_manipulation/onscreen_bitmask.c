#include <stdio.h>

long long decimal_to_binary(int n)
{
    int remainder = 0;
    int i = 1;
    long long b_num = 0;

    while (n != 0)
    {
        remainder = n % 2;
        printf("%d\n", remainder);
        n = n / 2;
        b_num += remainder * i;
        i *= 10;
    }
    printf("%lld\n", b_num);
    return b_num;
}

int main(void)
{
    int onscreen_box = 0;

    int mask_transparency = 1;
    int mask_fill_colour = 3;
    int mask_show_border = 1;
    int mask_border_colour = 2;
    int mask_border_style = 2;

    onscreen_box = onscreen_box | (mask_transparency << 13);
    onscreen_box = onscreen_box | (mask_fill_colour << 12);
    onscreen_box = onscreen_box | (mask_show_border << 6);
    onscreen_box = onscreen_box | (mask_border_colour << 5);
    onscreen_box = onscreen_box | (mask_border_style << 2);
    printf("%d\n", onscreen_box);
    printf("%lld\n", decimal_to_binary(onscreen_box));

    return 0;
}
