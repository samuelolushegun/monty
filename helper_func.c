#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * free_stack - Frees the memory allocated for a stack.
 * @stack: Pointer to the top of the stack.
 *
 * This function iterates through the stack and frees each individual node,
 * releasing the memory that was allocated for the stack nodes.
 * After this function is called, the stack pointer is reset to NULL to
 * indicate an empty stack.
 */
void free_stack(stack_t **stack)
{
	stack_t *currentNode = *stack;

	while (currentNode)
	{
		stack_t *temp = currentNode;

		currentNode = currentNode->next;

		free(temp);
	}

	*stack = NULL;
}

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
