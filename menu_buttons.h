//
// Created by Ha1do on 07.12.2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <curses.h>
#include <time.h>

void print_hollow_play()
{
    mvprintw(12, 71, "+--------------+");
    mvprintw(13, 71, "|     PLAY     |");
    mvprintw(14, 71, "|    MAP (1)   |");
    mvprintw(15, 71, "+--------------+");
}
void print_on_click_play()
{
    mvprintw(12, 71, "+--------------+");
    mvprintw(13, 71, "|     ");
    attron(COLOR_PAIR(9));
    mvprintw(13, 77, "PLAY");
    attroff(COLOR_PAIR(9));
    mvprintw(13, 81, "     |");
    mvprintw(14, 71, "|    ");
    attron(COLOR_PAIR(9));
    mvprintw(14, 76, "MAP (1)");
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

void print_hollow_exit()
{
    mvprintw(19, 71, "+--------------+");
    mvprintw(20, 71, "|     EXIT     |");
    mvprintw(21, 71, "+--------------+");
}
void print_on_click_exit()
{
    mvprintw(19, 71, "+--------------+");
    mvprintw(20, 71, "|");
    attron(COLOR_PAIR(9));
    mvprintw(20, 77, "EXIT");
    attroff(COLOR_PAIR(9));
    mvprintw(20, 86, "|");
    mvprintw(21, 71, "+--------------+");
}