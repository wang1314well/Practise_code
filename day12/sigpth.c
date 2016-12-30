#include <stdio.h>
#include <pthread.h>
#include <signal.h>
#include <unistd.h>

void handle(int s);

void *r1(void *d)
{
	while(1)
	{
		printf("pthread--1 \n");
		sleep(5);
	}
}

void *r2(void *d)
{
	while(1)
	{
		printf("pthread--2\n");
		sleep(1);
		kill(getpid(),SIGUSR1);
	}
}

void handle(int s)
{
	printf("signal\n");
}


int main()
{
	pthread_t t1,t2;
	pthread_create(&t1,0,r1,0);
	pthread_create(&t2,0,r2,0);

	pthread_join(t1,(void**)0);
	pthread_join(t2,(void**)0);
}
