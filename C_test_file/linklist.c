#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct someone
{
	char *name;
	struct someone *next;
};
struct someone *ptr,*current,*head,*prev;

void addsomeone()
{
	ptr = (struct someone*)malloc(sizeof(struct someone));
	printf("Please input a name:");
	scanf("%s",ptr->name);
	
	prev = head;
	current =head->next;

	while(current != NULL)
	{
		prev =current;
		current = current->next;
	}
	
	prev->next = ptr;
	ptr->next = current;
	current->next = NULL;
}

void showeveryone()
{
	while(current->next != NULL)
	{
		printf("%s\n",current->name);
		current = current->next ;
	}
}
int main()
{
	int i;
	head = (struct someone*)malloc(sizeof(struct someone));
	head->next = NULL;
	for(i=0;i<5;i++)
	{
		addsomeone();
	}	
	showeveryone();
	return 0;
}
