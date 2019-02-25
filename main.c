#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include "transfer.h"

int main() {
  DIR *dir;
  struct dirent *ent;
  if ((dir = opendir(getSRC())) != NULL) {
    // print all the files and directories within directory
    while ((ent = readdir(dir)) != NULL) {
      filter(ent->d_name);
    }
    closedir (dir);
  } else {
    printf("ERROR: could not open directory: %s\n", getSRC());
    return 1;
  }

  return 0;
}
