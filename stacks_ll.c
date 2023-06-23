#include "monty.h"

/**
 * add_dnodeint - add a node to the beginning of dlist h
 * @head: address of head of list
 * @n: data for the node
 *
 * Return: address of new node or NULL
 */

stack_t *add_dnodeint(stack_t **head, int n)
{
	stack_t *mal;

	if (!head)
		return (NULL);

	mal = malloc(sizeof(stack_t));

	if (mal == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	mal->n = n;
	mal->prev = NULL;
	mal->next = *head;
	if (*head != NULL)
		(*head)->prev = mal;
	*head = mal;
	return (mal);
}

/**
 * add_dnodeint_end - add new node to end of list h
 * @head: address to head of the list
 * @n: data of the node
 *
 * Return: address of the new element or NULL
 */

stack_t *add_dnodeint_end(stack_t **head, int n)
{
	stack_t *mal, *current;

	if (!head)
		return (NULL);
	mal = malloc(sizeof(stack_t));

	if (mal == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	mal->n = n;
	mal->next = NULL;

	if (*head == NULL)
	{
		mal->prev = NULL;
		*head = mal;
		return (mal);
	}

	current = *head;
	while (current->next != NULL)
		current = current->next;

	current->next = mal;
	mal->prev = current;
	return (mal);
}
