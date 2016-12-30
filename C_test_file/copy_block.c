#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
	char block[1024];
	int in ,out;
	int nread;

	in = open ("hello.c",O_RDONLY);
	out = open ("file.out",O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR);
	while (read(in,&C,1) == 1)
	write (out,&C,1);

	exit(0);
}
