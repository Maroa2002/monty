#include "monty.h"

/**
  * monty_pint - prints the value at the top of a stack
  * @stack: doubly linked list implementation of a stack
  * @line_number: line in file
  * Return: Nothing
  **/

void monty_pint(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
