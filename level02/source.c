 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h> 
 #include <string.h> 

int main(int argc, char **argv)
{

    char name[100];
    memset(name, 0, 12);

    char key[41]
    memset(key, 0, 5);

    char pass[100]
    memset(pass, 0, 12);

    FILE    *file;    
    int     len;

    file = fopen("/home/users/level03/.pass", "r");
    
    if (!file)
    {
        fwrite("ERROR: failed to open password file\n", 36, 1, stderr());
        exit(1);
    }

    len = fread(key, 1, 41,file);
    key[strcspn(key, "\n")]=0;

    if (len != 41)
    {
        fwrite("ERROR: failed to read password file\n", 36, 1, stderr());
        fwrite("ERROR: failed to read password file\n", 36, 1, stderr());
        exit(1);
    }

    puts("===== [ Secure Access System v1.0 ] =====");
    puts("\\***************************************/");
    puts("| You must login to access this system. |");
    puts("\\**************************************/");
    printf("--[ Username: ");

    fgets(name, 100, stdin);
    name[strcspn(name, "\n")] = 0;

    printf("--[ Password: ");

    fgets(pass, 100, stdin);
    pass[strcspn(pass, "\n")] = 0;

    puts("*****************************************");
    if (strncmp(key, pas, 41) == 0)
    {
            printf("Greetings, %s!\n", name);
            system("/bin/sh");
            return(0);
    }
    printf(name);
    puts(" does not have access!");
    exit(1);
}