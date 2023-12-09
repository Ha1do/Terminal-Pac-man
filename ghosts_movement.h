//
// Created by Ha1do on 08.12.2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <curses.h>
#include <time.h>

//int clyde_move_side_to_side(const int Cy, const int Cx, const int height, const int weight, char map[height][weight])
//{
//    bool hit_right_wall;
//    if (map[Cy][Cx + 2] != '#')
//    {
//        hit_right_wall = false;
//    }
//    else
//    {
//        hit_right_wall = true;
//    }
//
//    if (map[Cy][Cx + 2] != '#' && !hit_right_wall)
//    {
//        map[Cy][Cx] = '_';
//        map[Cy][Cx + 2] = 'C';
//    }
//    else
//    {
//        hit_right_wall = true;
//    }
//
//    if (map[Cy][Cx - 1] != '#' && hit_right_wall)
//    {
//        map[Cy][Cx + 2] = '_';
//        map[Cy][Cx - 1] = 'C';
//    }
//    else
//    {
//        hit_right_wall = false;
//    }
//}
//int inky_move_side_to_side(const int Iy, const int Ix, const int height, const int weight, char map[height][weight])
//{
//
//}
//int pinky_move_side_to_side(const int Py, const int Px, const int height, const int weight, char map[height][weight])
//{
//
//}
//int blinky_move_side_to_side(const int By, const int Bx, const int height, const int weight, char map[height][weight])
//{
//
//}

void random_smer_gener(char* smer, int* count)
{
    srand(time(NULL));
    //    rand() % 100 + 1
    int random_smer = rand() % 4 + 1;
    switch (random_smer)
    {
        case 1:
            *smer = 'N';
            break;
        case 2:
            *smer = 'S';
            break;
        case 3:
            *smer = 'E';
            break;
        case 4:
            *smer = 'W';
            break;
        default:
            *smer = 'N';
    }
    *count = rand() % 6 + 1;
}

char RSG()
{
    //    rand() % 100 + 1
    int random_smer = rand() % 4 + 1;
    switch (random_smer)
    {
        case 1:
            return 'N';
            break;
        case 2:
            return 'S';
            break;
        case 3:
            return 'E';
            break;
        case 4:
            return 'W';
            break;
        default:
            return 'N';
    }
}

void clyde(int* moves, char* smer, int* Cy, int* Cx, bool* dead, const int height, const int weight, char map[height][weight])
{
    if (*moves == 0)
    {
        random_smer_gener(smer, moves);
    }

    if (*smer == 'N')
    {
        if (map[*Cy - 1][*Cx] != '#' && map[*Cy - 1][*Cx + 1] != '#' &&
            map[*Cy - 1][*Cx] != 'B' && map[*Cy - 1][*Cx + 1] != 'B' &&
            map[*Cy - 1][*Cx] != 'P' && map[*Cy - 1][*Cx + 1] != 'P' &&
            map[*Cy - 1][*Cx] != 'I' && map[*Cy - 1][*Cx + 1] != 'I')
        {
            if (map[*Cy - 1][*Cx] == '@' || map[*Cy - 1][*Cx + 1] == '@')
            {
                *dead = true;
            }
            map[*Cy][*Cx] = map[*Cy - 1][*Cx];
            map[*Cy][*Cx + 1] = map[*Cy - 1][*Cx + 1];
            map[*Cy - 1][*Cx] = 'C';
            map[*Cy - 1][*Cx + 1] = 'C';
            *Cy = *Cy - 1;
            *moves = *moves - 1;
        }
        else
        {
            char sym = RSG();
            *smer = sym;
            clyde (moves, smer, Cy, Cx, dead, height, weight, map);
        }
    }
    if (*smer == 'W')
    {
        if (map[*Cy][*Cx + 2] != '#' &&
            map[*Cy][*Cx + 2] != 'B' &&
            map[*Cy][*Cx + 2] != 'P' &&
            map[*Cy][*Cx + 2] != 'I')
        {
            if (map[*Cy - 1][*Cx] == '@' || map[*Cy - 1][*Cx + 1] == '@')
            {
                *dead = true;
            }
            map[*Cy][*Cx] = map[*Cy][*Cx + 2];
            map[*Cy][*Cx + 2] = 'C';
            *Cx = *Cx + 1;
            *moves = *moves - 1;
        }
        else
        {
            char sym = RSG();
            *smer = sym;
            clyde (moves, smer, Cy, Cx, dead, height, weight, map);
        }
    }
    if (*smer == 'E')
    {
        if (map[*Cy][*Cx - 1] != '#' &&
            map[*Cy][*Cx - 1] != 'B' &&
            map[*Cy][*Cx - 1] != 'P' &&
            map[*Cy][*Cx - 1] != 'I')
        {
            if (map[*Cy - 1][*Cx] == '@' || map[*Cy - 1][*Cx + 1] == '@')
            {
                *dead = true;
            }
            map[*Cy][*Cx + 1] = map[*Cy][*Cx - 1];
            map[*Cy][*Cx - 1] = 'C';
            *Cx = *Cx - 1;
            *moves = *moves - 1;
        }
        else
        {
            char sym = RSG();
            *smer = sym;
            clyde (moves, smer, Cy, Cx, dead, height, weight, map);
        }
    }
    if (*smer == 'S')
    {
        if (map[*Cy + 1][*Cx] != '#' && map[*Cy + 1][*Cx + 1] != '#' &&
            map[*Cy + 1][*Cx] != 'B' && map[*Cy + 1][*Cx + 1] != 'B' &&
            map[*Cy + 1][*Cx] != 'P' && map[*Cy + 1][*Cx + 1] != 'P' &&
            map[*Cy + 1][*Cx] != 'I' && map[*Cy + 1][*Cx + 1] != 'I')
        {
            if (map[*Cy - 1][*Cx] == '@' || map[*Cy - 1][*Cx + 1] == '@')
            {
                *dead = true;
            }
            map[*Cy][*Cx] = map[*Cy + 1][*Cx];
            map[*Cy][*Cx + 1] = map[*Cy + 1][*Cx + 1];
            map[*Cy + 1][*Cx] = 'C';
            map[*Cy + 1][*Cx + 1] = 'C';
            *Cy = *Cy + 1;
            *moves = *moves - 1;
        }
        else
        {
            char sym = RSG();
            *smer = sym;
            clyde (moves, smer, Cy, Cx, dead, height, weight, map);
        }
    }
}
void inky(int* moves, char* smer, int* Iy, int* Ix, bool* dead, const int height, const int weight, char map[height][weight])
{
    if (*moves == 0)
    {
        random_smer_gener(smer, moves);
    }

    if (*smer == 'N')
    {
        if (map[*Iy - 1][*Ix] != '#' && map[*Iy - 1][*Ix + 1] != '#' &&
            map[*Iy - 1][*Ix] != 'B' && map[*Iy - 1][*Ix + 1] != 'B' &&
            map[*Iy - 1][*Ix] != 'P' && map[*Iy - 1][*Ix + 1] != 'P' &&
            map[*Iy - 1][*Ix] != 'C' && map[*Iy - 1][*Ix + 1] != 'C')
        {
            if (map[*Iy - 1][*Ix] == '@' || map[*Iy - 1][*Ix + 1] == '@')
            {
                *dead = true;
            }
            map[*Iy][*Ix] = map[*Iy - 1][*Ix];
            map[*Iy][*Ix + 1] = map[*Iy - 1][*Ix + 1];
            map[*Iy - 1][*Ix] = 'I';
            map[*Iy - 1][*Ix + 1] = 'I';
            *Iy = *Iy - 1;
            *moves = *moves - 1;
        }
        else
        {
            char sym = RSG();
            *smer = sym;
            inky (moves, smer, Iy, Ix, dead, height, weight, map);
        }
    }
    if (*smer == 'W')
    {
        if (map[*Iy][*Ix + 2] != '#' &&
            map[*Iy][*Ix + 2] != 'B' &&
            map[*Iy][*Ix + 2] != 'P' &&
            map[*Iy][*Ix + 2] != 'C')
        {
            if (map[*Iy - 1][*Ix] == '@' || map[*Iy - 1][*Ix + 1] == '@')
            {
                *dead = true;
            }
            map[*Iy][*Ix] = map[*Iy][*Ix + 2];
            map[*Iy][*Ix + 2] = 'I';
            *Ix = *Ix + 1;
            *moves = *moves - 1;
        }
        else
        {
            char sym = RSG();
            *smer = sym;
            inky (moves, smer, Iy, Ix, dead, height, weight, map);
        }
    }
    if (*smer == 'E')
    {
        if (map[*Iy][*Ix - 1] != '#' &&
            map[*Iy][*Ix - 1] != 'B' &&
            map[*Iy][*Ix - 1] != 'P' &&
            map[*Iy][*Ix - 1] != 'C')
        {
            if (map[*Iy - 1][*Ix] == '@' || map[*Iy - 1][*Ix + 1] == '@')
            {
                *dead = true;
            }
            map[*Iy][*Ix + 1] = map[*Iy][*Ix - 1];
            map[*Iy][*Ix - 1] = 'I';
            *Ix = *Ix - 1;
            *moves = *moves - 1;
        }
        else
        {
            char sym = RSG();
            *smer = sym;
            inky (moves, smer, Iy, Ix, dead, height, weight, map);
        }
    }
    if (*smer == 'S')
    {
        if (map[*Iy + 1][*Ix] != '#' && map[*Iy + 1][*Ix + 1] != '#' &&
            map[*Iy + 1][*Ix] != 'B' && map[*Iy + 1][*Ix + 1] != 'B' &&
            map[*Iy + 1][*Ix] != 'P' && map[*Iy + 1][*Ix + 1] != 'P' &&
            map[*Iy + 1][*Ix] != 'C' && map[*Iy + 1][*Ix + 1] != 'C')
        {
            if (map[*Iy - 1][*Ix] == '@' || map[*Iy - 1][*Ix + 1] == '@')
            {
                *dead = true;
            }
            map[*Iy][*Ix] = map[*Iy + 1][*Ix];
            map[*Iy][*Ix + 1] = map[*Iy + 1][*Ix + 1];
            map[*Iy + 1][*Ix] = 'I';
            map[*Iy + 1][*Ix + 1] = 'I';
            *Iy = *Iy + 1;
            *moves = *moves - 1;
        }
        else
        {
            char sym = RSG();
            *smer = sym;
            inky (moves, smer, Iy, Ix, dead, height, weight, map);
        }
    }
}
void pinky(int* moves, char* smer, int* Py, int* Px, bool* dead, const int height, const int weight, char map[height][weight])
{
    if (*moves == 0)
    {
        random_smer_gener(smer, moves);
    }

    if (*smer == 'N')
    {
        if (map[*Py - 1][*Px] != '#' && map[*Py - 1][*Px + 1] != '#' &&
            map[*Py - 1][*Px] != 'B' && map[*Py - 1][*Px + 1] != 'B' &&
            map[*Py - 1][*Px] != 'I' && map[*Py - 1][*Px + 1] != 'I' &&
            map[*Py - 1][*Px] != 'C' && map[*Py - 1][*Px + 1] != 'C')
        {
            if (map[*Py - 1][*Px] == '@' || map[*Py - 1][*Px + 1] == '@')
            {
                *dead = true;
            }
            map[*Py][*Px] = map[*Py - 1][*Px];
            map[*Py][*Px + 1] = map[*Py - 1][*Px + 1];
            map[*Py - 1][*Px] = 'P';
            map[*Py - 1][*Px + 1] = 'P';
            *Py = *Py - 1;
            *moves = *moves - 1;
        }
        else
        {
            char sym = RSG();
            *smer = sym;
            pinky (moves, smer, Py, Px, dead, height, weight, map);
        }
    }
    if (*smer == 'W')
    {
        if (map[*Py][*Px + 2] != '#' &&
            map[*Py][*Px + 2] != 'B' &&
            map[*Py][*Px + 2] != 'I' &&
            map[*Py][*Px + 2] != 'C')
        {
            if (map[*Py - 1][*Px] == '@' || map[*Py - 1][*Px + 1] == '@')
            {
                *dead = true;
            }
            map[*Py][*Px] = map[*Py][*Px + 2];
            map[*Py][*Px + 2] = 'P';
            *Px = *Px + 1;
            *moves = *moves - 1;
        }
        else
        {
            char sym = RSG();
            *smer = sym;
            pinky (moves, smer, Py, Px, dead, height, weight, map);
        }
    }
    if (*smer == 'E')
    {
        if (map[*Py][*Px - 1] != '#' &&
            map[*Py][*Px - 1] != 'B' &&
            map[*Py][*Px - 1] != 'I' &&
            map[*Py][*Px - 1] != 'C')
        {
            if (map[*Py - 1][*Px] == '@' || map[*Py - 1][*Px + 1] == '@')
            {
                *dead = true;
            }
            map[*Py][*Px + 1] = map[*Py][*Px - 1];
            map[*Py][*Px - 1] = 'P';
            *Px = *Px - 1;
            *moves = *moves - 1;
        }
        else
        {
            char sym = RSG();
            *smer = sym;
            pinky (moves, smer, Py, Px, dead, height, weight, map);
        }
    }
    if (*smer == 'S')
    {
        if (map[*Py + 1][*Px] != '#' && map[*Py + 1][*Px + 1] != '#' &&
            map[*Py + 1][*Px] != 'B' && map[*Py + 1][*Px + 1] != 'B' &&
            map[*Py + 1][*Px] != 'I' && map[*Py + 1][*Px + 1] != 'I' &&
            map[*Py + 1][*Px] != 'C' && map[*Py + 1][*Px + 1] != 'C')
        {
            if (map[*Py - 1][*Px] == '@' || map[*Py - 1][*Px + 1] == '@')
            {
                *dead = true;
            }
            map[*Py][*Px] = map[*Py + 1][*Px];
            map[*Py][*Px + 1] = map[*Py + 1][*Px + 1];
            map[*Py + 1][*Px] = 'P';
            map[*Py + 1][*Px + 1] = 'P';
            *Py = *Py + 1;
            *moves = *moves - 1;
        }
        else
        {
            char sym = RSG();
            *smer = sym;
            pinky (moves, smer, Py, Px, dead, height, weight, map);
        }
    }
}
void blinky(int* moves, char* smer, int* By, int* Bx, bool* dead, const int height, const int weight, char map[height][weight])
{
    if (*moves == 0)
    {
        random_smer_gener(smer, moves);
    }

    if (*smer == 'N')
    {
        if (map[*By - 1][*Bx] != '#' && map[*By - 1][*Bx + 1] != '#' &&
            map[*By - 1][*Bx] != 'I' && map[*By - 1][*Bx + 1] != 'I' &&
            map[*By - 1][*Bx] != 'P' && map[*By - 1][*Bx + 1] != 'P' &&
            map[*By - 1][*Bx] != 'C' && map[*By - 1][*Bx + 1] != 'C')
        {
            if (map[*By - 1][*Bx] == '@' || map[*By - 1][*Bx + 1] == '@')
            {
                *dead = true;
            }
            map[*By][*Bx] = map[*By - 1][*Bx];
            map[*By][*Bx + 1] = map[*By - 1][*Bx + 1];
            map[*By - 1][*Bx] = 'B';
            map[*By - 1][*Bx + 1] = 'B';
            *By = *By - 1;
            *moves = *moves - 1;
        }
        else
        {
            char sym = RSG();
            *smer = sym;
            blinky (moves, smer, By, Bx, dead, height, weight, map);
        }
    }
    if (*smer == 'W')
    {
        if (map[*By][*Bx + 2] != '#' &&
            map[*By][*Bx + 2] != 'I' &&
            map[*By][*Bx + 2] != 'P' &&
            map[*By][*Bx + 2] != 'C')
        {
            if (map[*By - 1][*Bx] == '@' || map[*By - 1][*Bx + 1] == '@')
            {
                *dead = true;
            }
            map[*By][*Bx] = map[*By][*Bx + 2];
            map[*By][*Bx + 2] = 'B';
            *Bx = *Bx + 1;
            *moves = *moves - 1;
        }
        else
        {
            char sym = RSG();
            *smer = sym;
            blinky (moves, smer, By, Bx, dead, height, weight, map);
        }
    }
    if (*smer == 'E')
    {
        if (map[*By][*Bx - 1] != '#' &&
            map[*By][*Bx - 1] != 'I' &&
            map[*By][*Bx - 1] != 'P' &&
            map[*By][*Bx - 1] != 'C')
        {
            if (map[*By - 1][*Bx] == '@' || map[*By - 1][*Bx + 1] == '@')
            {
                *dead = true;
            }
            map[*By][*Bx + 1] = map[*By][*Bx - 1];
            map[*By][*Bx - 1] = 'B';
            *Bx = *Bx - 1;
            *moves = *moves - 1;
        }
        else
        {
            char sym = RSG();
            *smer = sym;
            blinky (moves, smer, By, Bx, dead, height, weight, map);
        }
    }
    if (*smer == 'S')
    {
        if (map[*By + 1][*Bx] != '#' && map[*By + 1][*Bx + 1] != '#' &&
            map[*By + 1][*Bx] != 'I' && map[*By + 1][*Bx + 1] != 'I' &&
            map[*By + 1][*Bx] != 'P' && map[*By + 1][*Bx + 1] != 'P' &&
            map[*By + 1][*Bx] != 'C' && map[*By + 1][*Bx + 1] != 'C')
        {
            if (map[*By - 1][*Bx] == '@' || map[*By - 1][*Bx + 1] == '@')
            {
                *dead = true;
            }
            map[*By][*Bx] = map[*By + 1][*Bx];
            map[*By][*Bx + 1] = map[*By + 1][*Bx + 1];
            map[*By + 1][*Bx] = 'B';
            map[*By + 1][*Bx + 1] = 'B';
            *By = *By + 1;
            *moves = *moves - 1;
        }
        else
        {
            char sym = RSG();
            *smer = sym;
            blinky (moves, smer, By, Bx, dead, height, weight, map);
        }
    }
}
