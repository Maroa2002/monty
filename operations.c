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
		free_mem(*stack);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	(*stack) = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
  * monty_sub - subtracts top element from second top element of stack.
  * @stack: doubly linked list implementation of a stack
  * @line_number: line in file
  * Return: Nothing
  **/

void monty_sub(stack_t **stack, unsigned int line_number)
{
	int subtraction;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		free_mem(*stack);
		exit(EXIT_FAILURE);
	}

	subtraction = (*stack)->next->n - (*stack)->n;
	monty_pop(stack, line_number);
	(*stack)->n = subtraction;
}

/**
  * monty_div - divides second top element by the top element of the stack
  * @stack: doubly linked list implementation of a stack
  * @line_number: line in file
  * Return: Nothing
  **/

void monty_div(stack_t **stack, unsigned int line_number)
{
	int division;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		free_mem(*stack);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_mem(*stack);
		exit(EXIT_FAILURE);
	}

	division = ((*stack)->next->n) / ((*stack)->n);
	monty_pop(stack, line_number);
	(*stack)->n = division;
}

/**
  * monty_mul - multiplies the top two elements of the stack
  * @stack: doubly linked list implementation of a stack
  * @line_number: line in file
  * Return: Nothing
  **/

void monty_mul(stack_t **stack, unsigned int line_number)
{
	int product;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		free_mem(*stack);
		exit(EXIT_FAILURE);
	}

	product = (*stack)->next->n * (*stack)->n;
	monty_pop(stack, line_number);
	(*stack)->n = product;
}

/**
  * monty_mod - finds modulus of the top two elements of the stack
  * @stack: doubly linked list implementation of a stack
  * @line_number: line in file
  * Return: Nothing
  **/

void monty_mod(stack_t **stack, unsigned int line_number)
{
	int modulus;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		free_mem(*stack);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_mem(*stack);
		exit(EXIT_FAILURE);
	}
	modulus = (*stack)->next->n % (*stack)->n;
	monty_pop(stack, line_number);
	(*stack)->n = modulus;
}
