//
// Created by Ha1do on 05.12.2023.
// -std=c11 -Werror -Wall -Wno-vla-parameter -lcurses
#include <unistd.h>
#include "pac-man.h"



int main()
{
    initscr();
    noecho();
    keypad(stdscr, true);
    if (has_colors() == FALSE)
    {
        endwin();
        printf("Your terminal does not support color\n");
        exit(1);
    }
    start_color();
    init_pair(9,COLOR_BLACK,COLOR_WHITE);

    int difficulty = 2;
    int game_map = 1;
    game_map = print_menu(game_map, &difficulty);

    // ! read info from file
    FILE *fp;

    int weight, height, Ox, Oy, Px, Py, Bx, By, Cx, Cy, Ix, Iy;
    int lives = 3, score = 0, delta_time, time = get_stert_time();
    int highest_score;

    if (game_map == 1)
    {
        fp = fopen("/root/GitLab/test-dir/ps6_the_game/level_1.txt", "r");
        if(fp == NULL){
            printf("Error opening file.\n");
            exit(EXIT_FAILURE);
        }
    }
    else if (game_map == 2)
    {
        fp = fopen("/root/GitLab/test-dir/ps6_the_game/level_2.txt", "r");
        if(fp == NULL){
            printf("Error opening file.\n");
            exit(EXIT_FAILURE);
        }
    }
    else if (game_map == 3)
    {
        fp = fopen("/root/GitLab/test-dir/ps6_the_game/level_3.txt", "r");
        if(fp == NULL){
            printf("Error opening file.\n");
            exit(EXIT_FAILURE);
        }
    }
    else if (game_map == 4)
    {
        fp = fopen("/root/GitLab/test-dir/ps6_the_game/level_4.txt", "r");
        if(fp == NULL){
            printf("Error opening file.\n");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        endwin();
        printf("We fucked up\n");
        exit(1);
    }



    fscanf(fp, "weight=%d, height=%d, highest_score=%d, Ox=%d, Oy=%d, Px=%d, Py=%d, Bx=%d, By=%d, Cx=%d, Cy=%d, Ix=%d, Iy=%d\n",
           &weight, &height, &highest_score, &Ox, &Oy, &Px, &Py, &Bx, &By, &Cx, &Cy, &Ix, &Iy);

    char map[height][weight];
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < weight; j++) {
            fscanf(fp, "%c", &map[i][j]);
        }
        fscanf(fp, "\n");
    }

    fclose(fp);
    // ? END reading info from file

    // ! COLORING
    map[Oy][Ox] = '@';//PACMAN
    map[Oy][Ox + 1] = '@';//PACMAN

    map[Py][Px] = 'P';//PINKY
    map[Py][Px + 1] = 'P';//PINKY

    map[By][Bx] = 'B';//BLINKY
    map[By][Bx + 1] = 'B';//BLINKY

    map[Cy][Cx] = 'C';//CLYDE
    map[Cy][Cx + 1] = 'C';//CLYDE

    map[Iy][Ix] = 'I';//INKY
    map[Iy][Ix + 1] = 'I';//INKY


    init_pair(WALL_PAIR,COLOR_BLUE,COLOR_BLUE);
    init_pair(2,COLOR_BLACK,COLOR_BLACK);
    init_pair(PACMAN_PAIR,COLOR_YELLOW,COLOR_YELLOW);
    init_pair(BLINKY_PAIR,COLOR_RED,COLOR_RED);
    init_pair(PINKY_PAIR,COLOR_MAGENTA,COLOR_MAGENTA);
    init_pair(INKY_PAIR,COLOR_GREEN,COLOR_GREEN);
    init_pair(CLYDE_PAIR,COLOR_CYAN,COLOR_CYAN);
    // ? END OF COLORING


    delta_time = get_game_time(time);
    print_gamefield(height, weight, map, lives, score, highest_score, delta_time);
    clear();
    refresh();

    int key_pressed;
    char last_move = '0';
    int tick = 0;
    int clyde_moves = 0, inky_moves = 0, pinky_moves = 0, blinky_moves = 0;
    char clyde_smer, inky_smer, pinky_smer, blinky_smer;
    bool is_dead = false;
    halfdelay(difficulty);
    do{
        fflush(stdin);
        if (game_map == 1 && tick == 30)
        {
            map[9][16] = '_';
            map[9][17] = '_';
        }
//        else if (game_map == 2 && tick == 30)
//        {
//            map[9][16] = '_';
//            map[9][17] = '_'; TODO
//        }
//        else if (game_map == 3 && tick == 30)
//        {
//            map[9][16] = '_';
//            map[9][17] = '_';
//        }
//        else if (game_map == 4 && tick == 30)
//        {
//            map[9][16] = '_';
//            map[9][17] = '_';
//        }

//        if (pacman dead) todo

        if(key_pressed == 'D' || key_pressed == 'd' || key_pressed == KEY_RIGHT)
        {
            if (is_wall_r(Oy, Ox, height, weight, map))
            {
                score = move_pacman_r(Oy, Ox, &is_dead, height, weight, map, score);
                Ox++;
            }


            if (score > 10000)
            {
                printw("dead by ghost\n");
//                lives--; TODO
            }
            last_move = 'r';
        }
        else if(key_pressed == 'A' || key_pressed == 'a' || key_pressed == KEY_LEFT)
        {
            if (is_wall_l(Oy, Ox, height, weight, map))
            {
                score = move_pacman_l(Oy, Ox, &is_dead, height, weight, map, score);
                Ox--;
            }


            if (score > 10000)
            {
                printw("dead by ghost\n");
//                lives--; TODO
            }
            last_move = 'l';
        }
        else if(key_pressed == 'S' || key_pressed == 's' || key_pressed == KEY_DOWN)
        {
            if (is_wall_d(Oy, Ox, height, weight, map))
            {
                score = move_pacman_d(Oy, Ox, &is_dead, height, weight, map, score);
                Oy++;
            }

            if (score > 10000)
            {
                printw("dead by ghost\n");
//                lives--; TODO
            }
            last_move = 'd';
        }
        else if(key_pressed == 'W' || key_pressed == 'w' || key_pressed == KEY_UP)
        {
            if (is_wall_u(Oy, Ox, height, weight, map))
            {
                score = move_pacman_u(Oy, Ox, &is_dead, height, weight, map, score);
                Oy--;
            }


            if (score > 10000)
            {
                printw("dead by ghost\n");
//                lives--; TODO
            }
            last_move = 'u';
        }
        else
        {
            if(last_move == 'r')
            {
                if (is_wall_r(Oy, Ox, height, weight, map))
                {
                    score = move_pacman_r(Oy, Ox, &is_dead, height, weight, map, score);
                    Ox++;
                }


                if (score > 10000)
                {
                    printw("dead by ghost\n");
//                lives--; TODO
                }
            }
            if(last_move == 'l')
            {
                if (is_wall_l(Oy, Ox, height, weight, map))
                {
                    score = move_pacman_l(Oy, Ox, &is_dead, height, weight, map, score);
                    Ox--;
                }


                if (score > 10000)
                {
                    printw("dead by ghost\n");
//                lives--; TODO
                }
            }
            if(last_move == 'd')
            {
                if (is_wall_d(Oy, Ox, height, weight, map))
                {
                    score = move_pacman_d(Oy, Ox, &is_dead, height, weight, map, score);
                    Oy++;
                }


                if (score > 10000)
                {
                    printw("dead by ghost\n");
//                lives--; TODO
                }
            }
            if(last_move == 'u')
            {
                if (is_wall_u(Oy, Ox, height, weight, map))
                {
                    score = move_pacman_u(Oy, Ox, &is_dead, height, weight, map, score);
                    Oy--;
                }


                if (score > 10000)
                {
                    printw("dead by ghost\n");
//                lives--; TODO
                }
            }
        }
////        if(pacman.power_up == 1 && time == 0)
////        {
////            pacman.power_up = 0;
////            time = 25; TODO
////        }
////        else if(pacman.power_up == 1 && time != 0)
////            time--;

        // ! ghosts movement
//        if (tick < 35) TODO ?????
//        {
//            Cx = clyde_move_side_to_side(Cy, Cx, height, weight, map);
//            Ix = inky_move_side_to_side(Iy, Ix, height, weight, map);
//            Px = pinky_move_side_to_side(Py, Px, height, weight, map);
//            Bx = blinky_move_side_to_side(By, Bx, height, weight, map);
//        }
//        else if (tick < 40)
//        {
//            Ix = inky_move_side_to_side(Iy, Ix, height, weight, map);
//            Px = pinky_move_side_to_side(Py, Px, height, weight, map);
//            Bx = blinky_move_side_to_side(By, Bx, height, weight, map);
//        }
//        else if (tick < 45)
//        {
//            Px = pinky_move_side_to_side(Py, Px, height, weight, map);
//            Bx = blinky_move_side_to_side(By, Bx, height, weight, map);
//        }
//        else if (tick < 50)
//        {
//            Bx = blinky_move_side_to_side(By, Bx), height, weight, map;
//        }

        if (tick >= 35)
        {
            clyde(&clyde_moves, &clyde_smer, &Cy, &Cx, &is_dead, height, weight, map);
        }
        if (tick >= 40)
        {
            inky(&inky_moves, &inky_smer, &Iy, &Ix, &is_dead, height, weight, map);
        }
        if (tick >= 45)
        {
            pinky(&pinky_moves, &pinky_smer, &Py, &Px, &is_dead, height, weight, map);
        }
        if (tick >= 50)
        {
            blinky(&blinky_moves, &blinky_smer, &By, &Bx, &is_dead, height, weight, map);
        }

        if (is_dead)
        {
            is_dead = false;
            if (lives > 1)
            {
                lives--;
                tick = 0;
                score = 0;
                time = get_stert_time();
                if (game_map == 1)
                {
                    fp = fopen("/root/GitLab/test-dir/ps6_the_game/level_1.txt", "r");
                    if(fp == NULL){
                        printf("Error opening file.\n");
                        exit(EXIT_FAILURE);
                    }
                }
                else if (game_map == 2)
                {
                    fp = fopen("/root/GitLab/test-dir/ps6_the_game/level_2.txt", "r");
                    if(fp == NULL){
                        printf("Error opening file.\n");
                        exit(EXIT_FAILURE);
                    }
                }
                else if (game_map == 3)
                {
                    fp = fopen("/root/GitLab/test-dir/ps6_the_game/level_3.txt", "r");
                    if(fp == NULL){
                        printf("Error opening file.\n");
                        exit(EXIT_FAILURE);
                    }
                }
                else if (game_map == 4)
                {
                    fp = fopen("/root/GitLab/test-dir/ps6_the_game/level_4.txt", "r");
                    if(fp == NULL){
                        printf("Error opening file.\n");
                        exit(EXIT_FAILURE);
                    }
                }
                fscanf(fp, "weight=%d, height=%d, highest_score=%d, Ox=%d, Oy=%d, Px=%d, Py=%d, Bx=%d, By=%d, Cx=%d, Cy=%d, Ix=%d, Iy=%d\n",
                       &weight, &height, &highest_score, &Ox, &Oy, &Px, &Py, &Bx, &By, &Cx, &Cy, &Ix, &Iy);

                for (int i = 0; i < height; i++) {
                    for (int j = 0; j < weight; j++) {
                        fscanf(fp, "%c", &map[i][j]);
                    }
                    fscanf(fp, "\n");
                }

                fclose(fp);
                // ? END reading info from file

                // ! COLORING
                map[Oy][Ox] = '@';//PACMAN
                map[Oy][Ox + 1] = '@';//PACMAN

                map[Py][Px] = 'P';//PINKY
                map[Py][Px + 1] = 'P';//PINKY

                map[By][Bx] = 'B';//BLINKY
                map[By][Bx + 1] = 'B';//BLINKY

                map[Cy][Cx] = 'C';//CLYDE
                map[Cy][Cx + 1] = 'C';//CLYDE

                map[Iy][Ix] = 'I';//INKY
                map[Iy][Ix + 1] = 'I';//INKY
            }
            else if (lives == 1)
            {
                clear();
                mvprintw (30, 50, "GAME OVER");
                refresh();
                sleep(3);
                endwin();
                return 0;
            }
        }
        if (is_win(height, weight, map))
        {
            clear();
            mvprintw (30, 50, "CONGRATS YOU WON");
            refresh();
            sleep(3);
            endwin();
            return 0;
        }


        clear();
        delta_time =  get_game_time(time);
        print_gamefield(height, weight, map, lives, score, highest_score, delta_time);
        refresh();
        tick++;
    }while(((key_pressed = getch())!= 'x')/* && (pacman_life > 0) && (pacman.score < 995)*/);


    getch(); // Wait for key press before exiting
    endwin();
    return 0;
}