 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h> 

int main(int argc, char **argv)
{
    int i;

    puts("***********************************");
    puts("* \t     -Level00 -\t\t  *");
    puts("***********************************");

    printf("Password:");
    scanf("%d", &i);

    if (i != 0x149c)
    {
        puts("\nInvalid Password!");
    }
    else
    {
       puts("\nAuthenticated!");
       system("/bin/sh");
    }

   return 0;
}