#include <stdio.h>

int romanToInt(char *s) {

  int final_number;
  char next_car;

  final_number = 0;

  while (*s != '\0') {
    int skip = 1;
    next_car = *(s + 1);

    switch (*s) {
    case 'I':
      if (next_car == 'V') {
        final_number += 4;
        skip = 2;
      } else if (next_car == 'X') {
        final_number += 9;
        skip = 2;
      } else {
        final_number++;
      }
      break;
    case 'V':
      final_number += 5;
      break;
    case 'X':
      if (next_car == 'L') {
        final_number += 40;
        skip = 2;
      } else if (next_car == 'C') {
        final_number += 90;
        skip = 2;
      } else {
        final_number += 10;
      }
      break;
    case 'L':
      final_number += 50;
      break;
    case 'C':
      if (next_car == 'D') {
        final_number += 400;
        skip = 2;
      } else if (next_car == 'M') {
        final_number += 900;
        skip = 2;
      } else {
        final_number += 100;
      }
      break;
    case 'D':
      final_number += 500;
      break;
    case 'M':
      final_number += 1000;
      break;
    default:
      break;
    }
    s += skip;
  }

  return final_number;
}

int main(void) { printf("%d", romanToInt("MCMXCIV")); }
