#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "transfer.h"
#include "mydirectories.h"

char* getSRC() {
  return SRC_PATH;
}

// determines which folder to put the file in
void filter(char* filename) {
  // filter for current and previous directory and the do not delete file
  if (strcmp(filename, ".") == 0 || strcmp(filename, "..") == 0 ||
      strcmp(filename, "donot.delete") == 0) {
    return;
  }

  size_t base_len = strlen(filename) + 1;
  char file[base_len];
  strcpy(file, filename);

  char *extension = strrchr(file, '.');
  if (!extension) return;
  size_t ext_len = strlen(extension);
  *extension = 0;
  extension += 1;

  char *suffix = strrchr(file, '-');
  if (!suffix) return;
  size_t suffix_len = strlen(suffix);
  *suffix = 0;
  suffix += 1;

  char *dest = NULL;

  if (suffix == NULL) {
    if (strcmp(filename, ".") != 0 && strcmp(filename, "..") != 0) {
      printf("UNKNOWN %s\n", filename);
    }
    return;
  }

  for (size_t i = 0; i < num_courses; i++) {
    course_t course = courses[i];
    if (strcmp(suffix, course.name) == 0) {
      printf("%s\n", course.name);
      dest = course.path;
      break;
    }
  }

  if (dest == NULL) {
    printf("Directory not specified for file: %s\n", filename);
    printf("Suffix: %s\nExt:    %s\n", suffix, extension);
    return;
  }

  size_t new_name_len = base_len - suffix_len;
  char *nfname = malloc(new_name_len);
  snprintf(nfname, new_name_len, "%s.%s", file, extension);

  // new string = source path + filename
  size_t src_len = base_len + (strlen(SRC_PATH) * sizeof(char));
  char *dirsrc = malloc(src_len);
  snprintf(dirsrc, src_len, "%s%s", SRC_PATH, filename);

  // new string = destination source + new filename (w/o suffix)
  size_t dest_len = new_name_len + (strlen(dest) * sizeof(char));
  char *dirdest = malloc(dest_len);
  snprintf(dirdest, dest_len, "%s%s", dest, nfname);

  free(nfname);

  move(dirsrc, dirdest);

  free(dirdest);
  free(dirsrc);
}

// moves the file to the designated location
void move(char *src, char *dest) {

  //source location - size increase by 100 as a buffer. need to fix
  FILE *f1 = fopen(src, "r");

  //destination
  FILE *f2 = fopen(dest, "w");

  // print the expected source/destination
  printf("Source: %s\n", src);
  printf("Dest: %s\n", dest);

  // checks if the opened files actually exist
  if (!f1) {
    printf("ERROR: file does not exist [%s]\n", src);
  }
  if (!f2) {
    printf("ERROR: file cannot be written [%s]\n", dest);
  }

  // copying over information
  // this is probably the most important code
  int i;
  while((i = fgetc(f1)) != EOF) {
    fputc(i, f2);
  }

  // closing file objects and removing the source file
  fclose(f1);
  fclose(f2);

  if(remove(src) == -1) {
    printf("File failed to be removed: %s\n", src);
  }
}
