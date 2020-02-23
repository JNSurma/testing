/* Written by Jeremy N. Surma
   Just playing with ncurses in linux.  Doesn't
   do anything usefull yet, just playing around.
*/
/*  This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 2 of the License.
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/    
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
/*
#define WIDTH 60
#define HEIGHT 30
*/

int startx = 0;
int starty = 0;
int ch = 0;
int i = 0;

void delay(float sec){
  int m_sec = CLOCKS_PER_SEC * sec;
  clock_t start_time = clock();
  while (clock() < start_time + m_sec){
    ;
  }
}

int main(void){
  WINDOW *win;
  initscr();
  const int WIDTH = COLS - 20;
  const int HEIGHT = LINES - 10;
  clear();
  cbreak();
  startx = (COLS - WIDTH) / 2;
  starty = (LINES - HEIGHT) / 2;
  noecho();

  win = newwin(HEIGHT, WIDTH, starty, startx);
  keypad(win, TRUE);
  box(win, 0, 0);
  
  nodelay(win, TRUE);

  mvwprintw(win, ((HEIGHT/2)-6), ((WIDTH-20)/2), "Screen size %d x %d", COLS, LINES);
  while ((ch = wgetch(win)) == ERR && i <= 30){
    mvwprintw(win, ((HEIGHT/2)-4), ((WIDTH-20)/2), "Window size %d x %d", WIDTH, HEIGHT);
    mvwprintw(win, ((HEIGHT/2)-2), ((WIDTH-12)/2), "No Input. %d", i);
    wrefresh(win);
    i++;
    delay(1);
  }

  if (ch == ERR){
    mvwprintw(win, (HEIGHT/2), ((WIDTH-20)/2), "No Character Input.");
    wrefresh(win);
  }
  else{
    mvwprintw(win, (HEIGHT/2), ((WIDTH-16)/2), "Character Input.");
    wrefresh(win);
  }
mvwprintw(win, ((HEIGHT/2)+6), ((WIDTH-14)/2), "Press any key.");
  while (wgetch(win) == ERR){
} 

  endwin();
  return ch;
}
