#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

void add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE); }

	stack_t *first;
	stack_t *second;

	first = *stack;
	second = (*stack)->next;

	first->n += second->n;

	*stack = second->next;
	if (*stack != NULL)
	{
		(*stack)->prev = NULL; }

	free(second);
}

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
