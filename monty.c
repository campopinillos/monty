#include "monty.h"
/**
 * main - Get the bytecodes
 * @argc: Number of arguments.
 * @argv: Double pointer of arguments.
 * 
 * Description: Entry point for the Monty 
 * program interpreter
 * Return: 0 if success.
 */
int main(int argc, char **argv)
{
	int check_access;
	FILE *fd;
	if (argc < 2 || argc > 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if ((check_access = access(argv[1], R_OK)) == -1)
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
	return (EXIT_SUCCESS);
}
/**
 * read - Read and get the command
 * @fd: Number of arguments.
 * @file_name: File name.
 * 
 * Description: Read and get the command 
 * for the program interpreter
 * Return: Nothing.
 */
void read_file(FILE *fd, char *file_name)
{
	int n_line = 1, i = 0;
	size_t size_buf = 1;
	char *buffer = NULL, *delim = " \t\n", *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
	stack_t *stack;

	if (!fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}
	while (getline(&buffer, &size_buf, fd) != EOF)
	{
		opcode = strtok(buffer, delim);
		f = opcode_func(opcode);
		if (!f)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", n_line, opcode);
			exit (EXIT_FAILURE);
		}
		f(&stack, n_line);
		n_line++;
	}
	free(buffer);
}

void (*opcode_func(char *s))(stack_t **, unsigned int n_line)
{
	int i = 0, j = 0;
	instruction_t opcodes[] = {
		{"push", op_push}, {"pall", op_pall}, {"pint", op_pint},
		{"pop", op_pop}, {"swap", op_swap}, {"add", op_add},
		{"nop", op_nop}, {NULL, NULL}
	};
	while(opcodes[i].opcode && s)
	{
		j = 0;
		while (opcodes[i].opcode[j] == s[j] && s[j])
			j++;
		if (!opcodes[i].opcode[j] && !s[j])
		{
			return (opcodes[i].f);
		}
		i++;
	}
	return (NULL);
}