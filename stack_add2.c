#include "monty.h"

/**
 * _add - add top two values in a stack
 * @stack: stack to print
 * @line_number: current line of file
 * Description: Store the result in the second value and discard
 * the top value
 */


void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *mal;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	mal = *stack;
	(*stack)->next->n += (*stack)->n;
	*stack = (*stack)->next;
	free(mal);
}

/**
 * _nop - does absolutely nothing
 * @stack: stack to print
 * @line_number: current line of file
 */

void _nop(__attribute__((unused))stack_t **stack,
	  __attribute__((unused))unsigned int line_number)
{}

/**
 * _sub - subtracts the top two values in a stack
 * @stack: stack to print
 * @line_number: current line of file
 * Description: Store the result in the second value and discard
 * the top value
 */

void _sub(stack_t **stack, unsigned int line_number)
{
	stack_t *mal;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	mal = *stack;
	(*stack)->next->n -= (*stack)->n;
	*stack = (*stack)->next;
	free(mal);
}


/**
 * _div - divide the second value in a stack by the top value
 * @stack: stack to print
 * @line_number: current line of file
 * Description: Store the result in the second value and discard
 * the top value
 */

void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *mal;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	mal = *stack;
	(*stack)->next->n /= (*stack)->n;
	*stack = (*stack)->next;
	free(mal);
}



/**
 * _mul - multipy the second value in a stack with the top value
 * @stack: stack to print
 * @line_number: current line of file
 * Description: Store the result in the second value and discard
 * the top value
 */

void _mul(stack_t **stack, unsigned int line_number)
{
	stack_t *mal;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	mal = *stack;
	(*stack)->next->n *= (*stack)->n;
	*stack = (*stack)->next;
	free(mal);
}
