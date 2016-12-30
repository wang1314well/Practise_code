#include <stdio.h>
#include <pthread.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

pthread_t t1,t2;
sigset_t sigs;

void handle(int s)
{
}

void *r1(void *d)
{
	int s;
	while(1)
	{
		sigwait(&sigs,&s);
		printf("active!\n");
//		pause();
	}
}

void *r2(void *d)
{
	while(1)
	{
		sleep(1);
		pthread_kill(t1,34);
	}
}

int main()
{
	sigemptyset(&sigs);
	sigaddset(&sigs,34);
	signal(34,handle);
	pthread_create(&t1,0,r1,0);
	pthread_create(&t2,0,r2,0);
	pthread_join(t1,(void**)0);
	pthread_join(t2,(void**)0);

}
