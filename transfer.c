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
  // new string that does not contain the file type (.txt, .doc, etc)
  char shortened[strlen(filename) * sizeof(char)];
  strcpy(shortened, filename);
  *strstr(shortened, ".") = 0;

  // new string for the suffix in the filename
  char *suffix = strchr(shortened, '-');

  // determines if the suffix is valid and where to transfer the file
  if (suffix == NULL) {
    if (strcmp(filename, ".") != 0 && strcmp(filename, ".."))
      printf("UNKNOWN: %s\n", filename);
  } else if (strcmp(suffix, C1) == 0) {
    printf("%s\n", C1);
    move(filename, C1_DIR);
  } else if (strcmp(suffix, C2) == 0) {
    printf("%s\n", C2);
    move(filename, C2_DIR);
  } else if (strcmp(suffix, C3) == 0) {
    printf("%s\n", C3);
    move(filename, C3_DIR);
  } else if (strcmp(suffix, C4) == 0) {
    printf("%s\n", C4);
    move(filename, C4_DIR);
  } else if (strcmp(suffix, C5) == 0) {
    printf("%s\n", C5);
    move(filename, C5_DIR);
  } else {
    printf("UNKNOWN: %s\n", filename);
  }
}

// moves the file to the designated location
void move(char *src, char *dest) {
  char srccpy[strlen(src) * sizeof(char)];
  strcpy(srccpy, src);

  //source location - size increase by 100 as a buffer. need to fix
  char dirsrc[(strlen(src) * sizeof(char)) + (strlen(SRC_PATH) * sizeof(char)) + 100];
  strcpy(dirsrc, SRC_PATH);
  strcat(dirsrc, src);
  FILE *f1 = fopen(dirsrc, "r");

  //destination
  char dirdest[(strlen(srccpy) * sizeof(char)) + (strlen(dest) * sizeof(char)) + 100];
  strcpy(dirdest, dest);
  strcat(dirdest, src);
  FILE *f2 = fopen(dirdest, "w");

  printf("Source: %s\n", dirsrc);
  printf("Dest: %s\n", dirdest);

  if (!f1) {
    printf("ERROR: file does not exist [%s]\n", dirsrc);
  }
  if (!f2) {
    printf("ERROR: file cannot be written [%s]\n", dirdest);
  }

  //copying over information
  int i;
  while((i = fgetc(f1)) != EOF) {
    fputc(i, f2);
  }

  //closing file objects and removing the source file
  fclose(f1);
  fclose(f2);
  printf("%s\n", dirsrc);
  if(remove(dirsrc) == -1) {
    printf("File failed to be removed: %s\n", dirsrc);
  }
}
