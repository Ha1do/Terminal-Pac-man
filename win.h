//
// Created by Ha1do on 09.12.2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <curses.h>
#include <time.h>
#include <string.h>

void update_highest_score(const char *filename, int new_score) {
    FILE *file = fopen(filename, "r");
    FILE *temp = fopen("temp.txt", "w");

    if (file == NULL || temp == NULL) {
        printf("Ошибка открытия файла.\n");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "highest_score") != NULL) {
            fprintf(temp, "highest_score=%d,\n", new_score);
        } else {
            fprintf(temp, "%s", line);
        }
    }

    fclose(file);
    fclose(temp);

    remove(filename);
    rename("temp.txt", filename);
}

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
