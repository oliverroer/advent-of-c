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

bool readNumber(FILE *file, int *number) {
  char sign;
  int value;
  int scanned = fscanf(file, "%c%d\n", &sign, &value);

  if (scanned != 2) {
    return false;
  }

  *number = sign == '+' ? value : -value;
  return true;
}

int day01problem1() {
  FILE *file = openFile(1, "input.txt");
  if (!file) {
    return;
  }

  int number;
  int sum = 0;

  while (readNumber(file, &number)) {
    sum += number;
  }

  return sum;
}

enum {
  POSITIVE = 1 << 0,
  NEGATIVE = 1 << 1
};

int day01problem2() {
  FILE *file = openFile(1, "input.txt");
  if (!file) {
    return;
  }

  int sum = 0;

  int frequencyCount = sum + 1;
  char *frequencies = (char *)malloc(sizeof(char) * frequencyCount);

  frequencies[sum] = POSITIVE | NEGATIVE;

  while (true) {
    int number;
    int success = readNumber(file, &number);
    if (!success) {
      rewind(file);
      continue;
    }

    sum += number;

    int value = sum >= 0 ? sum : -sum;
    int sign = sum >= 0 ? POSITIVE : NEGATIVE;

    if (value >= frequencyCount) {
      // value is outside the range
      int oldfreqc = frequencyCount;
      frequencyCount = value + 1;
      // increase range
      frequencies = (char *)realloc(frequencies, sizeof(char) * frequencyCount);
      // zero out new values
      memset(frequencies + oldfreqc, 0, sizeof(char) * (frequencyCount-oldfreqc));
      // assign value and continue
      frequencies[value] = sign;
      continue;
    }

    int previousSign = frequencies[value];
    if (previousSign & sign) {
      break;
    } else {
      frequencies[value] = previousSign | sign;
    }
  }

  return sum;
}
