#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int data_pro;
	int file_pipes[2];
	const char some_data[]="king";
	char buffer[BUFSIZ+1];
	pid_t fork_result;

	memset(buffer,'\0',sizeof(buffer));
	if(pipe(file_pipes)==0)
	{
		fork_result =fork();
		if(fork_result == -1)
		{
			fprintf(stderr,"Fork failure");
			exit(EXIT_FAILURE);
		}
		if(fork_result == 0)
		{
			data_pro = read(file_pipes[0],buffer,BUFSIZ);
			printf("read %d bytes:%s\n",data_pro,buffer);
			exit(EXIT_SUCCESS);
		}
		else
		{
			data_pro = write(file_pipes[1],some_data,strlen(some_data));
			printf("wrote %d bytes\n",data_pro);
		}
		exit(EXIT_SUCCESS);
	}
}
