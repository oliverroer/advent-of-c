#include <stdbool.h>
#include <stdio.h>
#include <windows.h>
#include "day01.c"

void printAnswers(int day, int answer1, int answer2) {
  printf("day %d:\n", day);
  printf("  problem 1: %d\n", answer1);
  printf("  problem 2: %d\n", answer2);
}

int main(int argc, char **argv) {
  int answer1 = day01problem1();
  int answer2 = day01problem2();
  printAnswers(1, answer1, answer2);

  return (0);
}
