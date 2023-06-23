#define _GNU_SOURCE
#include "monty.h"

global_vars my_glob_vars;

/**
 * main - main function to run interpreter logic
 * @ac: number of parameters
 * @av: array of parameters
 *
 * Return: 0 always
 */

int main(int ac, char **av)
{
	char *buffer = NULL, *delim = " \t\n", *token = NULL;
	size_t buff_length = 0;
	int  line_size;
	FILE *file_descriptor;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file_descriptor = fopen(av[1], "r");
	if (!file_descriptor)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	my_glob_vars.num = NULL;
	my_glob_vars.head = NULL;
	my_glob_vars.line_num = 0;
	my_glob_vars.mode = 0;

	line_size = getline(&buffer, &buff_length, file_descriptor);
	while (line_size >= 0)
	{
		my_glob_vars.line_num++;
		token = strtok(buffer, delim);
		if (token && token[0] != '#')
		{
			my_glob_vars.num = strtok(NULL, delim);
			get_op_func(token);
		}
		line_size = getline(&buffer, &buff_length, file_descriptor);
	}
	free(buffer);
	buffer = NULL;
	fclose(file_descriptor);
	free_stack_t(my_glob_vars.head);
	return (0);
}
