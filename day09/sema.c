#include <stdio.h>
#include <unistd.h>
#include <sys/sem.h>
#include <sys/ipc.h>
#include <stdlib.h>

union semun
{
	int val;
	struct semid_ds *buf;
	unsigned short 	*array;
	struct seminfo	*_buf;
};

int main()
{
	union semun v;
	
	int semid;
	key_t key;
	key = ftok(".",98);
	int r;
	struct sembuf op[1];
//	if((semid = semget(key,1,IPC_CREAT|IPC_EXCL|0666)) < 0)
	if((semid = semget(key,1,0)) < 0)
	{
		printf("semget error : %m\n");
		exit(-1);
	}
	printf("id : %d\n",semid);
	v.val = 2;
	if((r = semctl(semid,0,SETVAL,v)) < 0)
	{
		printf("semctl error %m\n");
		exit(-1);
	}
	op[0].sem_num = 0;
	op[0].sem_op = -2;
	op[0].sem_flg = 0;
	while(1)
	{
		if((r = semop(semid,op,1)) < 0)
		{
			printf("error %m\n");
			exit(-1);
		}
		printf("detele zushe\n");
	}
	exit(0);
}
