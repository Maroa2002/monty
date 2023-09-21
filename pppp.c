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
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_mem(*stack);
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
		free_mem(*stack);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

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
		free_mem(*stack);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
}
