#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "menger.h"

/**
 * fill_menger - recursively fills the Menger sponge pattern
 *
 * @grid: 2D array
 * @x: x coordinate
 * @y: y coordinate
 * @size: current size
 */
void fill_menger(char **grid, int x, int y, int size)
{
    int step;

    if (size == 1)
        return;

    step = size / 3;

    for (int i = x + step; i < x + 2 * step; i++)
    {
        for (int j = y + step; j < y + 2 * step; j++)
            grid[i][j] = ' ';
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i != 1 || j != 1)
                fill_menger(grid, x + i * step, y + j * step, step);
        }
    }
}

/**
 * menger - draws a 2D Menger sponge
 *
 * @level: level of the Menger sponge
 */
void menger(int level)
{
    int size;
    char **grid;

    if (level < 0)
        return;

    size = pow(3, level);

    grid = malloc(sizeof(char *) * size);
    if (grid == NULL)
        return;

    for (int i = 0; i < size; i++)
    {
        grid[i] = malloc(sizeof(char) * size);
        if (grid[i] == NULL)
            return;

        for (int j = 0; j < size; j++)
            grid[i][j] = '#';
    }

    fill_menger(grid, 0, 0, size);

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            putchar(grid[i][j]);

        putchar('\n');
        free(grid[i]);
    }

    free(grid);
}
