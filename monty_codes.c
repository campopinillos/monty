#include "monty.h"
/**
 * mop_push - pushes an element to the stack
 * @stack: Double pointer input
 * @n_line: line number
 *
 * Description: This function pushes an element to the stack.
 * Return: Nothing.
 */
void mop_push(stack_t **stack, unsigned int n_line)
{
	stack_t *node;
	char del[] = " ";
	char *s;
	int n;

	node = malloc(sizeof(stack_t));
	if (!node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	s = strtok(NULL, del);
	if (!s)
	{
		fprintf(stderr, "L%d: usage: push integer\n", n_line);
		exit(EXIT_FAILURE);
	}
	if (*s != 48)
		n = atoi(s);
	if (n == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", n_line);
		exit(EXIT_FAILURE);
	}
	if (*s == 48)
		n = 0;
	node->n = n;
	node->next = *stack;
	node->prev = NULL;
	if (*stack)
		(*stack)->prev = node;
	*stack = node;
}
/**
 * mop_pall - prints all the values on the stack
 * @stack: Double pointer input
 * @n_line: line number
 *
 * Description: prints all the values on the stack,
 * starting from the top of the stack.
 * Return: Nothing.
 */
void mop_pall(stack_t **stack, unsigned int n_line)
{
	int i = 0;
	stack_t *tmp;
	(void) n_line;
	if (!stack || !*stack)
		;
	else
	{
		tmp = *stack;
		while (tmp != NULL)
		{
			i++;
			printf("%d\n", tmp->n);
			tmp = tmp->next;
		}
	}
}
