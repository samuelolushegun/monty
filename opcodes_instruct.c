#include "monty.h"
#include <stdio.h>
#include <stdlib.h>


void push(stack_t **stack, unsigned int line_number)
{
	int value;
	stack_t *new_node;

	if (value == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer", line_number);
		exit(EXIT_FAILURE); }



	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		exit(EXIT_FAILURE); }

	new_node->n = value;
	new_node->next = *stack;
	*stack = new_node;
}

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *currentNode;

	currentNode = *stack;
	(void)line_number; 

	while (currentNode != NULL)
	{
		printf("%d\n", currentNode->n);
		currentNode = currentNode->next; }
}

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L<%d>: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE); }

	printf("%d\n", *stack->n);
}

void pop(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L<%d>: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE); }

	stack_t *temp;

	temp = *stack;
	*stack = *stack->next;
	*stack->prev = NULL;
	free(temp);
}

void swap(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L<%d>: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);

		stack_t *first;
		stack_t *second;

		first = *stack;
		second = (*stack)->next;

		fist->next = second->next;
		second->prev = NULL;
		second->next = first;
		first->prev = second;

		*stack = second;
}
