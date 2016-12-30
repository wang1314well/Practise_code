#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *fptr;
	char name[20];
	int year;
	if((fptr=fopen("filetest.txt","w"))==NULL)
		printf("error/n");
	do
	{
		printf("input a some:\n");
		scanf("%s",name);
		fprintf(fptr,"%5s\n",name);
	}while(strcmp(name,"q")!=0);
	fclose(fptr);
	return 0;
}
