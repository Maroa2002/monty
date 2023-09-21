#include "monty.h"

/**
  * monty_swap - swaps the top two elements of the stack
  * @stack: doubly linked representation of a stack
  * @line_number: line number in the file
  * Return: Nothing
  **/

void monty_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free_mem(*stack);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->next;
	if (tmp->next != NULL)
	{
		(*stack)->next = tmp->next;
		(*stack)->next->prev = *stack;

	}
	else
	{
		tmp->prev->prev = tmp;
		tmp->prev->next = NULL;
	}
	tmp->prev = NULL;
	tmp->next = *stack;
	(*stack) = tmp;
}

/**
  * monty_nop - doesnt do anything
  * @stack: doubly linked representation of a stack
  * @line_number: line number in the file
  * Return: Nothing
  **/

void monty_nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
