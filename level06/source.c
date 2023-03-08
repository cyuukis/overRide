 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h> 
 #include <string.h> 

int auth(char *buffer, unsigned int num) {

    buffer[strcspn(buffer, "\n")] = 0;
    unsigned int len = strnlen(buffer, 32);

    if (len > 5) {
        if (ptrace(0, 0, 1, 0) == -1) {
            puts("\033[32m.-----------------------------.");
            puts("\033[31m| !! TAMPERING DETECTED !!  |");
            puts("\033[32m.-----------------------------.");
            return (1);
        }

        int hash = (buffer[3] ^ 4919) + 6221293;
        int i = 0;
        while (i < len) {
            if (buffer[i] <= 31) {
                return (1);
            }
            hash += hashing_algo(buffer[i]);
            ++i;
        }
        if (hash != num) {
            return (1);
        }
        return (0);
    }
}

int main(int argc, char **argv) {
    puts("***********************************");
    puts("*\t\tlevel06\t\t  *");
    puts("***********************************");

    printf("-> Enter Login: ");

    char buffer[32];
    fgets(buffer, 32, stdin);

    puts("***********************************");
    puts("***** NEW ACCOUNT DETECTED ********");
    puts("***********************************");

    printf("-> Enter Serial: ");

    unsigned int num;
    scanf("%u", &num);

    if (auth(buffer, num) == 0) {
        puts("Authenticated!");
        system("/bin/sh");
        return (0);
    }
    return (1);
}