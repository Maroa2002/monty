#include "monty.h"

char *arg = NULL;

/**
  * line_processing - handles line processing of monty files
  * @monty_file: monty bytecode file
  * @file_line: line read
  * @stack: doubli linked implementation of stacks
  * @line_number: line number
  * Return: Nothing
  **/

void line_processing(FILE *monty_file, char *file_line,
		stack_t **stack, unsigned int *line_number)
{
	int i = 0;
	char *tok_opcode;
	instruction_t directives[] = {
		{"push", monty_push}, {"pall", monty_pall},
		{"pint", monty_pint}, {"pop", monty_pop},
		{"swap", monty_swap}, {"add", monty_add},
		{"sub", monty_sub}, {"div", monty_div},
		{"mul", monty_mul}, {"mod", monty_mod},
		{"nop", monty_nop}, {NULL, NULL}
	};

	while (file_line[i] == ' ' || file_line[i] == '\t')
		i++;
	if (file_line[i] == '#')
		return;
	tok_opcode = strtok(file_line, " \t\n\a");
	if (tok_opcode == NULL)
		return;
	arg = strtok(NULL, " \t\n\a");
	while (directives[i].opcode)
	{
		if (strcmp(tok_opcode, directives[i].opcode) == 0)
		{
			directives[i].f(stack, *line_number);
			break;
		}
		i++;
	}
	if (!directives[i].opcode)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", *line_number, tok_opcode);
		free(file_line);
		fclose(monty_file);
		exit(EXIT_FAILURE);
	}
}

/**
  * main - monty bytecode files interpreter
  * @argc: argument count
  * @argv: argument vector
  * Return: Always 0
  **/

int main(int argc, char **argv)
{
	FILE *monty_file = NULL;
	char *file_line = NULL;
	size_t length = 0;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	/* argument check */
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	/* file opening */
	monty_file = fopen(argv[1], "r");
	if (!monty_file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&file_line, &length, monty_file) != -1)
	{
		line_number += 1;
		line_processing(monty_file, file_line, &stack, &line_number);
	}
	free(file_line);
	fclose(monty_file);

	return (0);
}
