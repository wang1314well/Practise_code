#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>

void* run(void* data)
{
	while(1)
	{
		printf("I'm the pthread!\n");
		sched_yield();
	}
}

void* run_2(void* data)
{
	while(1)
	{
		printf("I'm the other pthread!\n");
		sched_yield();
	}
}

int main()
{
	pthread_t tid,otid;
	pthread_create(&tid,0,run,0);
	pthread_create(&otid,0,run_2,0);
	while(1)
	{
		printf("I'm the main pthread!\n");
		sched_yield();
	}
//	sleep(1);
	pthread_join(tid,(void**)0);
	pthread_join(otid,(void**)0);
	exit(0);
}
