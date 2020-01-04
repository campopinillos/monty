#include "monty.h"
/**
 * _isdigit - Determine if is it a number
 * @c: The evaluated input
 *
 * Description: Determine if is it a number between 0 and 9
 * Return: 1 if it is a number 0 if is not
 */
int _isdigit(char *c)
{
	int i;

	for (i = 0; c[i]; i++)
	{
		if (c[i] < 48 || c[i] > 57)
			return (0);
	}
	return (1);
}
