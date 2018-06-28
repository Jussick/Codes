#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/msg.h>
#include <errno.h>

#define MAX_SIZE 1024

struct Msg{
	long int msg_type;
	char buffer[MAX_SIZE];
	int age;
};

int main()
{
	int msgid = -1;
	struct Msg myMsg;
	char buffer[MAX_SIZE] = {0};

	msgid = msgget((key_t)1234, 0666|IPC_CREAT);
	if (msgid == -1)
	{
		printf("Msg init error!\n");
		exit(EXIT_FAILURE);
	}

	while(1)
	{
		printf("Plsase input the text:\n");
		myMsg.msg_type = 1;
		fgets(buffer, MAX_SIZE, stdin);
		strcpy(myMsg.buffer, buffer);

		msgsnd(msgid, (void *)&myMsg, MAX_SIZE+8, 0);

		if(strncmp(buffer, "end", 3) == 0) 
			break;

		sleep(1);
	}
	exit(EXIT_SUCCESS);
}
