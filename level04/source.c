 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h> 
 #include <string.h> 

int main(int argc, char **argv){

    pid_t pid = fork();

    char buffer[32];
    memset(buffer, 0, 32);

    int ptrace = 0;
    int status = 0;

    if (pid == 0) {
        prctl(1, 1);
        ptrace(0, 0, 0, 0);
        puts("Give me some shellcode, k");
        gets(buffer);
        return(0);
    }

    while(ptrace = ptrace(3, pid, 44, 0) != 11) {
        wait (&status);
        if (status == 127 || status == 128 / 2) {
            puts("child is exiting...");
            return(0);
        }
    }

    puts("no exec() for you");
    kill(pid, 9);
    return
    
    
    (0);
}