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
	shmid = shmget(key,4,IPC_CREAT|IPC_EXCL|0666);
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
	int i= 0;
	while(1)
	{
	//	for(i = 0;i< 100;i++)
		*p = i;
		sleep(1);
		i++;
	}
	shmdt(p);
	shmctl(shmid,IPC_RMID,0);
	exit(0);
}
