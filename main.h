#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>

#define BUFSIZE (256)
#define PROMPT "#cisfun$ "
#define TOKENSIZE 64



/**
 * struct ds_data - Custom data structure to store command
 * details
 *
 * @line: Address of input data
 * @args: the arguments of the command
 * @cmd: the actual command
 * @index: Index of the command run by shell
 * @env: the environnment
 * @error_msg: stores error messages
 *
 * Description: A structure contains all the variables needed to manage
 * the program, memory and accessability
 */
typedef struct ds_data
{
	char *line;
	char **args;
	char *cmd;
	unsigned long int index;
	char *env;
	char *error_msg;
} cmd_data;

/**
 * struct builtin - Manage the builtin functions
 * @cmd: the command line on string form
 * @f: the associated function
 *
 * Description: this struct made to manage builtins cmd
 */
typedef struct builtin
{
	char *cmd;
	int (*f)(cmd_data *data);
} blt_t;

extern char **environ;

char *_resetMemory(char *s, char byt, unsigned int n);
int readInput(cmd_data *data);
char *_strdup(char *str);
void _print(char *stringOut);
int process_cmd(cmd_data *data);
int print_error(cmd_data *data);
char *_itoa(unsigned int n);
int intlen(int num);
void array_rev(char *arr, int len);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void *fill_an_array(void *a, int el, unsigned int len);
char *_memcpy(char *dest, char *src, unsigned int n);
char *_strcpy(char *dest, char *source);
void signal_handler(int signo);

int split_line(cmd_data *data);
int free_data(cmd_data *);
int parse_line(cmd_data *);
char *_strcat(char *first, char *second);
int _strlen(char *str);
char *_strchr(char *str, char c);
int _strcmp(char *s1, char *s2);
char *_getenv(char *path_name);
void index_cmd(cmd_data *data);
int write_history(cmd_data *data);
int _isalpha(int c);

/* -------------and these-----------------*/
int abort_prg(cmd_data *data);
int change_dir(cmd_data *data);
int display_help(cmd_data *data);
int handle_builtin(cmd_data *data);
int check_builtin(cmd_data *data);

int is_path_form(cmd_data *data);
void is_short_form(cmd_data *data);
int is_builtin(cmd_data *data);


#endif
