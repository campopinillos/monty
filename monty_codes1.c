#include "monty.h"

/**
 * mop_swap - swaps the top two elements of the stack
 * @stackk: pointer to a list
 * @n_line: line number of op command
 */
void mop_swap(stack_t **stackk, unsigned int n_line)
{
	int x, y;

	if (dlistint_len(*stackk) < 2)
	{
		fprintf(stderr, "L%i: can't swap, stack too short\n", n_line);
		exit(EXIT_FAILURE);
	}
	x = (*stackk)->n;
	y = (*stackk)->next->n;
	(*stackk)->n = y;
	(*stackk)->next->n = x;
}

void mop_add(stack_t **stack, unsigned int n_line)
{
	int n = 0;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		fprintf(stderr, "L%i: can't add, stack too short\n", n_line);
		exit(EXIT_FAILURE);
	}

	n += (*stack)->n;
	mop_pop(stack, n_line);
	(*stack)->n += n;
}
