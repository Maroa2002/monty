#include "monty.h"

/**
  * monty_pall - prints all the values on the stack
  * @stack: doubly linked list implementation of stack
  * @line_number: line number in the file
  * Return: Nothing
  **/

void monty_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;
	(void)line_number; /* unused variable */

	if (stack == NULL || *stack == NULL)
		return;

	while (ptr != NULL)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}
