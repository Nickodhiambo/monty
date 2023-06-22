#include "monty.h"

/**
 * execute_instructions - executes lines of a monty file sequentially
 * @opcode: opcode
 * @line_number: Position of a line in file, starting from 1
 * @stack: poniter to the top line
 */
void execute_instructions(char *opcode, unsigned int line_number,
			  stack_t **stack)
{
	int _opcode = 0;
	size_t n;

	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}};

	for (n = 0; instructions[n].opcode != NULL; n++)
	{
		if (strcmp(opcode, instructions[n].opcode) == 0)
		{
			_opcode = 1;
			instructions[n].f(stack, line_number);
			break;
		}
	}

	if (!_opcode)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number,
			opcode);
		exit(EXIT_FAILURE);
	}
}
