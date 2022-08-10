#include "main.h"
/**
 * _strlen - Calculates length of given string
 * @str: the given string
 *
 * Return: the length of the string or -1 if failed
 */
int _strlen(char *str)
{
	int len;

	for (len = 0; str[len]; len++)
	;
	return (len);
}

/**
 * _print - prints a string to stdout
 *
 * @stringOut: string to be printed
 * Return: 0 if success or -1 otherwise
 */
void _print(char *stringOut)
{
write(STDOUT_FILENO, stringOut, _strlen(stringOut));
}

/**
 * _strdup - dupicates string
 * @str: the given string
 *
 * Return: address of duplicated string or Null
 */
char *_strdup(char *str)
{
	char *dupl;

	if (str == NULL)
		return (NULL);
	dupl = malloc(_strlen(str) + 1);
	if (dupl == NULL)
		return (NULL);
	_strcpy(dupl, str);
	return (dupl);
}

/**
 * array_rev - reverse array
 * @arr: the given array
 * @len: the array length
 *
 * Return: void
 */
void array_rev(char *arr, int len)
{
	int i;
	char tmp;

	for (i = 0; i < (len / 2); i++)
	{
		tmp = arr[i];
		arr[i] = arr[(len - 1) - i];
		arr[(len - 1) - i] = tmp;
	}
}

/**
 * _strcpy - copie a string from source to destination
 * @source: the string source
 * @dest: the string destination
 *
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *source)
{
	int i;

	for (i = 0; source[i] != '\0'; i++)
	{
		dest[i] = source[i];
	}
	dest[i] = '\0';
	return (dest);
}
