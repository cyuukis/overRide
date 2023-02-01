 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h> 

char    a_user_name[100];

int verify_user_pass(const char *pass)
{
    return strncmp(a_user_name, "admin", 5);
}

int verify_user_name()
{
    puts("verifying username....\n");
    return strncmp(a_user_name, "dat_wil", 7);
}

int main(int argc, char **argv)
{
    char str_pass[0x40];
    int i;

    memset(str_pass, 0, 0x40);
    i = 0;
    puts("********* ADMIN LOGIN PROMPT *********");
    printf("Enter Username: ");

    fgets(a_user_name, 0x100, stdin);
    i = verify_user_name();
    if (i == 0)
    {
        puts("Enter Password: ");

        fgets(str_pass, 0x64, stdin);
        i = verify_user_pass(str_pass);
        if (i != 0)
        {
            if (i != 0)
            {
                puts("nope, incorrect password...\n");
            }
            return 1;
        }
    }
    else
    {
        puts("nope, incorrect username...\n");
        return 1;
    }
    return 0;
}