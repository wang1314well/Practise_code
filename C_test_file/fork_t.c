#include <stdio.h>
#include <unistd.h>

int main()
{
	
	printf("before fork: \n");
	printf("pid: %d  ***    ppid: %d",getpid(),getppid());
	printf("after fork\n");
	printf("fork: %d  ***   pid: %d  ***    ppid: %d",fork(),getpid(),getppid());
	return 0;
}
