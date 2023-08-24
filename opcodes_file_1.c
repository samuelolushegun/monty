#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

extern instruction_t *opcodes_list[] = {{"push", push}, {"pall", pall},
					{"pint", pint},{"pop",pop},
					{"swap", swap}, {"add", add},
					{"nop", nop}};

void add_opcode(const char *opcode, void (*f)(stack_t **stack, unsigned int line_number))
{
	if (num_opcodes < MAX_OPCODES)
	{
		opcodes_list[num_opcodes] = malloc(sizeof(instruction_t));
		if (opcodes_list[num_opcodes] != NULL)
		{
			opcodes_list[num_opcodes]->opcode = strdup(opcode);
			opcodes_list[num_opcodes]->f = f;
			num_opcodes++;
		} else
		{
			fprintf(stderr, "Error: malloc failed\n");
			return (EXIT_FAILURE);
		}
	} else
	{
		fprintf(stderr, "Error\n");
		return (EXIT_FAILURE);
	}
}

void swap(stack_t **stack, unsigned int line_number) {
	// Implementation of swap instruction
	// Modify the stack as needed
	// Use line_number as required
}

void add(stack_t **stack, unsigned int line_number) {
	// Implementation ofadd instruction
	// Modify the stack as needed
	// Use line_number as required
}

void nop(stack_t **stack, unsigned int line_number) {
	// Implementation of nop instruction
	// not modify the stack
	// Use line_number as required
}
