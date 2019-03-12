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

  // new string that does not contain the file type (.txt, .doc, etc)
  char noext[strlen(filename) * sizeof(char)];
  strcpy(noext, filename);
  *strstr(noext, ".") = 0;

  // new string for the suffix in the filename
  char *suffix = strchr(noext, '-');

  // new string with no suffix
  char nosuff[strlen(filename) * sizeof(char)];
  strcpy(nosuff, filename);

  // removing suffix from string
  char *p = strchr(nosuff, '-');
  if (!p)
    return;
  *p = 0;

  // extension
  char *ext = strrchr(filename, '.');

  // new string = filename (w/o suffix) + extension
  char nfname[strlen(nosuff) * sizeof(char) + strlen(ext) * sizeof(char)];
  strcpy(nfname, nosuff);
  strcat(nfname, ext);

  char *dest;

  // determines if the suffix is valid and where to transfer the file
  if (suffix == NULL) {
    if (strcmp(filename, ".") != 0 && strcmp(filename, "..")) {
      printf("UNKNOWN %s\n", filename);
    }
    return;
  } else if (strcmp(suffix, C1) == 0) {
    printf("%s\n", C1);
    dest = C1_DIR;
  } else if (strcmp(suffix, C2) == 0) {
    printf("%s\n", C2);
    dest = C2_DIR;
  } else if (strcmp(suffix, C3) == 0) {
    printf("%s\n", C3);
    dest = C3_DIR;
  } else if (strcmp(suffix, C4) == 0) {
    printf("%s\n", C4);
    dest = C4_DIR;
  } else if (strcmp(suffix, C5) == 0) {
    printf("%s\n", C5);
    dest = C5_DIR;
  } else {
    printf("Directory not specified for file: %s\n", filename);
    return;
  }

  // new string = source path + filename
  char dirsrc[(strlen(filename) * sizeof(char)) + (strlen(SRC_PATH) * sizeof(char)) + 100];
  strcpy(dirsrc, SRC_PATH);
  strcat(dirsrc, filename);

  // new string = destination source + new filename (w/o suffix)
  char dirdest[(strlen(nfname) * sizeof(char)) + (strlen(dest) * sizeof(char)) + 100];
  strcpy(dirdest, dest);
  strcat(dirdest, nfname);
  move(dirsrc, dirdest);
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
