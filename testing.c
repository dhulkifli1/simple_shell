#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "main.h"

void main(int argc, char **argv)
{
    //printf("My pid is %d count is: %d\n",getpid(),argc);
    printf("Starting program %d\n",getpid());
    if(fork()==0){
        printf("mtotoz %d\n" , getpid());
    }else{
    printf("Matheee %d\n" , getpid());
    }

}
