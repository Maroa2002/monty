#include "monty.h"

/**
  * monty_pop - removes the top element of the stack
  * @stack: doubly linked list implementation of a stack
  * @line_number: line in file
  * Return: Nothing
  **/

void monty_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
}
