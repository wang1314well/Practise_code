#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

pthread_mutex_t m;
pthread_t eid,oid;

void handle()
{
	printf("what a fuck!\n");
	pthread_mutex_unlock(&m);
}

void *even(void *d)
{
	int i ;
	for(i = 0;;i=i+2)
	{
		pthread_cleanup_push(handle,0);
		pthread_mutex_lock(&m);
		sleep(1);
		printf("%d\n",i);
		pthread_mutex_unlock(&m);
		pthread_cleanup_pop(0);
	}
}

void *odd(void *d)
{
	int j ;
	for(j= 1;;j=j+2)
	{
		pthread_cleanup_push(handle,0);
		pthread_mutex_lock(&m);
		sleep(1);
		printf("%d\n",j);
		pthread_mutex_unlock(&m);
		pthread_cleanup_pop(0);
	}
}

int main()
{
	pthread_mutex_init(&m,0);
//	pthread_t eid,oid;
	pthread_create(&eid,0,even,(void**)0);
	pthread_create(&oid,0,odd,(void**)0);
	sleep(10);
	pthread_cancel(eid);
	pthread_join(eid,0);
	pthread_join(oid,0);
	pthread_mutex_destroy(&m);
	exit(0);
	
}
