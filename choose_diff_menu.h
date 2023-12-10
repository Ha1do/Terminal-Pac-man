//
// Created by Ha1do on 08.12.2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <curses.h>
#include <time.h>

void on_click_snail()
{
    mvprintw(16, 67, "+---------------------+");
    mvprintw(17, 67, "|");
    attron(COLOR_PAIR(9));
    mvprintw(17, 68, "   Slow as a snail   ");
    attroff(COLOR_PAIR(9));
    mvprintw(17, 89, "|");
    mvprintw(18, 67, "+---------------------+");

    mvprintw(19, 67, "+---------------------+");
    mvprintw(20, 67, "|         Easy        |");
    mvprintw(21, 67, "+---------------------+");

    mvprintw(22, 67, "+---------------------+");
    mvprintw(23, 67, "|        Normal       |");
    mvprintw(24, 67, "+---------------------+");

    mvprintw(25, 67, "+---------------------+");
    mvprintw(26, 67, "|         Hard        |");
    mvprintw(27, 67, "+---------------------+");
    move(0,0);
}
void on_click_easy()
{
    mvprintw(16, 67, "+---------------------+");
    mvprintw(17, 67, "|   Slow as a snail   |");
    mvprintw(18, 67, "+---------------------+");

    mvprintw(19, 67, "+---------------------+");
    mvprintw(20, 67, "|");
    attron(COLOR_PAIR(9));
    mvprintw(20, 68, "         Easy        ");
    attroff(COLOR_PAIR(9));
    mvprintw(20, 89, "|");
    mvprintw(21, 67, "+---------------------+");

    mvprintw(22, 67, "+---------------------+");
    mvprintw(23, 67, "|        Normal       |");
    mvprintw(24, 67, "+---------------------+");

    mvprintw(25, 67, "+---------------------+");
    mvprintw(26, 67, "|         Hard        |");
    mvprintw(27, 67, "+---------------------+");
    move(0,0);
}
void on_click_normal()
{
    mvprintw(16, 67, "+---------------------+");
    mvprintw(17, 67, "|   Slow as a snail   |");
    mvprintw(18, 67, "+---------------------+");

    mvprintw(19, 67, "+---------------------+");
    mvprintw(20, 67, "|         Easy        |");
    mvprintw(21, 67, "+---------------------+");

    mvprintw(22, 67, "+---------------------+");
    mvprintw(23, 67, "|");
    attron(COLOR_PAIR(9));
    mvprintw(23, 68, "        Normal       ");
    attroff(COLOR_PAIR(9));
    mvprintw(23, 89, "|");
    mvprintw(24, 67, "+---------------------+");

    mvprintw(25, 67, "+---------------------+");
    mvprintw(26, 67, "|         Hard        |");
    mvprintw(27, 67, "+---------------------+");

    move(0,0);
}
void on_click_hard()
{
    mvprintw(16, 67, "+---------------------+");
    mvprintw(17, 67, "|   Slow as a snail   |");
    mvprintw(18, 67, "+---------------------+");

    mvprintw(19, 67, "+---------------------+");
    mvprintw(20, 67, "|         Easy        |");
    mvprintw(21, 67, "+---------------------+");

    mvprintw(22, 67, "+---------------------+");
    mvprintw(23, 67, "|        Normal       |");
    mvprintw(24, 67, "+---------------------+");

    mvprintw(25, 67, "+---------------------+");
    mvprintw(26, 67, "|");
    attron(COLOR_PAIR(9));
    mvprintw(26, 68, "         Hard        ");
    attroff(COLOR_PAIR(9));
    mvprintw(26, 89, "|");
    mvprintw(27, 67, "+---------------------+");

    move(0,0);
}

int choose_difficulty()
{
    mvprintw(13, 63, "Please, choose game difficulty.");
    mvprintw(15, 66, "There is 4 difficulties:");
    on_click_snail();
    int wait;
    int pos = 1;

    fflush(stdin);
    do
    {
        wait = getch();
        if (wait == 'W' || wait == 'w' || wait == KEY_UP)
        {
            if (pos > 1)
            {
                pos--;
            }
            switch (pos)
            {
                case 1:
                    on_click_snail();
                    move(0, 0);
                    break;
                case 2:
                    on_click_easy();
                    move(0, 0);
                    break;
                case 3:
                    on_click_normal();
                    move(0, 0);
                    break;
                case 4:
                    on_click_hard();
                    move(0, 0);
                    break;
                default:
                    on_click_snail();
                    move(0, 0);
            }
        }
        else if (wait == 'S' || wait == 's' || wait == KEY_DOWN)
        {
            if (pos < 4)
            {
                pos++;
            }
            switch (pos)
            {
                case 1:
                    on_click_snail();
                    move(0, 0);
                    break;
                case 2:
                    on_click_easy();
                    move(0, 0);
                    break;
                case 3:
                    on_click_normal();
                    move(0, 0);
                    break;
                case 4:
                    on_click_hard();
                    move(0, 0);
                    break;
                default:
                    on_click_snail();
                    move(0, 0);
            }
        }
        else if (wait == '\n')
        {
            return 5 - pos;
        }
    }while (wait != '\n');

    return pos;
}
