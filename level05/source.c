 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h> 
 #include <string.h> 

int main(int argc, char **argv){

    char buffer[100];
    int i = 0;

    fgets(buffer, 100, stdin);
    
    i = 0;
    while(buffer[i] != '\n') {
        if (buffer[i] > 64 && buffer[i] <= 90)
            buffer[i] = buffer[i] + 32;
        ++i;
    }
    
    printf(buffer);
    exit(0);
}