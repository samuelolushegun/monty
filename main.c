#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
#include <string.h>

#define num_instructions 7

instruction_t instructions[] = {
	{"push", push},
	{"pall", pall},
	{"nop", nop},
	{"swap", swap},
	{"add", add},
	{"pint", pint},
	{"pop", pop}
};

void process_instructions(FILE *file)
{
	opcode_data_t op_data;
	char line[MAX_LINE_LENGTH];
	unsigned int line_number;

	line_number = 1;

	while (fgets(line, sizeof(line), file))
	{
		char *token = strtok(line, " \t\n");

		if (token)
		{
			instruction_t *instruction;

			instruction = find_instruction(token);
			if (instruction)
			{
				token = strtok(NULL, " \t\n");
				if (token)
				{
					op_data.value = atoi(token); }

				else
				{
					op_data.value = 0; }
		
				instruction->f(&stack, line_number, &op_data); }
			else
			{
				fprintf(stderr, "L%d: unknown instructions %s\n", line_number, token);
				exit(EXIT_FAILURE); }
		}
		line_number++;
	}
}

instruction_t *find_instruction(char *opcode)
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


int main(int argc, char *argv[])
{
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
		return (EXIT_FAILURE); }


	file = fopen(argv[1], "r");
	if (!file)
	{
		perror("Error opening file");
		return (EXIT_FAILURE); }

	process_instructions(file);

	fclose(file);
	return (EXIT_SUCCESS);

}
