#include "monty.h"


/**
 * process_monty_file - Opens and reads contents of a file
 * @file_name: Takes monty file as input
 * Return: A data_t structure containing file lines
 */
void process_monty_file(const char *file_name)
{
	FILE *file;
	char line[100];
	unsigned int line_number = 0;
	stack_t *stack = NULL;
	char *opcode;

	file = fopen(file_name, "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), file))
	{
		line_number++;
		opcode = strtok(line, " \n");

		if (opcode && opcode[0] != '#')
		{
			execute_instructions(opcode, line_number, &stack);
		}
	}

	fclose(file);
	free_stack(stack);
}

/**
 * free_stack - frees memory allocated for a stack_t structure
 * @stack: The structure to be freed
 */
void free_stack(stack_t *stack)
{
	stack_t *temp = stack;
	stack_t *next;

	while (temp)
	{
		next = temp->next;
		free(temp);
		temp = next;
	}
}
