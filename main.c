#include "monty.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	stack_t *init_stack;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	FILE *m_file = fopen(argv[1], "r");
	if (m_file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	char line_char[MAX_LINE_LENGTH];
	int line_number = 0;

	while (fgets(line_char, sizeof(line_char), m_file) != NULL)
	{
		line_number++;

		/** if (line_char[strlen(line_char) - 1] == '\n')
		{
			line_char[strlen(line_char) - 1] = '\0';
		} */

		process_line(line_char, line_number);
	}

	fclose(m_file);

	return EXIT_SUCCESS;
}
