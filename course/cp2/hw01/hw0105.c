#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

#include "mytaiko.h"

#define COURSE_SIZE 5

int main() {
    Taiko taiko = {
        {
            {EASY,   NULL, 0},
            {NORMAL, NULL, 0},
            {HARD,   NULL, 0},
            {ONI,    NULL, 0},
            {EDIT,   NULL, 0},
        },
        0
    };

    for (int32_t i = 0; i < COURSE_SIZE; i++) {
        taiko.chart[i].course       = i;
        taiko.chart[i].measure      = NULL;
        taiko.chart[i].measure_size = 0;
    }

    taiko.offset = 0;

    if (readTjaFile(&taiko)) {
        writeTxtFile(&taiko);
    }

    for (size_t i = 0; i < COURSE_SIZE; i++) {
        if (taiko.chart[i].measure == NULL) {
            continue;
        }

        for (size_t j = 0; j < taiko.chart[i].measure_size; j++) {
            free(taiko.chart[i].measure[j].chart_content);
        }

        free(taiko.chart[i].measure);
    }

    return 0;
}
