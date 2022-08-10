#include "main.h"

#define DELIMITER " \n\t\r\a\v"
/**
 * split_line - splits line to tokens
 * @data: a pointer to the struct of data
 *
 * Return: (Success) a positive number
 *         (Fail) a negative number
 */
int split_line(cmd_data *data)
{
	char *token;
	size_t size = TOKENSIZE, new_size, i = 0;

	if (_strcmp(data->line, "\n") == 0)
		return (-1);
	data->args = malloc(size * sizeof(char *));
	if (data->args == NULL)
		return (-1);
	token = strtok(data->line, DELIMITER);
	if (token == NULL)
		return (-1);
	while (token)
	{
		data->args[i++] =  token;
		if (i + 2 >= size)
		{
			new_size = size * 2;
			data->args = _realloc(data->args, size * sizeof(char *),
					new_size * sizeof(char *));
			if (data->args == NULL)
				return (-1);
			size = new_size;
		}
		token = strtok(NULL, DELIMITER);
	}
	data->args[i] = NULL;
	return (0);
}
#undef DELIMITER

/**
 * free_data - frees data
 * @data: the data structure
 *
 * Return: (Success) positive number
 *         (Fail) negative number
 */
int free_data(cmd_data *data)
{
	free(data->line);
	data->line = NULL;
	free(data->args);
	data->args = NULL;
	free(data->cmd);
	data->cmd = NULL;
	free(data->error_msg);
	data->error_msg = NULL;
	return (0);
}


#define DELIMITER ":"
/**
 * parse_line - parses arguments to valid command
 * @data: a pointer to the struct of data
 *
 * Return: (Success) a positive number
 *         (Fail) a negative number
 */
int parse_line(cmd_data *data)
{
	if (is_path_form(data) > 0)
		return (1);
	if (is_builtin(data) > 0)
	{
		if (handle_builtin(data) < 0)
			return (-1);
		return (0);
	}
	is_short_form(data);
	return (1);
}
#undef DELIMITER

/**
 * _strcat - concatenates two string in a path form
 * @first: the first given destination
 * @second: the second given source
 *
 * Return: (Success) to the newly string
 *         (Fail) if it failed
 */
char *_strcat(char *first, char *second)
{
	int len1, len2, i = 0, j = 0;
	char *result;

	len1 = _strlen(first);
	len2 = _strlen(second);
	result = malloc((len1 + len2 + 2) * sizeof(char));
	if (!result)
		return (NULL);
	*result = '\0';
	while (first[j])
		result[i++] = first[j++];
	result[i++] = '/';
	j = 0;
	while (second[j])
		result[i++] = second[j++];
	result[i] = '\0';
	return (result);
}


/**
 * _strchr - locates a character in a given string
 * @str: the given string
 * @c: the given string
 *
 * Return: (Success) a pointer to the first occurence of c
 *         (Fail) return a null pointer
 */
char *_strchr(char *str, char c)
{
	char *ptr;

	if (str == NULL)
		return (NULL);
	for (ptr = str; *ptr; ptr++)
		if (*ptr == c)
			return (ptr);
	return (NULL);
}
