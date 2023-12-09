//
// Created by Ha1do on 09.12.2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <curses.h>
#include <time.h>

bool is_win(const int height, const int weight, char map[height][weight])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < weight; j++)
        {
            if (map[i][j] == '.')
            {
                return false;
            }
        }
    }
    return true;
}
