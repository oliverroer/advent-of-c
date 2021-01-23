#include <stdbool.h>
#include <stdio.h>
#include <windows.h>

FILE *openFile(int day, char *name) {
  char path[128];
  int written = sprintf(path, "../data/day%02d/%s", day, name);
  if (written == -1) {
    return NULL;
  }
  FILE *file = fopen(path, "r");
  return file;
}

int hash(char *str, int modulo) {
    int result = 0;
    int coefficient = 127;
    for (; *str != '\0', str++) {
        result = (coefficient * result + *str) % modulo;
    }
    return result;
}

int hashU(char *str, int modulo) {
  int result = 0;
  int coefficient = 31415;
  int b = 27183;
  for (; *str != '\0'; str++) {
    result = (coefficient * result + *str) % modulo;
    coefficient = coefficient * b % (modulo - 1);
  }
  return result;
}