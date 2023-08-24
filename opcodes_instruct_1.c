#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

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

void nop(stack_t **stack, unsigned int line_number, void *data)
{
	(void)data;
	(void)stack;
	(void)line_number;
}
