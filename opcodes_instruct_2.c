#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * mod - computes the rest of the division of the second top element of
 * the stack by the top element of the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number being processed.
 * @data: Pointer to unused data (not used in this function).
 *
 * Return: Nothing.
 */
void mod(stack_t **stack, unsigned int line_number, void *data)
{
	stack_t *first;
	stack_t *second;

	(void)data;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE); }

	else if ((*stack)->n == 0 || (*stack)->next->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE); }

	else
	{
		first = *stack;
		second = (*stack)->next; }


	second->n %= first->n;

	*stack = second;

	second->prev = NULL;

	free(first);
}
