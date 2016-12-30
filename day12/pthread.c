#include <curses.h>
#include <pthread.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

WINDOW *wnum,*wtime;
pthread_t thnum,thtime;
pthread_mutex_t m;


void *runnum(void *d)
{
	int num;
	while(1)
	{
		num = rand()%10000000;
		pthread_mutex_lock(&m);
		mvwprintw(wnum,1,2,"%07d",num);
		refresh();
		wrefresh(wnum);
		pthread_mutex_unlock(&m);
		usleep(10000);
	}
	return 0;
}

void *runtime(void *d)
{
	time_t tt;
	struct tm *t;
	while(1)
	{
		tt = time(0);
		t = localtime(&tt);
		pthread_mutex_lock(&m);
		mvwprintw(wtime,1,1,"%02d:%02d:%02d",t->tm_hour,t->tm_min,t->tm_sec);
		refresh();
		wrefresh(wtime);
//		return 0;
		pthread_mutex_unlock(&m);
	}
	return 0;
}

int main()
{
	pthread_mutex_init(&m,0);
//	pthread_mutex_init(&n,0);

	initscr();
	curs_set(0);
	noecho();
	keypad(stdscr,TRUE);
	wnum = derwin(stdscr,3,11,(LINES-3)/2,(COLS-11)/2);
	wtime = derwin(stdscr,3,10,0,(COLS-10));
	box(wnum,0,0);
	box(wtime,0,0);
	refresh();
	wrefresh(wnum);
	wrefresh(wtime);
	pthread_create(&thnum,0,runnum,(void**)0);
	pthread_create(&thtime,0,runtime,(void**)0);
	getch();
	delwin(wtime);
	delwin(wnum);
	endwin();
	pthread_mutex_destroy(&m);
//	pthread_mutex_destroy(&n);
	exit(0);
}
