#include "palindrome.h"

/**
 * is_palindrome - checks if an unsigned long is a palindrome
 * @n: number to check
 *
 * Return: 1 if n is a palindrome, 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long original, reversed;

	original = n;
	reversed = 0;

	while (n > 0)
	{
		reversed = (reversed * 10) + (n % 10);
		n /= 10;
	}

	return (original == reversed);
}
