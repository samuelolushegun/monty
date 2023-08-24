#include "monty.h"
#include <stdio.h>
#include <stdlib.h>


void push(stack_t **stack, unsigned int line_number, void *data)
{
	opcode_data_t *op_data;
	int value;
	stack_t *new_node;

	op_data = (opcode_data_t*)data;
	value = op_data->value;

	if (value == 0)
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
	new_node->prev = NULL;

	if (*stack != NULL)
	{
		(*stack)->prev = new_node; }

	*stack = new_node;
}

void pall(stack_t **stack, unsigned int line_number, void *data)
{
	stack_t *currentNode;

	currentNode = *stack;
	(void)line_number;
	(void)data;

	while (currentNode != NULL)
	{
		printf("%d\n", currentNode->n);
		currentNode = currentNode->next; }
}

void pint(stack_t **stack, unsigned int line_number, void *data)
{
	(void)data;

	if (*stack == NULL)
	{
		fprintf(stderr, "L<%d>: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE); }

	printf("%d\n", (*stack)->n);
}

void pop(stack_t **stack, unsigned int line_number, void *data)
{
	stack_t *temp;

	(void)data;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE); }


	temp = *stack;
	*stack = (*stack)->next;

	if (*stack != NULL)
	{
		(*stack)->prev = NULL; }

	free(temp);
}

void swap(stack_t **stack, unsigned int line_number, void *data)
{
	stack_t *first;
	stack_t *second;


	(void)data;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L<%d>: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE); }


		first = *stack;
		second = (*stack)->next;

		first->next = second->next;
		second->prev = NULL;
		second->next = first;
		first->prev = second;

		*stack = second;
}
