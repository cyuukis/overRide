#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

get_unum()
{

    int i; // ebp - 0xc = ebp - 12
    fflush(stdout);
    scanf("%u", &i);
    clear_stdin();

    return i;
}

clear_stdin() {
    int i; // ebp - 0x9 = ebp - 9
    while(1) {
        i = getchar();
        if (i == 0xa || i == 0xff){
            break;
        }
    }

    return ;
}

prog_timeout() {
   int 0x80 // системное прерывание
}

int store_number(unsigned int * data)
{
	unsigned int input = 0;
	int index = 0;

	printf(" Number: ");
	input = get_unum();

	printf(" Index: ");
	index = (int)get_unum();

	if(index % 3 == 0 || (input >> 24) == 0xb7)
	{
		puts(" *** ERROR! ***\n");
		puts("   This index is reserved for wil!\n");
		puts(" *** ERROR! ***\n");

		return ;
	}

	data[index] = input;

	return ;
}

int read_number(unsigned int * data)
{
	int index = 0;

	printf(" Index: ");
	index = (int)get_unum();

	printf(" Number at data[%d] is %u\n", index, data[index]);

	return 0;
}

int main(int argc, char * argv[], char * envp[])
{
	int res = 0;
	char cmd[20] = {0};
	unsigned int data[STORAGE_SIZE] = {0};

	for (int i = 1 ; argv[i] != NULL; i++)
		memset(argv[i], 0, strlen(argv[i]));

	for (int i = 0 ; envp[i] != NULL; i++)
		memset(envp[i], 0, strlen(envp[i]));

	printf("----------------------------------------------------\n"\
			"  Welcome to doom's crappy number storage service!  \n"\
			"----------------------------------------------------\n"\
			" Commands:                                          \n"\
			"    store - store a number into the data storage    \n"\
			"    read  - read a number from the data storage     \n"\
			"    quit  - exit the program                        \n"\
			"----------------------------------------------------\n"\
			"   wil has reserved some storage for himself :>     \n"\
			"----------------------------------------------------\n"\
			"\n");


	while(1)
	{
		printf("Input command: ");
		res = 1;

		fgets(cmd, sizeof(cmd), stdin);
		cmd[strlen(cmd)-1] = '\0';

		if(!strncmp(cmd, "store", 5))
			res = store_number(data);
		else if(!strncmp(cmd, "read", 4))
			res = read_number(data);
		else if(!strncmp(cmd, "quit", 4))
			break;

		if(res)
			printf(" Failed to do %s command\n", cmd);
		else
			printf(" Completed %s command successfully\n", cmd);

		memset(cmd, 0, sizeof(cmd));
	}

	return;
}