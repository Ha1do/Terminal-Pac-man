//
// Created by Ha1do on 06.12.2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <curses.h>
#include <time.h>

#define PACMAN '@'
#define BLINKY 'B'
#define PINKY 'P'
#define INKY 'I'
#define CLYDE 'C'
#define WALL '#'
#define BLANK '_'
#define FOOD '.'
#define ESP_FOOD ':'

#define WALL_PAIR 1
#define PACMAN_PAIR 3
#define BLINKY_PAIR 4
#define PINKY_PAIR 5
#define INKY_PAIR 6
#define CLYDE_PAIR 7
//#define SCARED_PAIR 8
#define LIN 40
#define COL 120

void print_gamefield(const int height, const int weight, const char map[height][weight],
                     const int lives, const int score, const int high_score, const int time)
{
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < weight; j++) {
            if (map[i][j] == WALL)
            {
                attron(COLOR_PAIR(WALL_PAIR));
                printw("%c",map[i][j]);
                attroff(COLOR_PAIR(WALL_PAIR));
            }
            else if (map[i][j] == BLANK)
            {
                attron(COLOR_PAIR(2));
                printw("%c",map[i][j]);
                attroff(COLOR_PAIR(2));
            }
            else if (map[i][j] == PACMAN)
            {
                attron(COLOR_PAIR(PACMAN_PAIR));
                printw("%c",map[i][j]);
                attroff(COLOR_PAIR(PACMAN_PAIR));
            }
            else if (map[i][j] == PINKY)
            {
                attron(COLOR_PAIR(PINKY_PAIR));
                printw("%c",map[i][j]);
                attroff(COLOR_PAIR(PINKY_PAIR));
            }
            else if (map[i][j] == BLINKY)
            {
                attron(COLOR_PAIR(BLINKY_PAIR));
                printw("%c",map[i][j]);
                attroff(COLOR_PAIR(BLINKY_PAIR));
            }
            else if (map[i][j] == INKY)
            {
                attron(COLOR_PAIR(INKY_PAIR));
                printw("%c",map[i][j]);
                attroff(COLOR_PAIR(INKY_PAIR));
            }
            else if (map[i][j] == CLYDE)
            {
                attron(COLOR_PAIR(CLYDE_PAIR));
                printw("%c",map[i][j]);
                attroff(COLOR_PAIR(CLYDE_PAIR));
            }
            else
            {
                printw("%c",map[i][j]);
            }
        }
        printw("\n");
    }
    mvprintw(3, weight + 5, "You have %d lives left\n", lives);
    mvprintw(4, weight + 5, "You have %d score\n", score);
    mvprintw(5, weight + 5, "Your highest score is %d\n", high_score);
    mvprintw(6, weight + 5, "Time is: %d\n", time);
    move(0, 0);

    refresh();
}

bool is_wall_r(const int Oy, const int Ox, const int height, const int weight, char map[height][weight])
{
    if (map[Oy][Ox + 2] != '#')
    {
        return true;
    }
    else
        return false;
}
int move_pacman_r(const int Oy, const int Ox, const int height, const int weight, char map[height][weight], int score)
{
        if (map[Oy][Ox + 2] == '_')
        {
            map[Oy][Ox] = '_';
            map[Oy][Ox + 2] = '@';
            return score;
        }
        else if (map[Oy][Ox + 2] == '.')
        {
            score++;
            map[Oy][Ox] = '_';
            map[Oy][Ox + 2] = '@';
            return score;
        }
    return score;
}

bool is_wall_l(const int Oy, const int Ox, const int height, const int weight, char map[height][weight])
{
    if (map[Oy][Ox - 1] != '#')
    {
        return true;
    }
    else
        return false;
}

int move_pacman_l(const int Oy, const int Ox, const int height, const int weight, char map[height][weight], int score)
{
    if (map[Oy][Ox - 1] == '_')
    {
        map[Oy][Ox + 1] = '_';
        map[Oy][Ox - 1] = '@';
        return score;
    }
    else if (map[Oy][Ox - 1] == '.')
    {
        score++;
        map[Oy][Ox + 1] = '_';
        map[Oy][Ox - 1] = '@';
        return score;
    }
    return score;
}