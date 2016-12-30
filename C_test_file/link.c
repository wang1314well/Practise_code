#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

struct classmates
{
	char *name;
	int score;
	struct classmates *next;
};

int main()
{
	struct classmates *p,*q,*r,*current;
	p=(struct classmates*)malloc(sizeof(struct classmates));
	p->name = "Jane";
	p->score = 99;

	q=(struct classmates*)malloc(sizeof(struct classmates));
	q->name = "Maxwell";
	q->score = 100;

	r=(struct classmates*)malloc(sizeof(struct classmates));
	r->name = "Whatf";
	r->score = 101;

	current = p;
	p->next = q;
	q->next =r;
	r->next = NULL;

	while(current !=NULL)
	{
		printf("%10s %10d\n ",current->name,current->score);
		current = current ->next;
	}
//	getch();
	return 0;
}
