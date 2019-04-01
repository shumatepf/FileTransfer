#ifndef CONSTANT_FILE
#define CONSTANT_FILE

#include "transfer.h"

#define BASE_DIR "/home/peter/school/spr19/"

char *SRC_PATH = "/home/peter/Documents/FileTransfer/SRC/";

const course_t cs430 = {
    .name = "CS430",
    .path = BASE_DIR "cs430"
};

const course_t cs482 = {
    .name = "CS482",
    .path = BASE_DIR "cs482"
};

const course_t geol110 = {
    .name = "GEOL110",
    .path = BASE_DIR "geol110"
};

const course_t eng221 = {
    .name = "ENG221",
    .path = BASE_DIR "eng221"
};

const course_t test = {
    .name = "TEST",
    .path = "/home/peter/school/test"
};

course_t courses[] = {
    cs430,
    cs482,
    geol110,
    eng221,
    test
};
size_t num_courses = 5;

#endif
