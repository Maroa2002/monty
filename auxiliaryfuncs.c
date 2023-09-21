#include "monty.h"

/**
  * is_int - checks for integer
  * @str: input string
  * Return: 0 if is integer, else -1
  **/

int is_int(const char *str)
{
	int i = 0;

	if (*str == '-')
		i = 1;
	for (; *(str + i) != '\0'; i++)
	{
		if (isdigit(*(str + i)) == 0)
			return (-1);
	}
	return (0);
}

/**
  * free_mem - frees the stack
  * @stack: doubly linked implementation of the stack
  * Return: Nothing
  **/

void free_mem(stack_t *stack)
{
	stack_t *tmp, *ptr = stack;

	while (ptr != NULL)
	{
		tmp = ptr;
		ptr = ptr->next;
		free(tmp);
	}
}
