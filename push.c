#include "monty.h"

/**
  * monty_push - pushes an integer onto a stack
  * @stack: doubly linked representation of a stack
  * @line_number: line number in the file
  * Return: Nothing
  **/

void monty_push(stack_t **stack, unsigned int line_number)
{
	stack_t *newNode;

	if (!stack)
		return;

	if (!arg || is_int(arg) == -1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	newNode->n = atoi(arg);
	newNode->prev = NULL;
	newNode->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = newNode;

	*stack = newNode;
}
