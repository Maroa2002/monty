#include "monty.h"

/**
  * monty_swap - swaps the top two elements of the stack
  * @stack: doubly linked representation of a stack
  * @line_number: line number in the file
  * Return: Nothing
  **/

void monty_swap(stack_t **stack, unsigned int line_number)
{
	int tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp;
}
