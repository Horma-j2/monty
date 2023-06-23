#include "monty.h"

/**
 * _push - add onto a stack
 * @stack: stack to add onto
 * @line_number: current line of file
 */

void _push(stack_t **stack, unsigned int line_number)
{
	if (my_glob_vars.num && is_valid_num(my_glob_vars.num))
	{
		if (my_glob_vars.mode == 0)
			add_dnodeint(stack, atoi(my_glob_vars.num));
		else
			add_dnodeint_end(stack, atoi(my_glob_vars.num));
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * _pall - print all values in a stack
 * @stack: stack to print
 * @line_number: current line of file
 */

void _pall(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *mal = *stack;

	while (stack && mal)
	{
		printf("%d\n", mal->n);
		mal = mal->next;
	}
}

/**
 * _pint - print the top item on the stack
 * @stack: stack to print from
 * @line_number: current line of file
 */

void _pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}


/**
 * _pop - remove the top value in a stack
 * @stack: stack to print
 * @line_number: current line of file
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *mal;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	mal = *stack;
	if ((*stack)->next)
		*stack = (*stack)->next;
	else
		*stack = NULL;
	free(mal);
}

/**
 * _swap - switch positions of two values in a stack
 * @stack: stack to print
 * @line_number: current line of file
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}


	(*stack)->n ^= (*stack)->next->n;
	(*stack)->next->n ^= (*stack)->n;
	(*stack)->n ^= (*stack)->next->n;
}
