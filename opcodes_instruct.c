#include "monty.h"
#include <stdio.h>
#include <stdlib.h>


/**
 * push - push opcode
 * @stack: poniter to a stack
 * @line_number: nth line
 * @data: data will be passed
 *
 * return: Nothing
 */
void push(stack_t **stack, unsigned int line_number, void *data)
{
	opcode_data_t *op_data;
	int value;
	stack_t *new_node;

	op_data = (opcode_data_t *)data;

	if (op_data->value == NULL || !is_all_digits(op_data->value))
	{
		fprintf(stderr, "L%d: usage: push integer", line_number);
		exit(EXIT_FAILURE); }

	value = atoi(op_data->value);

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE); }

	new_node->n = value;
	new_node->next = *stack;
	new_node->prev = NULL;

	if (*stack != NULL)
	{
		(*stack)->prev = new_node; }

	*stack = new_node;
}

/**
 * pall - pall opcode
 * @stack: pointer to a stack
 * @line_number: nth line
 * @data: data will be passed
 *
 * return: Nothing
 */
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

/**
 * pint - pint opcode
 * @stack: pointer to a stack
 * @line_number: nth line
 * @data: data will be passed
 *
 * return: Nothing
 */
void pint(stack_t **stack, unsigned int line_number, void *data)
{
	(void)data;

	if (*stack == NULL)
	{
		fprintf(stderr, "L<%d>: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE); }

	printf("%d\n", (*stack)->n);
}

/**
 * pop - pop opcode
 * @stack: pointer to a stack
 * @line_number: nth line
 * @data: data will be passed
 *
 * return: Nothing
 */
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

/**
 * swap - swap opcode
 * @stack: pointer to a stack
 * @line_number: nth line
 * @data: data will be passed
 *
 * return: Nothing
 */
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
