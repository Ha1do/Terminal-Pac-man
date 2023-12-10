//
// Created by Ha1do on 09.12.2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <curses.h>
#include <time.h>
#include <string.h>

//void update_highest_score(const char *filename, int new_score) {
//    FILE *file = fopen(filename, "r");
//    FILE *temp = fopen("temp.txt", "w");
//
//    if (file == NULL || temp == NULL) {
//        printf("Ошибка открытия файла.\n");
//        return;
//    }
//
//    char line[256];
//    while (fgets(line, sizeof(line), file)) {
//        if (strstr(line, "highest_score") != NULL) {
//            fprintf(temp, "highest_score=%d,\n", new_score);
//        } else {
//            fprintf(temp, "%s", line);
//        }
//    }
//
//    fclose(file);
//    fclose(temp);
//
//    remove(filename);
//    rename("temp.txt", filename);
//}

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

void print_over(const int score)
{
    init_pair(10, COLOR_RED, COLOR_BLACK);
    attron(COLOR_PAIR(10));
    mvprintw(15, 40, "   _____              __  __   ______      ____   __      __  ______   _____  ");
    mvprintw(16, 40, "  / ____|     /\\     |  \\/  | |  ____|    / __ \\  \\ \\    / / |  ____| |  __ \\ ");
    mvprintw(17, 40, " | |  __     /  \\    | \\  / | | |__      | |  | |  \\ \\  / /  | |__    | |__) |");
    mvprintw(18, 40, " | | |_ |   / /\\ \\   | |\\/| | |  __|     | |  | |   \\ \\/ /   |  __|   |  _  / ");
    mvprintw(19, 40, " | |__| |  / ____ \\  | |  | | | |____    | |__| |    \\  /    | |____  | | \\ \\ ");
    mvprintw(20, 40, "  \\_____| /_/    \\_\\ |_|  |_| |______|    \\____/      \\/     |______| |_|  \\_\\");
    attroff(COLOR_PAIR(10));
    mvprintw(22, 65, "Your score is: %d. Pretty Good i think", score);
    mvprintw(23, 50, "Also, try again or play on other map. Or may be reduce difficulty");
    mvprintw(26, 65, "Press any key to exit in menu");


    attron(COLOR_PAIR(10));
    mvprintw(30, 124, "__  __");
    mvprintw(31, 124, "\\ \\/ /");
    mvprintw(32, 124, " >  < ");
    mvprintw(33, 124, "/_/\\_\\");
    attroff(COLOR_PAIR(10));

    attron(COLOR_PAIR(10));
    mvprintw(7, 128, "__  __");
    mvprintw(8, 128, "\\ \\/ /");
    mvprintw(9, 128, " >  < ");
    mvprintw(10, 128, "/_/\\_\\");
    attroff(COLOR_PAIR(10));

    attron(COLOR_PAIR(10));
    mvprintw(5, 40, "__  __");
    mvprintw(6, 40, "\\ \\/ /");
    mvprintw(7, 40, " >  < ");
    mvprintw(8, 40, "/_/\\_\\");
    attroff(COLOR_PAIR(10));

    attron(COLOR_PAIR(10));
    mvprintw(28, 52, "__  __");
    mvprintw(29, 52, "\\ \\/ /");
    mvprintw(30, 52, " >  < ");
    mvprintw(31, 52, "/_/\\_\\");
    attroff(COLOR_PAIR(10));

    attron(COLOR_PAIR(10));
    mvprintw(10, 11, "\\/ ");
    mvprintw(11, 11, "/\\");
    attroff(COLOR_PAIR(10));

    attron(COLOR_PAIR(10));
    mvprintw(12, 25, "\\/ ");
    mvprintw(13, 25, "/\\");
    attroff(COLOR_PAIR(10));

    attron(COLOR_PAIR(10));
    mvprintw(9, 70, "\\/ ");
    mvprintw(10, 70, "/\\");
    attroff(COLOR_PAIR(10));

    attron(COLOR_PAIR(10));
    mvprintw(7, 86, "\\/ ");
    mvprintw(8, 86, "/\\");
    attroff(COLOR_PAIR(10));

    attron(COLOR_PAIR(10));
    mvprintw(5, 79, "\\/ ");
    mvprintw(6, 79, "/\\");
    attroff(COLOR_PAIR(10));

    attron(COLOR_PAIR(10));
    mvprintw(18, 130, "\\/ ");
    mvprintw(19, 130, "/\\");
    attroff(COLOR_PAIR(10));

    attron(COLOR_PAIR(10));
    mvprintw(21, 15, "\\/ ");
    mvprintw(22, 15, "/\\");
    attroff(COLOR_PAIR(10));

    attron(COLOR_PAIR(10));
    mvprintw(27, 39, "\\/ ");
    mvprintw(28, 39, "/\\");
    attroff(COLOR_PAIR(10));

    attron(COLOR_PAIR(10));
    mvprintw(31, 76, "\\/ ");
    mvprintw(32, 76, "/\\");
    attroff(COLOR_PAIR(10));
    move(0, 0);
}
void print_win(const int score)
{
    init_pair(11, COLOR_GREEN, COLOR_BLACK);
    init_pair(12, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(13, COLOR_YELLOW, COLOR_BLACK);
    init_pair(14, COLOR_CYAN, COLOR_BLACK);
    attron(COLOR_PAIR(11));
    mvprintw(15, 60, "__      __ ___  _  _  _  _  ___  ___ ");
    mvprintw(16, 60, "\\ \\    / /|_ _|| \\| || \\| || __|| _ \\");
    mvprintw(17, 60, " \\ \\/\\/ /  | | | .  || .  || _| |   /");
    mvprintw(18, 60, "  \\_/\\_/  |___||_|\\_||_|\\_||___||_|_\\");
    attroff(COLOR_PAIR(11));

    attron(COLOR_PAIR(12));
    mvprintw(31, 76, " \\ ");
    attroff(COLOR_PAIR(12));
    attron(COLOR_PAIR(13));
    mvprintw(31, 79, "|");
    attroff(COLOR_PAIR(13));
    mvprintw(31, 80, " / ");
    attron(COLOR_PAIR(14));
    mvprintw(32, 76, "-- ");
    attroff(COLOR_PAIR(14));
    mvprintw(32, 79, "o");
    attron(COLOR_PAIR(13));
    mvprintw(32, 80, " --");
    attroff(COLOR_PAIR(12));
    mvprintw(33, 76, " /");
    attron(COLOR_PAIR(13));
    mvprintw(33, 78, " |");
    attroff(COLOR_PAIR(13));
    attron(COLOR_PAIR(14));
    mvprintw(33, 80, " \\");
    attroff(COLOR_PAIR(14));

    attron(COLOR_PAIR(12));
    mvprintw(23, 96, " \\ ");
    attroff(COLOR_PAIR(12));
    attron(COLOR_PAIR(13));
    mvprintw(23, 99, "|");
    attroff(COLOR_PAIR(13));
    mvprintw(23, 100, " / ");
    attron(COLOR_PAIR(14));
    mvprintw(24, 96, "-- ");
    attroff(COLOR_PAIR(14));
    mvprintw(24, 99, "o");
    attron(COLOR_PAIR(13));
    mvprintw(24, 100, " --");
    attroff(COLOR_PAIR(12));
    mvprintw(25, 96, " /");
    attron(COLOR_PAIR(13));
    mvprintw(25, 98, " |");
    attroff(COLOR_PAIR(13));
    attron(COLOR_PAIR(14));
    mvprintw(25, 100, " \\");
    attroff(COLOR_PAIR(14));

    attron(COLOR_PAIR(12));
    mvprintw(15, 33, " \\ ");
    attroff(COLOR_PAIR(12));
    attron(COLOR_PAIR(13));
    mvprintw(15, 36, "|");
    attroff(COLOR_PAIR(13));
    mvprintw(15, 37, " / ");
    attron(COLOR_PAIR(14));
    mvprintw(16, 33, "-- ");
    attroff(COLOR_PAIR(14));
    mvprintw(16, 36, "o");
    attron(COLOR_PAIR(13));
    mvprintw(16, 37, " --");
    attroff(COLOR_PAIR(12));
    mvprintw(17, 33, " /");
    attron(COLOR_PAIR(13));
    mvprintw(17, 35, " |");
    attroff(COLOR_PAIR(13));
    attron(COLOR_PAIR(14));
    mvprintw(17, 37, " \\");
    attroff(COLOR_PAIR(14));


    attron(COLOR_PAIR(11));
    mvprintw(25, 60, "    _");
    mvprintw(26, 60, "  _| |_");
    mvprintw(27, 60, " |_   _|");
    mvprintw(28, 60, "   |_|");
    attroff(COLOR_PAIR(11));

    attron(COLOR_PAIR(11));
    mvprintw(20, 117, "    _");
    mvprintw(21, 117, "  _| |_");
    mvprintw(22, 117, " |_   _|");
    mvprintw(23, 117, "   |_|");
    attroff(COLOR_PAIR(11));

    attron(COLOR_PAIR(11));
    mvprintw(12, 100, "    _");
    mvprintw(13, 100, "  _| |_");
    mvprintw(14, 100, " |_   _|");
    mvprintw(15, 100, "   |_|");
    attroff(COLOR_PAIR(11));

    attron(COLOR_PAIR(12));
    mvprintw(11, 74, " \\ ");
    attroff(COLOR_PAIR(12));
    attron(COLOR_PAIR(13));
    mvprintw(11, 77, "|");
    attroff(COLOR_PAIR(13));
    mvprintw(11, 78, " / ");
    attron(COLOR_PAIR(14));
    mvprintw(12, 74, "-- ");
    attroff(COLOR_PAIR(14));
    mvprintw(12, 77, "o");
    attron(COLOR_PAIR(13));
    mvprintw(12, 78, " --");
    attroff(COLOR_PAIR(12));
    mvprintw(13, 74, " /");
    attron(COLOR_PAIR(13));
    mvprintw(13, 76, " |");
    attroff(COLOR_PAIR(13));
    attron(COLOR_PAIR(14));
    mvprintw(13, 78, " \\");
    attroff(COLOR_PAIR(14));

    attron(COLOR_PAIR(12));
    mvprintw(5, 24, " \\ ");
    attroff(COLOR_PAIR(12));
    attron(COLOR_PAIR(13));
    mvprintw(5, 27, "|");
    attroff(COLOR_PAIR(13));
    mvprintw(5, 28, " / ");
    attron(COLOR_PAIR(14));
    mvprintw(6, 24, "-- ");
    attroff(COLOR_PAIR(14));
    mvprintw(6, 27, "o");
    attron(COLOR_PAIR(13));
    mvprintw(6, 28, " --");
    attroff(COLOR_PAIR(12));
    mvprintw(7, 24, " /");
    attron(COLOR_PAIR(13));
    mvprintw(7, 26, " |");
    attroff(COLOR_PAIR(13));
    attron(COLOR_PAIR(14));
    mvprintw(7, 28, " \\");
    attroff(COLOR_PAIR(14));

    attron(COLOR_PAIR(11));
    mvprintw(28, 30, "    _");
    mvprintw(29, 30, "  _| |_");
    mvprintw(30, 30, " |_   _|");
    mvprintw(31, 30, "   |_|");
    attroff(COLOR_PAIR(11));

    attron(COLOR_PAIR(12));
    mvprintw(11, 144, " \\ ");
    attroff(COLOR_PAIR(12));
    attron(COLOR_PAIR(13));
    mvprintw(11, 147, "|");
    attroff(COLOR_PAIR(13));
    mvprintw(11, 148, " / ");
    attron(COLOR_PAIR(14));
    mvprintw(12, 144, "-- ");
    attroff(COLOR_PAIR(14));
    mvprintw(12, 147, "o");
    attron(COLOR_PAIR(13));
    mvprintw(12, 148, " --");
    attroff(COLOR_PAIR(12));
    mvprintw(13, 144, " /");
    attron(COLOR_PAIR(13));
    mvprintw(13, 146, " |");
    attroff(COLOR_PAIR(13));
    attron(COLOR_PAIR(14));
    mvprintw(13, 148, " \\");
    attroff(COLOR_PAIR(14));

    move(0, 0);
}
