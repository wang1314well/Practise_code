#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

	struct msgbuf
	{
		long type;
		char data[32];
	};
int main()
{
	int i = 10;
	struct msgbuf msg;
	int msgid;
	key_t key;
	key = ftok(".",200);
	if(key == -1)
	{
		printf("ftok error :  %m \n");
		exit(-1);
	}
	msgid = msgget(key,0);
	if(msgid == -1)
	{
		printf("msgget error :  %m \n");
		exit(-1);
	}
	while(1)
	{
		bzero(&msg,sizeof(msg));
		msg.type = 1;
		msgrcv(msgid,&msg.data,sizeof(msg.data),1,0);
		printf("%s\n",msg.data);
	}
/*	if((msgsnd(msgid,&msg,)) <0)
	{
		printf("send error %m\n");
		exit(-1);
	}

	for(i = 0;i<10;i++)
	{
		msg.type = 1;
		bzero(msg.data,sizeof(msg.data));
		sprintf(msg.data,"Message :%d",i);
		msgsnd(msgid,&msg,strlen(msg.data),0);
	}
	for(i = 0;i<10;i++)
	{
		msg.type = 1;
		bzero(msg.data,sizeof(msg.data));
		sprintf(msg.data,"MessageII :%d",i);
		msgsnd(msgid,&msg,strlen(msg.data),0);
	}  */
//	msgctl(msgid,IPC_RMID,0);
	exit(0);
}
