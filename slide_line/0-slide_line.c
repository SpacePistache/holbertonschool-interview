#include "slide_line.h"

/**
 * compress_left - moves all non-zero values to the left
 * @line: array of integers
 * @size: size of array
 */
static void compress_left(int *line, size_t size)
{
	size_t i, pos = 0;

	for (i = 0; i < size; i++)
	{
		if (line[i] != 0)
		{
			line[pos] = line[i];
			if (pos != i)
				line[i] = 0;
			pos++;
		}
	}
}

/**
 * compress_right - moves all non-zero values to the right
 * @line: array of integers
 * @size: size of array
 */
static void compress_right(int *line, size_t size)
{
	size_t i, pos = size - 1;

	for (i = size; i-- > 0;)
	{
		if (line[i] != 0)
		{
			line[pos] = line[i];
			if (pos != i)
				line[i] = 0;
			if (pos > 0)
				pos--;
		}
	}
}

/**
 * slide_left - slides and merges left
 * @line: array
 * @size: array size
 */
static void slide_left(int *line, size_t size)
{
	size_t i;

	compress_left(line, size);

	for (i = 0; i + 1 < size; i++)
	{
		if (line[i] && line[i] == line[i + 1])
		{
			line[i] *= 2;
			line[i + 1] = 0;
			i++;
		}
	}

	compress_left(line, size);
}

/**
 * slide_right - slides and merges right
 * @line: array
 * @size: array size
 */
static void slide_right(int *line, size_t size)
{
	size_t i;

	compress_right(line, size);

	for (i = size - 1; i > 0; i--)
	{
		if (line[i] && line[i] == line[i - 1])
		{
			line[i] *= 2;
			line[i - 1] = 0;
			i--;
		}
	}

	compress_right(line, size);
}

/**
 * slide_line - slides and merges an array
 * @line: array of integers
 * @size: number of elements
 * @direction: slide direction
 *
 * Return: 1 on success, 0 on failure
 */
int slide_line(int *line, size_t size, int direction)
{
	if (!line)
		return (0);

	if (direction == SLIDE_LEFT)
		slide_left(line, size);
	else if (direction == SLIDE_RIGHT)
		slide_right(line, size);
	else
		return (0);

	return (1);
}
