#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * is_all_digits - Check if a string consists of digits only.
 * @str: The input string to be checked.
 *
 * Return: 1 if the string consists of digits only, 0 otherwise.
 */
int is_all_digits(const char *str)
{
	while (*str)
	{
		if (!isdigit(*str))
		{
			return (0);
		}
		str++;
	}
	return (1);
}

/**
 * add - add opcode
 * @stack: our stack
 * @line_number: nth line number
 * @data: data for opcode
 */
void add(stack_t **stack, unsigned int line_number, void *data)
{
	stack_t *first;
	stack_t *second;

	(void)data;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE); }


	first = *stack;
	second = (*stack)->next;

	second->n += first->n;

	*stack = second;

	second->prev = NULL;

	free(first);
}

/**
 * nop - nop opcode
 * @stack: our stack
 * @line_number: nth line number
 * @data: data for opcode
 */
void nop(stack_t **stack, unsigned int line_number, void *data)
{
	(void)data;
	(void)stack;
	(void)line_number;
}
