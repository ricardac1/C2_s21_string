#include "s21_string.h"

char* s21_strtok(char* str, const char* delim) {
  static char* mem = S21_NULL;

  if (str) mem = str;

  if (mem) {
    str = mem + s21_strspn(mem, delim);
    mem = str + s21_strcspn(str, delim);
    if (*mem != '\0') {
      *mem = '\0';
      ++mem;
    }
  }

  return *str != '\0' ? str : S21_NULL;
}

s21_size_t s21_strspn(const char* str1, const char* str2) {
  s21_size_t count = 0;
  const char *ptr1, *ptr2;

  for (ptr1 = str1; *ptr1 != '\0'; ptr1++) {
    int flag = 0;
    for (ptr2 = str2; *ptr2 != '\0'; ptr2++) {
      if (*ptr1 == *ptr2) {
        count++;
        flag = 1;
        break;
      }
    }
    if (!flag) break;
  }

  return count;
}