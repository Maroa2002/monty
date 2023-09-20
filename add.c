#include "monty.h"

/**
  * monty_add - adds the top two elements of the stack
  * @stack: doubly linked list implementation of a stack
  * @line_number: line in file
  * Return: Nothing
  **/

void monty_add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	(*stack) = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
