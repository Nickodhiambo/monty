#include "monty.h"

/**
 * open_monty_file - Opens a file
 * @file_name: File to be opened
 * Return: Pointer to opened file
 */

FILE *open_monty_file(const char *file_name)
{
	FILE *file = fopen(file_name, "r");

	if (file_name == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}
	return (file);
}

/**
 * read_monty_file - Reads a file
 * @file_name: Monty file to be read
 * Return: data_t structure with lines of code
 */

data_t read_monty_file(const char *file_name)
{
	FILE *file = open_monty_file(file_name);
	data_t file_contents;
	char line[MAX_LINE_LEN];
	int len;

	file_contents.lines = malloc(sizeof(char *) * MAX_LINE_LEN);

	if (file_contents.lines == NULL)
	{
		fclose(file);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	file_contents.count = 0;
	while (fgets(line, MAX_LINE_LEN, file) != NULL)
	{
		len = strlen(line);
		if (line[len - 1] != '\n')
			line[len - 1] = '\0';
		file_contents.lines[file_contents.count] = malloc(sizeof(char) *
				(len + 1));
		if (file_contents.lines[file_contents.count] == NULL)
		{
			fclose(file);
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		strcpy(file_contents.lines[file_contents.count], line);
		file_contents.count++;
	}
	fclose(file);
	return (file_contents);
}

/**
 * free_data_t - Frees memory allocated to data structure data_t
 * @file_contents: Lines in a monty file
 * Return: Nothing
 */

void free_data_t(data_t file_contents)
{
	int i;

	for (i = 0; i < file_contents.count; i++)
	{
		free(file_contents.lines[i]);
	}
	free(file_contents.lines);
}
