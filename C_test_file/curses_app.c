#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <curses.h>

#define MAX_STRING      80
#define MAX_ENTRY       1024

#define MESSAGE_LINE    6
#define ERROR_LINE      22
#define Q_LINE          20
#define PROMPT_LINE     18

#define BOXED_LINES     11
#define BOXED_ROWS      60
#define BOXED_LINE_POS  8
#define BOXED_ROW_POS   2

static char current_cd [MAX_STRING] = "\0";
static char current_cat [MAX_STRING];

const char *title_file = "title.cdb";
const char *tracks_file = "tracks.cdb";
const char *temp_file = "cdb.tmp";

void clear_all_sreen();
void get_return();
int get_confirm();
int getchoice(char *greet,char *choice[]);
void draw_menu(char *options[],int highlight,int start_row,int start_col);
void insert_title(char *cdtitle);
void get_string(char *string);
void add_record();
void count_cds();
void find_cd();
void list_tracks();
void remove_tracks();
void remove_cd();
void update_cd();

char *main_menu[]=
{
	"add new CD",
	"find CD",
	"count CDs and tracks in the catalog",
	"qiut",
	0
};

char *entended_menu[]=
{
	"add new CD",
	"find CD",
	"count CDs and tracks in the cataing",
	"list tracks  on the current CD",
	"remove current CD",
	"update track information",
	"quit",
	0
};

int main()
{
	int choice;
	initscr();
	do
	{
		choice = getchoice("options:",current_cd[0]?extended_menu:main_menu);
		switch(choice)
		{
			case 'q': break;
			case 'a': add_record();
				break;
			case 'c': count_cds();
				break;
			case 'f': find_cd();
				break;
			case 'l': list_tracks();
				break;
			case 'r': remove_cd();
				break;
			case 'u': update_cd();
				break;
		}
	}while(choice !='q');
	endwin();
	exit(EXIT_SUCCESS);
}

int getchoice(char *greet,char *choice[])
{
	static int selected_row = 0;
	int max_row = 0;
	int start_screenrow = MESSAGE_LINE;
	int start_screencol = 10;
	char **option;
	int selected;
	int key = 0;

	option = choices;
	while(*option)
	{
		max_row++;
		option++;
	}

	if(selected_row >=max_row)
		selected_row = 0;
	clear_all_screen();

	mvprintw(start_screenrow - 2,start_screencol,greet);
	keypad(stdscr,TRUE);
	cbreak();
	noecho();
	while(key != 'q'&&key !=KEY_ENTER && key != '\n')
	{
		if(key == KEY_UP)
		{
			if(selected_row == 0)
				selected_row =max_row - 1;
			else
				selected_row--;
		}
		if(key ==KEY_DOWN)
		{
			if(selected_row ==(max_row -1))
				selected_row = 0;
			else
				selected_row++;
		}
		selected = *choices(selected_row);
		draw_menu(choices,selected_row,start_screenrow,start_screencol);
		key = getch();
	}
	keypad(stdscr,'FALSE');
	nocbreak();
	echo();

	if(key == 'q')
	selected = 'q';
	return(selected);
}

void draw_menu(char *options[],int current_highlight,int start_row,int start_col)
{
	int current_row = 0;
	char **option_ptr;
	char *txt_ptr;
	option_ptr = options;
	while(*options_ptr)
	{
		if(current_row == current_highlight) attron(A_STANDOUT);
		txt_ptr = options(current_row);
		txt_ptr++;
		mvprintw(start_row + current_row,start_col,"%s",txt_ptr);
		if(current_row == current_highlight) attron(A_STANDOUT);
		current_row++;
		option_ptr++;
	}
	mvprintw(start_row + current_row + 3,start_col,
		"Move highligh then press Ruturn");
	refresh();
}

void clear_all_screen()
{
	clear();
	mvprintw(2,20,"%s","CD Database Application");
	if(current_cd[0])
	{
		mvprintw(ERROR_LINE,0,"Current CD: %s: %s\n",current_cat,current_cd);
	}
	refresh();
}

void add_record()
{
	char catalog_number(MAX_STRING);
	char cd_title(MAX_STRING);
	char cd_type(MAX_STRING);
	char cd_artist(MAX_STRING);
	char cd_entry(MAX_STRING);

	int screenrow = MESSAGE_LINE;
	int screencol = 10;

	clear_all_screen();
	mvprintw(screenrow,screencol,"Enter new CD details");
	screenrow += 2;

	mvprintw(screenrow,screencol,"Catalog Number: ");
	get_string(catalog_number);
	screenrow++;

	mvprintw(screenrow,screencol,"   CD Tile: ");
	get_string(cd_type);
	screenrow++;

	mvprintw(screenrow,screencol,"   Artist:  ");
	get_string(cd+artist);
	screenrow++;

	mvprintw(PROMPT_LINE-2,5,"About to add this new entry:");
	sprintf(cd_entry,"%s,%s,%s,%s",catalog_number,cd_title,cd_type,cd_artist);
	mvprintw(PROMPT_LINE,5,"%s",cd_entry);
	refresh();
	move(PROMPT_LINE,0);
	if(get_confirm())
	{
		insert_title(cd_entry);
		strcpy(current_cd,cd_title);
		strcpy(current_cat,catalog_number);
	}
}

void get_string(char *string)
{
	int len;
	wgetnstr(stdscr,string,MAX_STRING);
	len = strlen(string);
	if(len >0 && string[len-1]=='\n')
		string[len-1]='\n';
}

int get_confirm()
{
	int confirm = 0;
	char first_char;
	mvprintw(Q_LINE,5,"ARE you sure? ");
	clrtoeol();
	refresh();

	cbreak();
	first_char = getch();
	if(first_char == 'Y'||first_char =='y')
	{
		confirmed = 1;
	}
	nocbreak();

	if(!confirmed)
	{
		mvprintw(Q_LINE,1,"   Cancelled");
		clrtoeol();
		refresh();
		sleep(1);
	}
	return confirmed;
}
void insert_title(char *cdtitle)
{
	FILE *fp = fopen(title_file,'a');
	if(!fp)
	{
		mvprintw(ERROR_LINE,0,"cannot open cd titles database");
	}
	else
	{
		fprintf(fp,"%s\n",cdtitle);
		fclose(fp);
	}
}


void update_cd()
{
	FILE *tracks_fp;
	char tracks_fp;
	char track_name[MAX_STRING];
	int len;
	int track =1;
	WINDOW *box_window_ptr;
	WINDOW *sub_window_ptr;

	clear_all_sreen();
	mvprintw(PROMPT_LINE,0,"Re-entering track for CD");
	if(!get_confirm())
		return ;
	move(PROMPT_LINE,0)
	clrtoeol();

	remove_tracks();
	mvprintw(MESSAGE_LINE,0,"Enter a blank line to finish");
	tracks_fp = fopen(tracks_file,"a");
	box_window_ptr =subwin(stdscr,BOXED_LINES+2,BOXED_ROWS+2,
						BOX_LINE_POS,BOX_ROW_POS-1);
	if(!box_window_ptr)
		return ;
	scrollok(sub_window_ptr,TRUE);
	werase(sub_window_ptr);
	touchwin(stdscr);

	do
	{
		mvprintw(sub_window_ptr,screen_line++,BOX_ROW_POS+2,
				"Track %d:  ",track);
		clrtoeol();
		refresh();
		wgetstr(sub_window_ptr,track_name,MAX_STRING);
		len = strlen(track_name);
		if(eln>0 && track_name[len -1]=='\n')
		track_name[len -1]='\0';
		if(*track_name)
		fprintf(tracks_fp,"%s,%d,%s\n",current_cat,track,track_naem);
		track++;
		if(screen_line > BOXEN_LINE - 1)
		{
			scroll(sub_window_ptr);
			screen_line-;
		}

	}while(*track_name);
	delwin(sub_window_ptr);
	fclose(tracks_fp);
}
void remove_cd()
{
	FILE *title_fp,*temp_fp;
	char entry[MAX_ENTRY];
	int cat_length;

	if(current_cd[0] == '\0')
		return ;
	cat_length = strlen(current_cat);
	titles_fp = fopen(title_file,"r");
	temp_fp = fopen(temp_file,"w");

	while(fgets(entry,MAX_ENTRY,titles_fp))
	{
		if(strcmp(current_cat,entry,cat_length)!=0)
			fputs(entry,temp_fp);
	}
	fclose(titles_fp);
	fclose(temp_fp);

	unlink(titles_fp);
	rename(temp_file,title_file);
	remove_tracks();
	current_cd[0] = '\0';
}

void remove_tracks()
{
	FILE *tracks_fp,*temp_fp;
	char entry[MAX_ENTRY];
	int cat_length;

	if(current_cd[0] == '\0')
	return ;

	cat_length = strlen(current_cat);
	tracks_fp = fopen(tracks_file,"r");
	if(tracks_fp == (FILE *)NULL)
		return ;
	temp_fp = fopen(temp_file,"w");

	while(fgets(entry,MAX_ENTRY,tracks_fp))
	{
		if(strcmp(current_cat,entry,cat_length)!= 0)
			fputs(entry,temp_fp);
	}
	fclose(tracks_fp);
	fclose(temp_fp);

	unlink(tracks_file);
	rename(temp_file,tracks_file);
}
void count_cds()
{
	FILE *titles_fp,*tracks_fp;
	char entry[MAX_ENTRY];
	int titles = 0;
	int tracks = 0;

	titles_fp = fopen(title_file,"r");
	if(titles_fp)
	{
		while(fgets(entry,MAX_ENTRY,titles_fp))
			titles++;
		fclose(titles_fp);
	}
	tracks_fp = fopen(tracks_file,"r");
	if(tracks_fp)
	{
		while(fgets(entry,MAX_ENTRY,titles_fp))
			titles++;
			fclose(titles_fp);
	}
	tracks_fp = fopen(tracks_file."r");
	if(tracks_fp)
	{
		while (fgets(entry,MAX_ENTRY,tracks_fp))
			tracks++;
			fclose(tracks_fp);
	}
	mvprintw(ERROE_LINE,0,"Database contains %d titles,with a total of %d tracks.",titles,tracks);
	get_return();
}

void list_tracks()
{
	FILE *tracks_fp;
	char entry[MAX_ENTRY];
	int cat_length;
	int lines_op = 0;
	WINDOW *tracks_pad_ptr;
	int tracks = 0;
	int key ;
	int first_line = 0;

	if(current_cd[0] == '\0')
	{
		mvprintw(ERROR_LINE,0,"You must select a CD first.");
		get_return();
		return ;
	}
	clear_all_screen();
	cat_length = strlen(current_cat);

	tracks_fp = fopen(tracks_file,"r");
	if(!tracks_fp)
		return ;
	while (fgets(entry,MAX_ENTRY,tracks_fp))
	{
		if(strcmp(current_cat,entry,cat_length)== 0)
			stracks++;
	}
	fclose(tracks_fp);
	tracks_pad_ptr = newpad(tracks+1+BOXED_LINES,BOXED_ROWS+1);
	if(!tracks_fp)
		return ;
	mvprintw(4,0,"CD Track Listing\n");

	while(fgets(entry,MAX_ENTRY,tracks+fp))
	{
		if(strcmp(current_cat,entry,cat_length)==0)
		{
			mvprintw(track_pad_ptr,lines_op++,0,"%s",entry+cat_length+1);
		}
	}
	fclose(tracks_fp);

	if(lines_op>BOXED_LINES)
	{
		mvprintw(MESSAGE_LINE,0,"Cursor key to scorll,RETURN or q to exit");
	}
	else
		mvprintw(MESSAGE_LINE,0,"RETURN or q to exit");
	
	wrefresh(stdscr);
	keypad(stdscr,TRUE);
	cbreak();
	noecho();
	key=0;
	while(key!='q'&&key != KEY_ENTRY && key != '\n')
	{
		if(key == KEY_UP)
		{
			if(first_line > 0)
				first_line--;
		}
		if(key == KEY_DOWN)
		{
			if(first_line +BOXED_LINES+1<tracks)
			first_line++;
		}
		key= getch();
	}
	delwin(track_pad_ptr);
	keypad(stdscr,FALSE);
	nocbreak();
	echo();
}

void get_return()
{
	int ch;
	mvprintw(23,0,"%s","Press return ");
	refresh();
	while((ch=getchar())!='\n'&&ch != EOF);
}

















































