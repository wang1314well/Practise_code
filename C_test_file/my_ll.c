#include <stdio.h>
#include <malloc.h>

struct someone
{
	char name[20];
	struct someone *next;
};

struct someone *head,*tail,*current,*ptr,*prev;

void addsomeone()
{
	ptr = (struct someone*)malloc(sizeof(struct someone));
	printf("input a name:");
	scanf("%s",ptr->name);
	printf("\n");

	prev = head;
	current = head->next;
/*	while(current != NULL)
	{
		prev = current;
		current = current->next;
	}
*/	ptr->next = current;
	prev->next = ptr;
	
		
}

void showeveryone()
{
	current = head->next;
	while(current != NULL) 
	{
		printf("%s\n",current->name);
		current = current->next;
	}
}

int main()
{
	head = (struct someone*)malloc(sizeof(struct someone));
//	tail = (struct someone*)malloc(sizeof(struct someone));

	head->next = NULL;
//	tail->name = "I'm the tail";
//	tail->next = NULL;
	for(int i=0;i<5;i++)
	addsomeone();
	showeveryone();
	return 0;
}
