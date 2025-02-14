#include <cs50.h>
#include <stdio.h>

int askheight(void);
void printhash(int height);

void print_row(int spaces, int bricks);

int main(void)
{
    int height;

    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    for (int i = 0; i < height; i++)
    {
        print_row((height - i - 1), i + 1);
    }
}

void print_row(int spaces, int bricks)
{

    // print spaces
    for (int i = 0; i < spaces; i++)
    {
        printf(" ");
    }

    // print row
    for (int i = 0; i < bricks; i++)
    {
        printf("#");
    }

    printf("\n");
}
