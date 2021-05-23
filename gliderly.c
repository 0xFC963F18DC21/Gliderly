#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <curses.h>
#include <unistd.h>

#define PM(divd, divs) ((divd % divs < 0) ? (divd % divs) + divs : divd % divs)
#define DRAW for (int yy = 0; yy < y; ++yy) for (int xx = 0; xx < x; ++xx) mvwaddch(SSSTD, yy, xx, grid[x * yy + xx]); wrefresh(SSSTD)
#define ISON(ch) (ch == '#')
#define GET(xx, yy) grid[xx + (yy * x)]
#define NGET(xx, yy) newgrid[xx + (yy * x)]

int count(char* str,
int n,char look_for)
{int cn=0;for (char*
c = str; c < str+ n;
++c)  {  if  (*c  ==
look_for)   ++cn;  }
return    cn;  } int
main(void) { WINDOW*
                                            SSSTD=initscr();noecho();
                                            cbreak()  ;  int  x,   y;
                                            getmaxyx(SSSTD ,  y,  x);
                                            srand(   time(  NULL  ));
                                            char* grid = malloc(x * y
                                            *  sizeof( char )); char*
                                            newgrid =  malloc(x * y *
                                            sizeof(char)); int pc =0;
int SAME = 0; for (char* c = grid; c < grid + x * y;++c) *c = (rand()
& 1) ? '#' : ' '; /* USING B3/S23 */ while (1){for (int i = 0; i < y;
++i) { for (int j = 0; j < x; ++j) { int on = 0; for (int di = -1; di
<= 1; ++di) { for (int dj = -1; dj <= 1; ++dj) { if (di != 0 || dj !=
0) { if (ISON(GET(PM(j + dj,  x),  PM(i  + di,  y))))  ++on;  }  }  }
if (!ISON(GET(j, i)) && on == 3) NGET(j, i) = '#'; else if(ISON(GET(j
, i)) && (on != 2 && on != 3)) NGET(j, i) = ' ';   else NGET(j, i)  =
GET(j, i); } } memcpy(grid, newgrid, x * y); int cn = count(grid, x *
y,'#');if(cn == pc) { if (++SAME == ((x + y) / 2)) break; } else { pc
=cn;}DRAW;usleep(50000);}free(grid);free(newgrid);endwin();return 0;}
