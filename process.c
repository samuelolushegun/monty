#include "monty.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * process_line - dive into line to get and execute opcodes
 * @line: poniter to an array where all char in the line is stored
 * @line_number: nth line of monty source code file
 *
 * Return: Nothing in succes or Exit failure otherwise
 */
void process_line(const char *line, unsigned int line_number)
{
	char *opcode;
	char *token = strtok(line, " \t\n");
	char *opcode = malloc(strlen(token) + 1))
	int tracker = 0;

	if (opcode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (EXIT_FAILURE);
	}

        if (token != NULL)
	{
		strcpy(opcode, token);
		token = strtok(NULL, " \t\n");
		if (token != NULL)
			int arg = atoi(token);
	}
	else
		opcode[0] = '\0';

        for (size_t i = 0; i < sizeof(opcodes_list) / sizeof(opcodes_list[0]); i++)
	{
		if (strcmp(opcode, opcodes_list[i].opcode) == 0)
		{
			instructions[i].f(init_stack, line_number);
			tracker = 1;
			break;
		}
	}
        if (tracker == 0 && opcode[0] != '\0')
	{
		fprintf(stderr, "L%d: unknown instruction %s", line_number, opcode);
		return (EXIT_FAILURE);
	}
}
