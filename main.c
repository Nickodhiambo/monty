#include "monty.h"

/**
 * main - Entry point to intepreter
 * @ac: Argument count
 * @av: Arugument vector
 * Return: 0(Success)
 */

int main(int ac, char **av)
{

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	process_monty_file(av[1]);

	return (EXIT_SUCCESS);
}
