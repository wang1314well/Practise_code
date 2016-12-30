#include <stdio.h>
#include <unistd.h>
#include <sys/msg.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#define MAX_TEXT 512
struct msg_st
{
	long int msg_type;
	char text[MAX_TEXT];
};

int main()
{
	int running = 1;
	struct msg_st data;
	char buffer[BUFSIZ];
	int msgid = -1;

	msgid = msgget((key_t)1234, 0666 | IPC_CREAT);
	if(msgid == -1)
	{
		fprintf(stderr,"msgget failed with error:%d\n",errno);
		exit(EXIT_FAILURE);
	}

	while(running)
	{
		printf("Enter some text: ");
		fgets(buffer,BUFSIZ,stdin);
		data.msg_type = 1;
		strcpy(data.text,buffer);
		if(msgsnd(msgid,(void*)&data,MAX_TEXT,0) == -1)
		{
			fprintf(stderr,"msgsnd failed\n");
			exit(EXIT_FAILURE);
		}
		if(strncmp(buffer,"end",3) ==0)
			running = 0;
		sleep(1);
	}
	exit(EXIT_SUCCESS);
}
