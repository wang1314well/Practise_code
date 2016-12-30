#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/shm.h>
#include <stdlib.h>

int main()
{
	int shmid;
	key_t key;
	int *p;
	key = ftok(".",255);
	if(key == -1)
	{
		printf("fotk error :%m\n");
		exit(-1);
	}
	shmid = shmget(key,4,0);
	if(shmid == -1)
	{
		printf("shmget error %m\n");
		exit(-1);
	}
//	shmctl(shmid,IPC_RMID,0);
	p = shmat(shmid,0,0);
	if(p == (int*)-1)
	{
		printf("shmat error %m\n");
		exit(-1);
	}
	int i;
	while(1)
	{
//		for(i = 0;i< 100;i++)
//		*p = i;
		printf("%d\n",*p);
		sleep(1);
	}
//	shmctl(shmid,IPC_RMID,0);
	shmdt(p);
	exit(0);
}
