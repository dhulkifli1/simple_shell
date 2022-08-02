#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<sys/wait.h>
#include "main.h"

void main()
{
    char * input;
    size_t bufSize = 32;
    size_t characters;
    char *argv[] = {"ls"};
    char *envp[] ={NULL};
    while (1)
    {
        printf("#cisfun$ ");
        characters = getline(&input,&bufSize,stdin);
        sanitizeInput(&input);
        if(fork()!=0)
        wait(NULL);
        else{
            if (execve(input,argv,envp) == -1)
                perror("./shell");
        }
    }
    
}

void sanitizeInput(char **input){
    char *tempString = *input;
    while (*tempString)
    {
        //printf(":%d:\n",*tempString);
        if (*tempString == 10)
        *tempString = 0;
        ++tempString;
    }
    
}
