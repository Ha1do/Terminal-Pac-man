//
// Created by Ha1do on 08.12.2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <curses.h>
#include <time.h>



int choose_difficulty()
{
    mvprintw(13, 60, "Please, choose game difficulty.");
    mvprintw(15, 64, "There is 4 difficulties:");
    mvprintw(16, 64, "Slow as a snail");
    mvprintw(17, 64, "Easy");
    mvprintw(18, 64, "Normal");
    mvprintw(19, 64, "Hard");
    getch();
    return 2;
}
