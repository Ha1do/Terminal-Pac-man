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
void print_on_click_one()
{
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
}
void print_on_click_two()
{

}
void print_on_click_three()
{

}
void print_on_click_four()
{

}

int choose_map()
{
    mvprintw(13, 60, "Please, choose map, you want to play on");
    mvprintw(15, 57, "+-------+    +-------+    +-------+    +-------+");
    print_on_click_one();
    mvprintw(19, 57, "+-------+    +-------+    +-------+    +-------+");
    move(0, 0);

    int wait;
    int pos = 1;
    fflush(stdin);
    do
    {
        wait = getch();
        if (wait == 'S' || wait == 's' || wait == KEY_DOWN)
        {
            if (pos < 3)
            {
                pos++;
            }
//            if (pos == 1)
//            {
//                print_on_click_play();
//                print_hollow_map();
//                print_hollow_exit();
//                move(0, 0);
//            }
//            else if (pos == 2)
//            {
//                print_hollow_play();
//                print_on_click_map();
//                print_hollow_exit();
//                move(0, 0);
//            }
//            else if (pos == 3)
//            {
//                print_hollow_play();
//                print_hollow_map();
//                print_on_click_exit();
//                move(0, 0);
//            }
//        }
//        else if (wait == 'W' || wait == 'w' || wait == KEY_UP)
//        {
//            if (pos > 1)
//            {
//                pos--;
//            }
//            if (pos == 1)
//            {
//                print_on_click_play();
//                print_hollow_map();
//                print_hollow_exit();
//                move(0, 0);
//            }
//            else if (pos == 2)
//            {
//                print_hollow_play();
//                print_on_click_map();
//                print_hollow_exit();
//                move(0, 0);
//            }
//            else if (pos == 3)
//            {
//                print_hollow_play();
//                print_hollow_map();
//                print_on_click_exit();
//                move(0, 0);
//            }
        }
        else if (wait == '\n' && pos == 1)
        {
            return pos;
        }
        else if (wait == '\n' && pos == 2)
        {
            clear();
            return choose_map();
        }
        else if (wait == '\n' && pos == 3)
        {
            return 5;
        }
    }while (wait != '\n');

    getch();
    return 1;
}