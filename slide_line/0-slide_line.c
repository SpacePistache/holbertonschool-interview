#include "slide_line.h"

/**
 * move_left - moves non-zero values to the left
 * @line: array of integers
 * @size: size of array
 */
static void move_left(int *line, size_t size)
{
	size_t i, j;

	j = 0;
	for (i = 0; i < size; i++)
	{
		if (line[i] != 0)
		{
			line[j] = line[i];
			if (i != j)
				line[i] = 0;
			j++;
		}
	}
}

/**
 * move_right - moves non-zero values to the right
 * @line: array of integers
 * @size: size of array
 */
static void move_right(int *line, size_t size)
{
	size_t i, j;

	j = size;
	while (j > 0)
		j--;

	i = size;
	while (i > 0)
	{
		i--;
		if (line[i] != 0)
		{
			line[j] = line[i];
			if (i != j)
				line[i] = 0;
			if (j > 0)
				j--;
		}
	}
}

/**
 * merge_left - merges values to the left
 * @line: array of integers
 * @size: size of array
 */
static void merge_left(int *line, size_t size)
{
	size_t i;

	for (i = 0; i + 1 < size; i++)
	{
		if (line[i] != 0 && line[i] == line[i + 1])
		{
			line[i] *= 2;
			line[i + 1] = 0;
			i++;
		}
	}

	move_left(line, size);
}

/**
 * merge_right - merges values to the right
 * @line: array of integers
 * @size: size of array
 */
/**
 * merge_right - merges values to the right
 * @line: array of integers
 * @size: size of array
 */
static void merge_right(int *line, size_t size)
{
	size_t i;

	i = size - 1;
	while (i > 0)
	{
		if (line[i] != 0 && line[i] == line[i - 1])
		{
			line[i] *= 2;
			line[i - 1] = 0;
			i--;
		}
		i--;
	}

	move_right(line, size);
}

/**
 * slide_line - slides and merges an array
 * @line: array of integers
 * @size: number of elements
 * @direction: direction to slide
 *
 * Return: 1 on success, 0 on failure
 */
int slide_line(int *line, size_t size, int direction)
{
	if (line == NULL || size == 0)
		return (0);

	if (direction == SLIDE_LEFT)
	{
		move_left(line, size);
		merge_left(line, size);
	}
	else if (direction == SLIDE_RIGHT)
	{
		move_right(line, size);
		merge_right(line, size);
	}
	else
	{
		return (0);
	}

	return (1);
}
