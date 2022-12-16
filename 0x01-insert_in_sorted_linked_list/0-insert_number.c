#include "lists.h"
#include <stdlib.h>

/**
 * insert_node - function that inserts a number into a sorted sibly linked list
 * @head: first node
 * @number: int to be inserted
 * Return: success
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_node;
	listint_t *tmp, *tmp_next;

	new_node = malloc(sizeof(listint_t));

	if (new_node == NULL)
		return (NULL);

	if (*head == NULL)
	{
		*head = new_node;
		new_node->n = number;
		return (new_node);
	}
	tmp = *head;
	tmp_next = tmp->next;

	if (tmp->n >= number)
	{
		new_node->next = tmp;
		new_node->n = number;
		*head = new_node;
		return (new_node);
	}

	while (tmp_next != NULL)
	{
		if (tmp->n <= number && tmp_next->n >= number)
		{
			tmp->next = new_node;
			new_node->next = tmp_next;
			new_node->n = number;
			return (new_node);
		}
		tmp = tmp->next;
		tmp_next = tmp_next->next;
	}
	tmp->next = new_node;
	new_node->n = number;
	return (new_node);
}
