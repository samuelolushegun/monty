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
