#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * insert_node - function to insert a node with value
 * @head: A pointer to the start of the linked list
 * @number: The value stored in new_node
 * Return: the address of new node or NULL if failure
*/

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_node = malloc(sizeof(listint_t));
	listint_t *current = *head;

	if (new_node == NULL)
		return (NULL);

	new_node->n = number;
	new_node->next = NULL;

	if (*head == NULL || (*head)->n >= number)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}
	current = *head;
	while (current->next != NULL && current->next->n < number)
	current = current->next;


	new_node->next = current->next;
	current->next = new_node;

	return (new_node);
}
