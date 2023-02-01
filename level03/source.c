 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h> 
 #include <string.h> 

int decrypt(int token)
{
    char	buffer[17];
	*(int *)(&buffer) = 0x757c7d51;
    *(int *)(&buffer + 4) = 0x67667360;
    *(int *)(&buffer + 8) = 0x7b66737e;
    *(int *)(&buffer + 12) = 0x33617c7d;
	
    buffer[16] = 0;
	
    unsigned int	size;
	unsigned int	i;

    size = strlen((char *)buffer);
    i  = 0;

    while (i < size)
    {
        buffer[i] = buffer[i] ^ token;
        ++i;
    }

    if (strncmp(buffer, "Congratulations!", 17) == 0)
    {
        system("/bin/sh");
        printf("1");
    }
    else
    {
        puts("\nInvalid Password");
    }

    return 0;
}

int test(int val, int n)
{
    n = n - val;

    if (n > 21 )
    {
        decrypt(rand());
    }

    decrypt(n);
    decrypt(n);
    decrypt(n);
    decrypt(n);
    decrypt(n);
    decrypt(n);
    decrypt(n);
    decrypt(n);
    decrypt(n);
    decrypt(n);
    decrypt(n);
    decrypt(n);
    decrypt(n);
    decrypt(n);
    decrypt(n);
   

    return 0;
}

int main(int argc, char **argv)
{
    srand(time(0));
    puts("***********************************");
	puts("*\t\tlevel03\t\t**");
	puts("***********************************");
    
    printf("Password:");

    int val;
	scanf("%d", &val);

    test(val, 322424845);
    return 0;
}