#include "monty.h"

/**
 * find_instruction - Finds instruction function to execute
 * @opcode: The opcode string
 * @stack: A pointer to a stack of instructions
 * @line_number: The current line number
 * @argument: instruction argument
 */
void find_instruction(char *opcode, stack_t **stack,
		      unsigned int line_number, char *argument)
{
	int n = 0;
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	(void) argument;
	while (instructions[n].opcode != NULL)
	{
		if (strcmp(opcode, instructions[n].opcode) == 0)
		{
			instructions[n].f(stack, line_number);
			return;
		}
		n++;
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}

/**
 * execute_instructions - executes lines of a monty file
 * @file_content: component of data_t structure
 */
void execute_instructions(data_t file_contents)
{
	stack_t *stack = NULL;
	stack_t *temp;
	int n;

	char *line, *opcode, *argument;

	for (n = 0; n < file_contents.count; n++)
	{
		line = file_contents.lines[n];
		opcode = strtok(line, " \t\n");
		if (opcode == NULL || opcode[0] == '#')
			continue;

		argument = strtok(NULL, "\t\n");

		find_instruction(opcode, &stack, n + 1, argument);
	}

	while (stack != NULL)
	{
		temp = stack->prev;
		free(stack);
		stack = temp;
	}
}
