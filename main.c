#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
#include <string.h>

stack_t *stack = NULL;

void process_instructions(FILE *file, instruction_t *instructions, int
			  num_instructions)
{
	opcode_data_t op_data;
	char line[MAX_LINE_LENGTH];
	unsigned int line_number;
	char *token;

	line_number = 1;
	while (fgets(line, sizeof(line), file))
	{
		char *trimmed_line = line;

		while (*trimmed_line == ' ' || *trimmed_line == '\t')
		{
			trimmed_line++; }
		if (*trimmed_line == '#' || *trimmed_line == '\n')
		{
			line_number++;
			continue; }
		token = strtok(line, " \t\n");
		if (token)
		{
			instruction_t *instruction;

			instruction = find_instruction(token, instructions, num_instructions);
			if (instruction)
			{
				token = strtok(NULL, " \t\n");
				if (token)
				{
					op_data.value = token; }
				else
				{
					op_data.value = NULL; }
				instruction->f(&stack, line_number, &op_data); }
			else
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
				exit(EXIT_FAILURE); }
		}
		line_number++;
	}
}

instruction_t *find_instruction(char *opcode, instruction_t *instructions, int
				num_instructions)
{
	int i;

	for (i = 0; i < num_instructions; i++)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			return (&instructions[i]); }
	}

	return (NULL);
}

/**
 * main - main function for monty
 * @argc: lentgh of argv
 * @argv: array
 *
 * Return: O or 1
 */
int main(int argc, char *argv[])
{
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"nop", nop},
		{"swap", swap},
		{"add", add},
		{"pint", pint},
		{"pop", pop},
		{"sub", sub},
		{"div", div_ide},
		{"mul", mul},
		{"mod", mod}
	};

	FILE *file;
	int num_instructions;

	num_instructions = sizeof(instructions) / sizeof(instructions[0]);

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE); }


	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		free_stack(&stack);
		return (EXIT_FAILURE); }

	process_instructions(file, instructions, num_instructions);

	fclose(file);
	free_stack(&stack);
	return (EXIT_SUCCESS);

}
