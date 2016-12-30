#include <stdio.h>
#include <error.h>

int main()
{
	FILE *fptr;
	char name[20];

	if((fptr = fopen("filetest.txt","r"))==NULL)
		printf("error\n");
	
	while(fscanf(fptr,"%s",name)!=EOF)
		printf("%s\n",name);
	fclose(fptr);
}
