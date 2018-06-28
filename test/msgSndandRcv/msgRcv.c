#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/msg.h>
#include <errno.h>

#define MAX_SIZE 1024

struct Msg {
	long int msg_type;
	char buffer[MAX_SIZE];
	int age;
};

int main()
{
	int msgid = -1;
	struct Msg myMsg;
	long int msgType = 0;

	msgid = msgget((key_t)1234, 0666|IPC_CREAT);
	if (msgid == -1)
	{
		printf("Msg init error!\n");
		exit(EXIT_FAILURE);
	}

	while(1)
	{
		msgrcv(msgid, (void *)&myMsg, MAX_SIZE+8, msgType, 0);
		printf("recv:%s\n", myMsg.buffer);
		if (strncmp(myMsg.buffer, "end", 3) == 0) 
			break;
	}

	msgctl(msgid, IPC_RMID, 0);
	exit(EXIT_SUCCESS);
}
