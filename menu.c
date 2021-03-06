/******************************/
/* Gra ASCII "Przygody kloca" */
/* © 2016 Kamil Poniatowski   */
/******************************/

#include <ncursesw/ncurses.h>

#include "menu.h"
#include "okna.h"

int menu( WINDOW *win ) {
    init_pair( 1, COLOR_BLACK, COLOR_WHITE );
    int startx = ( 80 - 11 ) / 2;
    int starty = ( 20 - 4 ) / 2;
    int line=1;
    int c;
    do {
        wclear( win );
        printBorder( win );

        // 1
        if( line == 1 ) {
            wmove( win, starty, startx - 2 );
            wprintw( win, ">");
            wattron( win, COLOR_PAIR( 1 ) );
        }

        wmove( win, starty, startx );
        wprintw( win, "Nowa gra" );
        if( line == 1 )
            wattroff( win, COLOR_PAIR( 1 ) );

        // 2
        if( line == 2 ) {
            wmove( win, starty + 1, startx - 2 );
            wprintw( win, ">");
            wattron( win, COLOR_PAIR( 1 ) );
        }

        wmove( win, starty + 1, startx );
        wprintw( win, "Wczytaj gre" );
        if( line == 2 )
            wattroff( win, COLOR_PAIR( 1 ) );

        // 3
        if( line == 3 ) {
            wmove( win, starty + 2, startx - 2 );
            wprintw( win, ">");
            wattron( win, COLOR_PAIR( 1 ) );
        }

        wmove( win, starty + 2, startx );
        wprintw( win, "Pomoc" );
        if( line == 3 )
            wattroff( win, COLOR_PAIR( 1 ) );

        // 4
        if( line == 4 ) {
            wmove( win, starty + 3, startx - 2 );
            wprintw( win, ">");
            wattron( win, COLOR_PAIR( 1 ) );
        }

        wmove( win, starty + 3, startx );
        wprintw( win, "Zakoncz gre" );
        if( line == 4 )
            wattroff( win, COLOR_PAIR( 1 ) );

        wrefresh( win );
        refresh();

        c = getch();
        switch( c ) {
            case KEY_UP:
                if( line > 1 )
                    line--;
                break;
            case KEY_DOWN:
                if( line < 4 )
                    line++;
                break;
            case 'q':
                line = 4;
                c = '\n';
                break;
            default:
                line=line;
                break;
        }
    } while( c != '\n' );

    return line;
}
