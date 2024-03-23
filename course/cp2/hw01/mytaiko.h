#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

typedef enum _Course {
    EASY = 0,
    NORMAL,
    HARD,
    ONI,
    EDIT,
    UNSET = -1,
} Course;

typedef enum _TaikoNote { 
    BLANK = 0,
    DON,
    KA,
    BIGDON,
    BIGKA,
    DRUM_ROLL,
    BIG_DRUM_ROLL,
    BALLOON,
    END_SIGN,
    POTATO
} TaikoNote;

typedef enum _tjaKeyword {
    ERROR = -1,
    BPM = 1,
    OFFSET,
    COURSE,
    START,
    MEASURE,
    BPMCHANGE,
    END,
} TjaKeyword;

typedef struct _Measure {
    char *chart_content;
    double bpm;
    uint64_t beat;
    uint64_t note;
} Measure;

typedef struct _Chart {
    Course course;
    Measure *measure;
    uint64_t measure_size;
} Chart;

typedef struct _Taiko {
    Chart chart[5];
    double offset;
} Taiko;

/**
 * Read a TJA file and store the data in a Taiko struct.
 * @param taiko the taiko struct
 * @return true: read correctly, false: read error
 */
bool readTjaFile(Taiko *taiko);

/**
 * Write data from taiko to text file.
 * @param taiko the taiko struct
 */
void writeTxtFile(const Taiko *taiko);

/**
 * Read and determine the data.
 * @param data the given data.
 * @return -1: error input, 0: ignored; 1-7: corresponding keywords;
 */
int32_t readData(const char *data);

/**
 * Set current BPM.
 * @param data the given data string of BPM.
 * @param bpm the bpm to be be set.
 * @return true: bpm is corect, false: error input
 */
bool setBPM(const char *data, double *bpm);

/**
 * Set offset of the chart.
 * @param data the given data string of offset.
 * @param offset the offset to be set.
 * @return true: offset is corect, false: error input
 */
bool setOffset(const char *data, double *offset);

/**
 * Set the current course.
 * @param data the given data.
 * @param course the course to be set.
 * @return true: offset is corect, false: error input
 */
bool setCourse(const char *data, Course *course);

/**
 * Set the current measure.
 * @param data the given data.
 * @param beat the beat to be set.
 * @param note the note to be set.
 * @return true: beat and note is corect, false: error input
 */
bool setMeasure(const char *data, uint64_t *beat, uint64_t *note);

/**
 * Add current chart content into current course's chart.
 * @param data the given data.
 * @param taiko the taiko struct.
 * @param course the course to be added.
 * @param bpm current bpm of chart.
 * @param beat current beat of chart.
 * @param note current note of chart.
 * @return 2: error input, 1: data is correct, 0: error input
 */
int32_t addChartContent(const char *data, Taiko *taiko,
    Course course, double bpm, uint64_t beat, uint64_t note);

/**
 * Find gcd of two numbers.
 * @param a the number a.
 * @param b the number b.
 * @return the gcd of a and b
 */
uint64_t gcd(uint64_t a, uint64_t b);

/**
 * Process a new chart.
 * @param data the given chart content.
 * @param beat the beat of chart.
 * @param chart the content result.
 * @return true: chart is correct, 0: error input
 */
bool processNewChart(const char *data, uint64_t beat, char **chart);

/**
 * Check if the note should be printed.
 * @param ch the given note character.
 * @return true: should be printed, false: shouldn't be printed
 */
bool isPrintedNote(char ch);

/**
 * Print current measure.
 * @param mea the measure to be printed.
 * @param time the time elapsed.
 * @return true: measure is printed correctly, 0: error input
 */
bool printChart(const Measure *mea, double *time);
