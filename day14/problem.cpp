#include <stdio.h>
#include <unistd.h>


void log()
{
	printf("output daily!\n");
}

void biz()
{
	while(1)
	{
		sleep(1);
		printf("I'm process!\n");
		log();
	}
}

int main()
{
	biz();
	
}
