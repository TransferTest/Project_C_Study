#include <stdio.h>
#define BLOCK_WIDTH 7
#define BLOCK_HEIGHT 4
#define DISPLAY_WIDTH 36
#define DISPLAY_HEIGHT 21
#define DISPLAY_SIZE 778
void clear(char display[DISPLAY_SIZE])
{
    for (int i = 0; i < DISPLAY_SIZE; i++)
    {
        display[i] = ' ';
    }
    for (int i = 0; i < DISPLAY_HEIGHT; i++)
    {
        display[(DISPLAY_WIDTH + 1) * i + DISPLAY_WIDTH] = '\n';
    }
}
void init_display (char display[DISPLAY_SIZE])
{
    clear(display);
    display[DISPLAY_SIZE - 1] = 0;
}
void overWriteAt(char display[DISPLAY_SIZE], char src[BLOCK_WIDTH + 2], int offset)
{
    for (int i = 0; i < BLOCK_WIDTH + 1; i++)
    {
        display[offset + i] = src[i];
    }
}
void drawAt (char display[DISPLAY_SIZE], int offset_i, int offset_j, int value)
{
    if (value == 0)
    {
        return;
    }
    char value_text[BLOCK_WIDTH + 2] = "*      *";
    char val[4] = {0, 0, 0, 0};
    int offset = 2;
    int v = value;
    int prefix = 0;
    int zeros = 0;
    int l = 4;
    for (int i = 3; i >= 0; i--)
    {
        int c = v%10;
        v = v / 10;
        val[i] = c;
    }
    for (; zeros < 4; zeros++)
    {
        if (val[zeros] != 0) break;
    }
    offset += zeros / 2;
    if (zeros % 2 == 1) offset += 1;
    l -= zeros;
    for (int i = 0; i < l; i++)
    {
        value_text[offset + i] = val[zeros + i] + '0';
    }
    overWriteAt(display, "********", offset_j * (DISPLAY_WIDTH + 1) + offset_i);
    overWriteAt(display, "*      *", (offset_j + 1) * (DISPLAY_WIDTH + 1) + offset_i);
    overWriteAt(display, value_text, (offset_j + 2) * (DISPLAY_WIDTH + 1) + offset_i);
    overWriteAt(display, "*      *", (offset_j + 3) * (DISPLAY_WIDTH + 1) + offset_i);
    overWriteAt(display, "********", (offset_j + 4) * (DISPLAY_WIDTH + 1) + offset_i);
}
void drawBlock (char display[DISPLAY_SIZE], int i, int j, int value)
{
    if (i >= DISPLAY_WIDTH || j >= DISPLAY_HEIGHT)
    {
        printf("Error at drawBlock : index out of bounds i = %d, j = %d\n", i, j);
        return;
    }
    drawAt(display, i * BLOCK_WIDTH, j * BLOCK_HEIGHT, value);
}
void draw (int map[5][5], char display[DISPLAY_SIZE])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            drawBlock(display, i, j, map[i][j]);
        }
    }
    printf("%s\n", display);
}

int main ()
{
    int map[5][5] = {
        2, 0, 0, 0, 2,
        0, 0, 0, 2, 4,
        0, 8, 16, 32, 64,
        0, 128, 512, 1024, 2048
        };
    char display[DISPLAY_SIZE] = {' '};
    init_display(display);
    draw(map, display);
    return 1;
}

