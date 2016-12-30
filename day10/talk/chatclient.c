#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <curses.h>

WINDOW	*winfo,*wmsg;
int		fd;
int		r;
struct sockaddr_in	dr;


int init_socket()
{
	if((fd = socket(AF_INET,SOCK_STREAM,0)) < 0)
	{
		printf("socket error\n");
		return -1;
	}
	dr.sin_family = AF_INET;
	dr.sin_port = htons(9989);
	dr.sin_addr.s_addr = inet_addr("192.168.119.128");

	r = connect(fd,(struct sockaddr*)&dr,sizeof(dr));
	if(r == -1)
	{
		close(fd);
		return -1;
	}
	return fd;
}

void initUI()
{
	initscr();
	winfo = derwin(stdscr,(LINES-3),COLS,0,0);
	wmsg  = derwin(stdscr,2,COLS,LINES-3,0);
	box(winfo,0,0);
	box(wmsg,0,0);
	refresh();
	wrefresh(winfo);
	wrefresh(wmsg);
}

void destroy()
{
	getch();
	close(fd);
	endwin();
}

int main()
{
//	fd = init_socket();
//	if(fd == -1)
//		exit(-1);
	printf("internet work init sucess\n");
	initUI();
	if(fork())
	{
		char buf[256];
		while(1)
		{
			mvwgetstr(wmsg,1,1,buf);
			buf[r] = 0;
			send(fd,buf,r,0);
//		mvwaddstr(wmsg,1,1,buf);
			wclear(wmsg);
			box(wmsg,0,0);
			refresh();
			wrefresh(wmsg);
		}
	}
	else
	{
		char buf[256];
		int line = 1;
		while(1)
		{
			r = recv(fd,buf,255,0);
			buf[r] = 0;
			mvwaddstr(winfo,line,1,buf);
			line++;
			if(line >= (LINES-3))
			{
				wclear(winfo);
				line = 1;
				box(winfo,0,0);
			}
			refresh();
			wrefresh(winfo);
			wmove(wmsg,1,1);
		}
	}
	destroy();
	exit(0);
}
