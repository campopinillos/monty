#include "monty.h"
/**
 * _isdigit - Determine if is it a number
 * @c: The evaluated input
 *
 * Description: Determine if is it a number between 0 and 9
 * Return: 0 Value if it works
 */
int _isdigit(char *c)
{
	int num;

	num = atoi(c);
	if (num >= 48 && num <= 57)
		return (1);
	else
		return (0);
}