#include "monty.h"

/**
 * main - Entry point to intepreter
 * @ac: Argument count
 * @av: Arugument vector
 * Return: 0(Success)
 */

int main(int ac, char **av)
{
	const char *file_name = av[1];
	data_t file_contents;
	
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	file_contents = read_monty_file(file_name);
	execute_instructions(file_contents);
	free_data_t(file_contents);

	return (EXIT_SUCCESS);
}
