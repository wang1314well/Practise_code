#include <pthread.h>
#include <stdlib.h>
#include <curses.h>
#include <math.h>
#include <unistd.h>

pthread_t t[26];
pthread_mutex_t m;

struct AChar
{
	int x;
	int y;
	int speed;
	char a;
};

void *run(void *d)
{
		struct AChar a;
//		AChar a;
		a.x = rand()%COLS;
		a.y = rand()%(LINES/4);
		a.speed = 1 + rand()%3;
		a.a = 65+rand()%26;
	while(1)
	{
		a.y= a.y+a.speed;
		if(a.y >= LINES)
		{
			a.y = rand()%(LINES/4);
		}
		pthread_mutex_lock(&m);
		mvaddch(a.y,a.x,a.a);
		refresh();
		pthread_mutex_unlock(&m);
		usleep(10000);
	}
}

int main()
{
	int i ;
	initscr();
	pthread_mutex_init(&m,0);
	for(i = 0;i<26;i++)
	{
		pthread_create(&t[i],0,run,(void**)0);
	}

	getch();
	pthread_mutex_destroy(&m);
	endwin();
	exit(0);
}
