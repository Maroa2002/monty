#include "monty.h"

char *arg = NULL;

/**
  * line_processing - handles line processing of monty files
  * @file: monty bytecode file
  * @line: line read
  * @stack: doubli linked implementation of stacks
  * @line_number: line number
  * Return: Nothing
  **/

void line_processing(FILE *file, char *line,
		stack_t **stack, unsigned int *line_number)
{
	int i = 0;
	char *tok_opcode;
	static instruction_t directives[] = {
		{"push", monty_push},
		{"pall", monty_pall},
		{NULL, NULL}
	};

	tok_opcode = strtok(line, " \t\ni\a");
	if (tok_opcode == NULL)
	{
		return;
	}

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
		fprintf(stderr, "L%d: unknown instruction %s\n", *line_number, tok_opcode);
		free(line);
		fclose(file);
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
	FILE *isFile;
	char *file_line = NULL;
	size_t length = 0;
	ssize_t linesread;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	/* argument check */
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	/* file opening */
	isFile = fopen(argv[1], "r");
	if (isFile == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	linesread = getline(&file_line, &length, isFile);
	while (linesread != -1)
	{
		line_number += 1;
		line_processing(isFile, file_line, &stack, &line_number);
		linesread = getline(&file_line, &length, isFile);
	}
	free(file_line);
	fclose(isFile);

	return (0);
}
