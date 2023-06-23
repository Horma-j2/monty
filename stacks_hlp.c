#include "monty.h"

/**
 * is_valid_num - checks if value is a number
 * @str: the string to convert
 *
 * Return: 1 for success and 0 for failure
 */

int is_valid_num(char *str)
{
	int i = 0;

	if (str[i] == '-')
		i++;

	while (str[i])
	{
		if (!isdigit(str[i]))
			return (0);
		i++;
	}

	return (1);
}

/**
 * free_stack_t - free memory being used by the stack
 * @head: head of the stack
 */

void free_stack_t(stack_t *head)
{
	stack_t *mal;

	while (head)
	{
		mal = head;
		head = head->next;
		free(mal);
	}
}
