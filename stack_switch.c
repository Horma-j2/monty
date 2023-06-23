#include "monty.h"

/**
 * _stack - switch dll mode to stack
 * @stack: stack to print
 * @line_number: current line of file
 */


void _stack(__attribute__((unused))stack_t **stack,
	    __attribute__((unused))unsigned int line_number)
{
	my_glob_vars.mode = 0;
}


/**
 * _queue - switch dll mode to queue
 * @stack: stack to print
 * @line_number: current line of file
 */


void _queue(__attribute__((unused))stack_t **stack,
	    __attribute__((unused))unsigned int line_number)
{
	my_glob_vars.mode = 1;
}
