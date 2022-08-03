#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "main.h"

void main(int argc, char **argv)
{
    printf("My pid is %d count is: %d\n",getpid(),argc);
    if(fork()==0){
        printf("I am the child :%d\n",getpid());
    }else
    {
        //wait(NULL);
        printf("I am the parent :%d\n",getpid());
    }   
}
