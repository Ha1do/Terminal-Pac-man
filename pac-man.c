//
// Created by Ha1do on 05.12.2023.
// -std=c11 -Werror -Wall -Wno-vla-parameter -lcurses
#include "pac-man.h"



int main()
{
    // ! read info from file
    FILE *fp;

    int weight, height, Ox, Oy, Px, Py, Bx, By, Cx, Cy, Ix, Iy;
    int lives = 3, score = 0, delta_time, time = get_stert_time();
    int highest_score;

    fp = fopen("/root/GitLab/test-dir/ps6_the_game/level_1.txt", "r");
    if(fp == NULL){
        printf("Error opening file.\n");
        exit(EXIT_FAILURE);
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

    int key_pressed;
    char last_move = '0';
    halfdelay(3);
    do{
        fflush(stdin);
        if(key_pressed == 'D' || key_pressed == 'd' || key_pressed == KEY_RIGHT)
        {
            if (is_wall_r(Oy, Ox, height, weight, map))
            {
                score = move_pacman_r(Oy, Ox, height, weight, map, score);
                Ox++;
            }

            clear();

            delta_time =  get_game_time(time);
            print_gamefield(height, weight, map, lives, score, highest_score, delta_time);
            refresh();
            if (score > 10000)
            {
                printw("dead by ghost\n");
//                lives--;
            }
//            pacman = mv_pacman_right(map,pacman);
            last_move = 'r';
        }
        else if(key_pressed == 'A' || key_pressed == 'a' || key_pressed == KEY_LEFT)
        {
            if (is_wall_l(Oy, Ox, height, weight, map))
            {
                score = move_pacman_l(Oy, Ox, height, weight, map, score);
                Ox--;
            }

            clear();
            delta_time =  get_game_time(time);
            print_gamefield(height, weight, map, lives, score, highest_score, delta_time);
            refresh();
            if (score > 10000)
            {
                printw("dead by ghost\n");
//                lives--;
            }
//            pacman = mv_pacman_left(map,pacman);
            last_move = 'l';
        }
        else if(key_pressed == 'S' || key_pressed == 's' || key_pressed == KEY_DOWN)
        {
            if (is_wall_d(Oy, Ox, height, weight, map))
            {
                score = move_pacman_d(Oy, Ox, height, weight, map, score);
                Oy++;
            }

            clear();
            delta_time =  get_game_time(time);
            print_gamefield(height, weight, map, lives, score, highest_score, delta_time);
            refresh();
            if (score > 10000)
            {
                printw("dead by ghost\n");
//                lives--;
            }
//            pacman = mv_pacman_down(map,pacman);
            last_move = 'd';
        }
        else if(key_pressed == 'W' || key_pressed == 'w' || key_pressed == KEY_UP)
        {
            if (is_wall_u(Oy, Ox, height, weight, map))
            {
                score = move_pacman_u(Oy, Ox, height, weight, map, score);
                Oy--;
            }

            clear();
            delta_time =  get_game_time(time);
            print_gamefield(height, weight, map, lives, score, highest_score, delta_time);
            refresh();
            if (score > 10000)
            {
                printw("dead by ghost\n");
//                lives--;
            }
//            pacman = mv_pacman_up(map,pacman);
            last_move = 'u';
        }
        else
        {
            if(last_move == 'r')
            {
                if (is_wall_r(Oy, Ox, height, weight, map))
                {
                    score = move_pacman_r(Oy, Ox, height, weight, map, score);
                    Ox++;
                }

                clear();
                delta_time =  get_game_time(time);
            print_gamefield(height, weight, map, lives, score, highest_score, delta_time);
                refresh();
                if (score > 10000)
                {
                    printw("dead by ghost\n");
//                lives--;
                }
            }
            if(last_move == 'l')
            {
                if (is_wall_l(Oy, Ox, height, weight, map))
                {
                    score = move_pacman_l(Oy, Ox, height, weight, map, score);
                    Ox--;
                }

                clear();
                delta_time =  get_game_time(time);
            print_gamefield(height, weight, map, lives, score, highest_score, delta_time);
                refresh();
                if (score > 10000)
                {
                    printw("dead by ghost\n");
//                lives--;
                }
            }
            if(last_move == 'd')
            {
                if (is_wall_d(Oy, Ox, height, weight, map))
                {
                    score = move_pacman_d(Oy, Ox, height, weight, map, score);
                    Oy++;
                }

                clear();
                delta_time =  get_game_time(time);
            print_gamefield(height, weight, map, lives, score, highest_score, delta_time);
                refresh();
                if (score > 10000)
                {
                    printw("dead by ghost\n");
//                lives--;
                }
            }
            if(last_move == 'u')
            {
                if (is_wall_u(Oy, Ox, height, weight, map))
                {
                    score = move_pacman_u(Oy, Ox, height, weight, map, score);
                    Oy--;
                }

                clear();
                delta_time =  get_game_time(time);
            print_gamefield(height, weight, map, lives, score, highest_score, delta_time);
                refresh();
                if (score > 10000)
                {
                    printw("dead by ghost\n");
//                lives--;
                }
            }
        }
////        if(pacman.power_up == 1 && time == 0)
////        {
////            pacman.power_up = 0;
////            time = 25;
////        }
////        else if(pacman.power_up == 1 && time != 0)
////            time--;
//        if(clyde.last_move == 'k')
//        {
//            map[clyde.x0][clyde.y0] = FOOD;
//            map[clyde.x1][clyde.y1] = FOOD;
//            map[clyde.x2][clyde.y2] = FOOD;
//            map[clyde.x3][clyde.y3] = FOOD;
//            map[clyde.x4][clyde.y4] = FOOD;
//            map[clyde.x5][clyde.y5] = FOOD;
//            map[clyde.x6][clyde.y6] = FOOD;
//            map[clyde.x7][clyde.y7] = FOOD;
//            map[clyde.x8][clyde.y8] = FOOD;
//            clyde = ini_ghost(clyde_kills,'r',CLYDE,map,20,61,20,62,20,63,21,61,21,62,21,63,22,61,22,62,22,63);
//            display_map(map,pacman,blinky,inky,pinky,clyde);
//        }
//        if(inky.last_move == 'k')
//        {
//            map[inky.x0][inky.y0] = FOOD;
//            map[inky.x1][inky.y1] = FOOD;
//            map[inky.x2][inky.y2] = FOOD;
//            map[inky.x3][inky.y3] = FOOD;
//            map[inky.x4][inky.y4] = FOOD;
//            map[inky.x5][inky.y5] = FOOD;
//            map[inky.x6][inky.y6] = FOOD;
//            map[inky.x7][inky.y7] = FOOD;
//            map[inky.x8][inky.y8] = FOOD;
//            inky = ini_ghost(inky_kills,'n',INKY,map,20,57,20,58,20,59,21,57,21,58,21,59,22,57,22,58,22,59);
//            display_map(map,pacman,blinky,inky,pinky,clyde);        }
//        if(pinky.last_move == 'k')
//        {
//            map[pinky.x0][pinky.y0] = FOOD;
//            map[pinky.x1][pinky.y1] = FOOD;
//            map[pinky.x2][pinky.y2] = FOOD;
//            map[pinky.x3][pinky.y3] = FOOD;
//            map[pinky.x4][pinky.y4] = FOOD;
//            map[pinky.x5][pinky.y5] = FOOD;
//            map[pinky.x6][pinky.y6] = FOOD;
//            map[pinky.x7][pinky.y7] = FOOD;
//            map[pinky.x8][pinky.y8] = FOOD;
//            pinky = ini_ghost(pinky_kills,'n',PINKY,map,16,61,16,62,16,63,17,61,17,62,17,63,18,61,18,62,18,63);
//            display_map(map,pacman,blinky,inky,pinky,clyde);
//        }
//        if(blinky.last_move == 'k')
//        {
//            map[blinky.x0][blinky.y0] = FOOD;
//            map[blinky.x1][blinky.y1] = FOOD;
//            map[blinky.x2][blinky.y2] = FOOD;
//            map[blinky.x3][blinky.y3] = FOOD;
//            map[blinky.x4][blinky.y4] = FOOD;
//            map[blinky.x5][blinky.y5] = FOOD;
//            map[blinky.x6][blinky.y6] = FOOD;
//            map[blinky.x7][blinky.y7] = FOOD;
//            map[blinky.x8][blinky.y8] = FOOD;
//            blinky = ini_ghost(blinky_kills,'n',BLINKY,map,16,57,16,58,16,59,17,57,17,58,17,59,18,57,18,58,18,59);
//            display_map(map,pacman,blinky,inky,pinky,clyde);
//        }
//        if((blinky.kills != blinky_kills) || (pinky.kills != pinky_kills) || (inky.kills != inky_kills) || (clyde.kills != clyde_kills))
//        {
//            pacman_life--;
//            if(pacman_life != 0)
//            {
//                map = ini_map();
//                build_walls(map);
//                blinky_kills = blinky.kills;
//                pinky_kills = pinky.kills;
//                inky_kills = inky.kills;
//                clyde_kills = clyde.kills;
//                pacman = ini_pacman(map,2,2,2,3,2,4,3,2,3,3,3,4,4,2,4,3,4,4,pacman_life);
//                blinky = ini_ghost(blinky_kills,'n',BLINKY,map,16,57,16,58,16,59,17,57,17,58,17,59,18,57,18,58,18,59);
//                pinky = ini_ghost(pinky_kills,'n',PINKY,map,16,61,16,62,16,63,17,61,17,62,17,63,18,61,18,62,18,63);
//                inky = ini_ghost(inky_kills,'n',INKY,map,20,57,20,58,20,59,21,57,21,58,21,59,22,57,22,58,22,59);
//                clyde = ini_ghost(clyde_kills,'n',CLYDE,map,20,61,20,62,20,63,21,61,21,62,21,63,22,61,22,62,22,63);
//                display_map(map,pacman,blinky,inky,pinky,clyde);
//            }
//            // break;
//        }
//        blinky = blinky_movement(map,blinky,pacman);
//        pinky = pinky_movement(map, pinky, pacman, key_pressed, last_move);
//        inky = inky_movement(map, inky, pacman, blinky);
//        clyde = clyde_movement(map, clyde, pacman);
//        display_map(map,pacman,blinky,inky,pinky,clyde);
        delta_time =  get_game_time(time);
            print_gamefield(height, weight, map, lives, score, highest_score, delta_time);
    }while(((key_pressed = getch())!= 'x')/* && (pacman_life > 0) && (pacman.score < 995)*/);


    getch(); // Wait for key press before exiting
    endwin();
    return 0;
}