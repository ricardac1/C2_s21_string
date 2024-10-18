#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  char *result = S21_NULL;

  for (const char *dest1 = str1; *dest1; dest1++) {
    for (const char *dest2 = str2; *dest2; dest2++) {
      if (*dest1 == *dest2) {
        result = (char *)dest1;
        break;
      }
    }

    if (result) {
      break;
    }
  }

  return result;
}