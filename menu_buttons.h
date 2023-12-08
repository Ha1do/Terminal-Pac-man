//
// Created by Ha1do on 07.12.2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <curses.h>
#include <time.h>

// ! main menu buttons
void print_hollow_play(const int map)
{
    mvprintw(12, 71, "+--------------+");
    mvprintw(13, 71, "|     PLAY     |");
    mvprintw(14, 71, "|    MAP (%d)   |", map);
    mvprintw(15, 71, "+--------------+");
}
void print_on_click_play(const int map)
{
    mvprintw(12, 71, "+--------------+");
    mvprintw(13, 71, "|     ");
    attron(COLOR_PAIR(9));
    mvprintw(13, 77, "PLAY");
    attroff(COLOR_PAIR(9));
    mvprintw(13, 81, "     |");
    mvprintw(14, 71, "|    ");
    attron(COLOR_PAIR(9));
    mvprintw(14, 76, "MAP (%d)", map);
    attroff(COLOR_PAIR(9));
    mvprintw(14, 86, "|");
    mvprintw(15, 71, "+--------------+");
}

void print_hollow_map()
{
    mvprintw(16, 71, "+--------------+");
    mvprintw(17, 71, "|  CHOOSE MAP  |");
    mvprintw(18, 71, "+--------------+");
}
void print_on_click_map()
{
    mvprintw(16, 71, "+--------------+");
    mvprintw(17, 71, "|");
    attron(COLOR_PAIR(9));
    mvprintw(17, 74, "CHOOSE MAP");
    attroff(COLOR_PAIR(9));
    mvprintw(17, 86, "|");
    mvprintw(18, 71, "+--------------+");
}

void print_hollow_options()
{
    mvprintw(19, 71, "+--------------+");
    mvprintw(20, 71, "|    OPTIONS   |");
    mvprintw(21, 71, "+--------------+");
}
void print_on_click_options()
{
    mvprintw(19, 71, "+--------------+");
    mvprintw(20, 71, "|");
    attron(COLOR_PAIR(9));
    mvprintw(20, 75, "OPTIONS");
    attroff(COLOR_PAIR(9));
    mvprintw(20, 86, "|");
    mvprintw(21, 71, "+--------------+");
}

void print_hollow_exit()
{
    mvprintw(22, 71, "+--------------+");
    mvprintw(23, 71, "|     EXIT     |");
    mvprintw(24, 71, "+--------------+");
}
void print_on_click_exit()
{
    mvprintw(22, 71, "+--------------+");
    mvprintw(23, 71, "|");
    attron(COLOR_PAIR(9));
    mvprintw(23, 77, "EXIT");
    attroff(COLOR_PAIR(9));
    mvprintw(23, 86, "|");
    mvprintw(24, 71, "+--------------+");
}

// ! CHOOSE MAP MENU BUTTONS
//|       |    |       |    |       |    |       |
//|   1   |    |   2   |    |   3   |    |   4   |
//|       |    |       |    |       |    |       |
void print_on_click_one()
{
    mvprintw(15, 57, "+-------+    +-------+    +-------+    +-------+");

    mvprintw(16, 57, "|");
    attron(COLOR_PAIR(9));
    mvprintw(16, 58, "       ");
    attroff(COLOR_PAIR(9));
    mvprintw(16, 65, "|    |       |    |       |    |       |");

    mvprintw(17, 57, "|");
    attron(COLOR_PAIR(9));
    mvprintw(17, 58, "   1   ");
    attroff(COLOR_PAIR(9));
    mvprintw(17, 65, "|    |   2   |    |   3   |    |   4   |");

    mvprintw(18, 57, "|");
    attron(COLOR_PAIR(9));
    mvprintw(18, 58, "       ");
    attroff(COLOR_PAIR(9));
    mvprintw(18, 65, "|    |       |    |       |    |       |");

    mvprintw(19, 57, "+-------+    +-------+    +-------+    +-------+");
}
void print_on_click_two()
{
    mvprintw(15, 57, "+-------+    +-------+    +-------+    +-------+");
    mvprintw(16, 57, "|       |    |");
    attron(COLOR_PAIR(9));
    mvprintw(16, 71, "       ");
    attroff(COLOR_PAIR(9));
    mvprintw(16, 78,"|    |       |    |       |");

    mvprintw(17, 57, "|   1   |    |");
    attron(COLOR_PAIR(9));
    mvprintw(17, 71, "   2   ");
    attroff(COLOR_PAIR(9));
    mvprintw(17, 78,"|    |   3   |    |   4   |");

    mvprintw(18, 57, "|       |    |");
    attron(COLOR_PAIR(9));
    mvprintw(18, 71, "       ");
    attroff(COLOR_PAIR(9));
    mvprintw(18, 78,"|    |       |    |       |");
    mvprintw(19, 57, "+-------+    +-------+    +-------+    +-------+");
}
void print_on_click_three()
{
    mvprintw(15, 57, "+-------+    +-------+    +-------+    +-------+");

    mvprintw(16, 57, "|       |    |       |    |");
    attron(COLOR_PAIR(9));
    mvprintw(16, 84, "       ");
    attroff(COLOR_PAIR(9));
    mvprintw(16, 91, "|    |       |");

    mvprintw(17, 57, "|   1   |    |   2   |    |");
    attron(COLOR_PAIR(9));
    mvprintw(17, 84, "   3   ");
    attroff(COLOR_PAIR(9));
    mvprintw(17, 91, "|    |   4   |");

    mvprintw(18, 57, "|       |    |       |    |");
    attron(COLOR_PAIR(9));
    mvprintw(18, 84, "       ");
    attroff(COLOR_PAIR(9));
    mvprintw(18, 91, "|    |       |");

    mvprintw(19, 57, "+-------+    +-------+    +-------+    +-------+");
}
void print_on_click_four()
{
    mvprintw(15, 57, "+-------+    +-------+    +-------+    +-------+");
    mvprintw(16, 57, "|       |    |       |    |       |    |");
    attron(COLOR_PAIR(9));
    mvprintw(16, 97, "       ");
    attroff(COLOR_PAIR(9));
    mvprintw(16, 104, "|");

    mvprintw(17, 57, "|   1   |    |   2   |    |   3   |    |");
    attron(COLOR_PAIR(9));
    mvprintw(17, 97, "   4   ");
    attroff(COLOR_PAIR(9));
    mvprintw(17, 104, "|");

    mvprintw(18, 57, "|       |    |       |    |       |    |");
    attron(COLOR_PAIR(9));
    mvprintw(18, 97, "       ");
    attroff(COLOR_PAIR(9));
    mvprintw(18, 104, "|");
    mvprintw(19, 57, "+-------+    +-------+    +-------+    +-------+");
}

int choose_map()
{
    mvprintw(13, 60, "Please, choose map, you want to play on");
    print_on_click_one();
    move(0, 0);

    int wait;
    int pos = 1;
    fflush(stdin);
    do
    {
        wait = getch();
        if (wait == 'A' || wait == 'a' || wait == KEY_LEFT)
        {
            if (pos > 1)
            {
                pos--;
            }
            switch (pos)
            {
                case 1:
                    print_on_click_one();
                    move(0, 0);
                    break;
                case 2:
                    print_on_click_two();
                    move(0, 0);
                    break;
                case 3:
                    print_on_click_three();
                    move(0, 0);
                    break;
                case 4:
                    print_on_click_four();
                    move(0, 0);
                    break;
                default:
                    print_on_click_one();
                    move(0, 0);
            }
        }
        else if (wait == 'D' || wait == 'd' || wait == KEY_RIGHT)
        {
            if (pos < 4)
            {
                pos++;
            }
            switch (pos)
            {
                case 1:
                    print_on_click_one();
                    move(0, 0);
                    break;
                case 2:
                    print_on_click_two();
                    move(0, 0);
                    break;
                case 3:
                    print_on_click_three();
                    move(0, 0);
                    break;
                case 4:
                    print_on_click_four();
                    move(0, 0);
                    break;
                default:
                    print_on_click_one();
                    move(0, 0);
            }
        }
        else if (wait == '\n')
        {
            return pos;
        }
    }while (wait != '\n');

    getch();
    return pos;
}