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
