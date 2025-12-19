#include "lists.h"

/**
 * reverse_list - reverses a singly linked list
 * @head: pointer to head pointer
 *
 * Return: pointer to new head
 */
static listint_t *reverse_list(listint_t *head)
{
	listint_t *prev = NULL, *next = NULL;

	while (head)
	{
		next = head->next;
		head->next = prev;
		prev = head;
		head = next;
	}
	return (prev);
}

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to pointer to head of list
 *
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
	listint_t *slow, *fast;
	listint_t *second_half, *copy_second;
	listint_t *first_half;
	int result = 1;

	if (!head || !*head || !(*head)->next)
		return (1);

	slow = fast = *head;

	/* Find middle */
	while (fast->next && fast->next->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

    /* Reverse second half */
	second_half = reverse_list(slow->next);
	copy_second = second_half;
	first_half = *head;

    /* Compare halves */
	while (second_half)
	{
		if (first_half->n != second_half->n)
		{
			result = 0;
			break;
		}
		first_half = first_half->next;
		second_half = second_half->next;
	}

	/* Restore list */
	slow->next = reverse_list(copy_second);

	return (result);
}
