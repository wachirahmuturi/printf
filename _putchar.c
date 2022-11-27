#include <unistd.h>

/**
  * _putchar - writes the character c to standard output
  * @c: the character to be printed to screen
  *
  * Return: 1 if successful
  * On error: -1 is returned, and error set appropriately
  */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
