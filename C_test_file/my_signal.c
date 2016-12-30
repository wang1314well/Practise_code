#include "apue.h"
#include "myerr.h"

static void sig_usr(int signo)
{
	if(signo == SIGUSR1)
		printf("receved SIGUSR1\n");
	else if(signo == SIGUSR2)
		printf("receved SIGUSR2\n");
	else
		err_dump("receved signal %d\n",signo);
}

int main()
{
	if(signal(SIGUSR1,sig_usr) == SIG_ERR)
		err_sys("can not catch SIGUSR1");
	if(signal(SIGUSR2,sig_usr) == SIG_ERR)
		err_sys("can not catch SIGUSR2");
	while(1)
		pause();
	
}
