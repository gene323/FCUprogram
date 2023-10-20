#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void collatz(int* n){
    printf("%d ", *n);
    if(*n == 1){
        puts("");
        return ;
    } else if (*n % 2 == 0){
        *n /= 2;
        collatz(n);
    } else {
        *n = *n * 3 + 1;
        collatz(n);
    }
}

int main(int argc, char** argv){

    //error checking
    if(argc == 1 || atoi(argv[1]) <= 0){
        fprintf(stderr, "enter a positive number\n");
        return -1;
    }
    int n = atoi(argv[1]);

    pid_t pid;

    pid = fork();
    if(pid == 0){
        printf("child process: %d\n", getpid());
        collatz(&n);
    } else {
        int status;
        pid_t waitpid;
        
        printf("parent process: childpid=%d, mypid=%d\n", pid, getpid());
        waitpid = wait(&status);
        printf("waitpid: %d\n", waitpid);
    }

    printf("end pid: %d\n", getpid());
    return 0;
}
