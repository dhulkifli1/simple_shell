#include "main.h"

/**
 * print_error - prints error
 * @data: the data structure pointer
 *
 * Return: (Success) a positive number
 * ------- (Fail) a negative number
 */
int print_error(cmd_data *data)
{
	char *idx = _itoa(data->index);

	_print("hsh: ");
	_print(idx);
	_print(": ");
	_print(data->args[0]);
	_print(": ");
	_print(data->error_msg);
	free(idx);
	return (0);
}

/**
 * _itoa - convert integer to array
 * @n: the given number
 *
 * Return: a pointer to the null terminated string
 */
char *_itoa(unsigned int n)
{
	int len = 0, i = 0;
	char *s;

	len = intlen(n);
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	*s = '\0';
	while (n / 10)
	{
		s[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	s[i] = (n % 10) + '0';
	array_rev(s, len);
	s[i + 1] = '\0';
	return (s);
}

/**
 * intlen - Determine the number of digit int integer
 * @num: the given number
 *
 * Return: the length of the integer
 */
int intlen(int num)
{
	int len = 0;

	while (num != 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

/**
 * signal_handler - handle the process interrept signal
 * @signo: the signal identifier
 *
 * Return: void
 */
void signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		_print("\n");
		_print(PROMPT);
	}
}
