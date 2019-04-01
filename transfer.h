#ifndef TRANSFER_HEADER
#define TRANSFER_HEADER

typedef struct {
    char *name;
    char *path;
} course_t;

char* getSRC();
void filter(char* filename);
void move(char *src, char *dest);

#endif
