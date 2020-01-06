#include "monty.h"
/**
 * main - Get the bytecodes
 * @argc: Number of arguments
 * @argv: Double pointer of arguments
 *
 * Description: Entry point for the Monty
 * program interpreter.
 * Return: 0 if success.
 */
int main(int argc, char **argv)
{
	int check_access;
	FILE *fd;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	check_access = access(argv[1], R_OK);
	if (check_access == -1)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");
	if (!fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	read_file(fd, argv[1]);
	fclose(fd);
	return (EXIT_SUCCESS);
}
/**
 * read_file - Read and get the command
 * @fd: Number of arguments
 * @file_name: File name
 *
 * Description: Read and get the command
 * for the program interpreter.
 * Return: Nothing.
 */
void read_file(FILE *fd, char *file_name)
{
	int n_line = 1;
	size_t size_buf = 1;
	char *buffer = NULL, *delim = " \t\n", *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
	stack_t *stack = NULL;

	if (!fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		fclose(fd);
		exit(EXIT_FAILURE);
	}
	while (getline(&buffer, &size_buf, fd) != EOF)
	{
		opcode = strtok(buffer, delim);
		if (!opcode)
		{
			n_line++;
			continue;
		}
		f = opcode_func(opcode);
		if (!f)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", n_line, opcode);
			free(buffer);
			fclose(fd);
			exit(EXIT_FAILURE);
		}
		f(&stack, n_line);
		n_line++;
	}
	free(buffer);
}

/**
 * opcode_func - Get the opcode function
 * @s: String input
 *
 * Description: This function validates the opcode
 * function to be returned and executed.
 * Return: Nothing.
 */
void (*opcode_func(char *s))(stack_t **stack, unsigned int n_line)
{
	instruction_t opc[] = {
		{"push", mop_push},
		{"pall", mop_pall},
		{"pint", mop_pint},
		{"nop", mop_nop},
		{"pop", mop_pop},
		{"swap", mop_swap},
		{NULL, NULL}
	};
	int i = 0;

	for (; opc[i].opcode; i++)
	{
		if (strcmp(s, opc[i].opcode) == 0)
			return (opc[i].f);
	}
	return (NULL);
}
