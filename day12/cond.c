#include <stdio.h>
#include <pthread.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

pthread_t t1,t2;
sigset_t sigs;
pthread_cond_t  cond;
pthread_mutex_t m;

void handle(int s)
{
}

void *r1(void *d)
{
	int s;
	while(1)
	{
		pthread_cond_wait(&cond,&m);
//		sigwait(&sigs,&s);
		printf("active!\n");
//		pause();
	}
}

void *r2(void *d)
{
	while(1)
	{
		sleep(1);
		pthread_cond_signal(&cond);
//		pthread_kill(t1,34);
	}
}

int main()
{
	pthread_mutex_init(&m,0);
	pthread_cond_init(&cond,0);

//	sigemptyset(&sigs);
//	sigaddset(&sigs,34);
	signal(34,handle);
	pthread_create(&t1,0,r1,0);
	pthread_create(&t2,0,r2,0);
	pthread_join(t1,(void**)0);
	pthread_join(t2,(void**)0);
	pthread_cond_destroy(&cond);
	pthread_mutex_destroy(&m);
}
