#include "mytaiko.h"

#define SIZE 512

#define TOTAL_TJA_KEYWORD 7
#define TOTAL_TJA_COURSE  5

const char *TJA_COURSE_WORD[] = {
    "Easy", "Normal", "Hard", "Oni", "Edit",
};

const char *TJA_COURSE_NUM[] = {
    "0", "1", "2", "3", "4",
};

const char *TJA_KEYWORD[] = {
    "BPM:",
    "OFFSET:",
    "COURSE:",
    "#START",
    "#MEASURE",
    "#BPMCHANGE",
    "#END"
};

bool readTjaFile(Taiko *taiko) {
    double currBpm    = 0;
    double defaultBpm = 0;
    Course currCourse = UNSET;
    uint64_t currBeat = 4;
    uint64_t currNote = 4;

    bool inCourse = false;

    char data[SIZE] = {0};
 
    while (fgets(data, SIZE, stdin) != NULL) {
        TjaKeyword type = readData(data);

        if (type == -1) {
            return false;
        }

        if (type == BPM || type == BPMCHANGE) {
            if (!setBPM(data, &currBpm)) {
                return false;
            }

            if (type == BPM) {
                defaultBpm = currBpm;
            }
        } else if (type == OFFSET) {
            if (!setOffset(data, &(taiko->offset))) {
                return false;
            }
        } else if (type == COURSE) {
            if (!setCourse(data, &currCourse)) {
                return false;
            }
        } else if (type == MEASURE) {
            if (!setMeasure(data, &currBeat, &currNote)) {
                return false;
            }
        } else if (type == START) {
            inCourse = true;
        } else if (inCourse) {
            if (type == END) {
                inCourse = false;

                currBpm    = defaultBpm;
                currCourse = UNSET;
                currBeat   = 4;
                currNote   = 4;

                continue;
            }

            if (!addChartContent(data, taiko, currCourse, currBpm, currBeat, currNote)) {
                return false;
            }
        }
    }

    return true;
}

void writeTxtFile(const Taiko *taiko) {
    bool print = false;
    double time = 0;

    for (uint64_t i = TOTAL_TJA_COURSE; i > 0; i--) {
        if (taiko->chart[i-1].measure_size == 0) {
            continue;
        }

        if (print == true) {
            printf("\n");
        }

        printf("course: %ld\n", i-1);

        time = -taiko->offset;

        for (uint64_t j = 0; j < taiko->chart[i-1].measure_size; j++) {
            if (!printChart(&(taiko->chart[i-1].measure[j]), &time)) {
                return;
            }
        }

        print = true;
    }
}

TjaKeyword readData(const char *data) {
    if (data == NULL) {
        return -1;
    }

    for (int32_t i = 0; i < TOTAL_TJA_KEYWORD; i++) {
        if (strstr(data, TJA_KEYWORD[i])) {
            return i + 1;
        }
    }

    return 0;
}

bool setBPM(const char *data, double *bpm) {
    if (data == NULL) {
        return false;
    }

    char *str = strpbrk(data, "1234567890");

    if (str == NULL) {
        return false;
    }

    sscanf(str, "%lf", bpm);

    return true;
}

bool setOffset(const char *data, double *offset) {
    if (data == NULL) {
        return false;
    }

    char *str = strpbrk(data, "-1234567890");

    if (str == NULL) {
        return false;
    }

    sscanf(str, "%lf", offset);

    return true;
}

bool setCourse(const char *data, Course *course) {
    if (data == NULL) {
        return false;
    }

    Course temp = UNSET;

    for (int i = 0; i < TOTAL_TJA_COURSE; i++) {
        if (strstr(data, TJA_COURSE_WORD[i]) || strstr(data, TJA_COURSE_NUM[i])) {
            temp = i;
            break;
        }
    }

    if (temp == UNSET) {
        return false;
    }

    *course = temp;

    return true;
}

bool setMeasure(const char *data, uint64_t *beat, uint64_t *note) {
    if (data == NULL) {
        return false;
    }

    uint64_t tmpBeat = 0, tmpNote = 0;

    sscanf(data, "#MEASURE %lu/%lu", &tmpBeat, &tmpNote);

    if (!tmpBeat || !tmpNote) {
        return false;
    }

    *beat = tmpBeat;
    *note = tmpNote;

    return true;
}

int32_t addChartContent(const char *data, Taiko *taiko,
    Course course, double bpm, uint64_t beat, uint64_t note) {

    if (course == UNSET) {
        return 0;
    }

    if (strchr(data, ',') == NULL) {
        return 2;
    }

    // Allocate new memory

    Chart *chart = &(taiko->chart[course]);

    if (chart->measure == NULL) {
        chart->measure_size = 1;
        chart->measure = calloc(1, sizeof(Measure));
    } else {
        chart->measure_size++;
        chart->measure = reallocarray(
            chart->measure, chart->measure_size, sizeof(Measure)
        );
    }

    // Add data to current chart

    uint64_t pos = chart->measure_size - 1;

    char *tmp = NULL;
    if (!processNewChart(data, beat, &tmp)) {
        return 0;
    }

    chart->measure[pos].chart_content = tmp;
    chart->measure[pos].bpm  = bpm;
    chart->measure[pos].beat = beat;
    chart->measure[pos].note = note;

    return 1;
}

uint64_t gcd(uint64_t a, uint64_t b) {
    if (b == 0) {
        return a;
    }

    uint64_t r = a % b;

    return gcd(b, r);
}

bool processNewChart(const char *data, uint64_t beat, char **chart) {
    uint64_t chartLength = strspn(data, "1234567890");
    uint64_t totalLength = 0;

    if (chartLength == 0) {
        totalLength = beat;
    } else if (chartLength < beat) {
        totalLength = chartLength * beat / gcd(chartLength, beat);
    } else {
        totalLength = chartLength;
    }

    uint64_t ratio = 0;

    if (chartLength == 0) {
        ratio = totalLength;
    } else {
        ratio = totalLength / chartLength;
    }

    *chart = calloc(totalLength + 1, sizeof(char));

    uint64_t j = 0;
    for (uint64_t i = 0; i < totalLength; i++) {
        if (i % ratio == 0 && j < chartLength) {
            (*chart)[i] = data[j];
            j++;
        } else {
            (*chart)[i] = '0';
        }
    }

    (*chart)[totalLength] = '\0';

    return true;
}

bool isPrintedNote(char ch) {
    TaikoNote note = ch - '0';

    return ((note == DON) || (note == BIGDON) || (note == KA)  || (note == BIGKA));
}

bool printChart(const Measure *mea, double *time) {
    size_t len = strlen(mea->chart_content);
    double dur = (double) (240.0 * mea->beat) / (mea->bpm * mea->note * len);

    for (size_t i = 0; i < len; i++) {
        if (isPrintedNote(mea->chart_content[i])) {
            printf("[%c, %f]\n", mea->chart_content[i], *time);
        }

        *time += dur;
    }

    return true;
}
