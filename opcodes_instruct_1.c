#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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
		free_stack(stack);
		exit(EXIT_FAILURE); }


	first = *stack;
	second = (*stack)->next;

	second->n += first->n;

	*stack = second;

	second->prev = NULL;

	free(first);
}

/**
 * sub - Subtracts the top element from the second element of the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number being processed.
 * @data: Pointer to unused data (not used in this function).
 *
 * Return: Nothing.
 */
void sub(stack_t **stack, unsigned int line_number, void *data)
{
	stack_t *first;
	stack_t *second;

	(void)data;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE); }

	first = *stack;
	second = (*stack)->next;

	second->n -= first->n;

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

/**
 * div_ide - Divides the second element by the top element of the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number being processed.
 * @data: Pointer to unused data (not used in this function).
 *
 * Return: Nothing.
 */
void div_ide(stack_t **stack, unsigned int line_number, void *data)
{
	stack_t *first;
	stack_t *second;

	(void)data;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE); }

	else if ((*stack)->n == 0 || (*stack)->next->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE); }

	else
	{
		first = *stack;
		second = (*stack)->next; }


	second->n /= first->n;

	*stack = second;

	second->prev = NULL;

	free(first);
}

/**
 * mul - Multiplies the second element by the top element of the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number being processed.
 * @data: Pointer to unused data (not used in this function).
 *
 * Return: Nothing.
 */
void mul(stack_t **stack, unsigned int line_number, void *data)
{
	stack_t *first;
	stack_t *second;

	(void)data;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE); }

	first = *stack;
	second = (*stack)->next;

	second->n *= first->n;

	*stack = second;

	second->prev = NULL;

	free(first);
}
