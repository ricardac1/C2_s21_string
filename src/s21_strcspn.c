#include "s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  const char *ptr1, *ptr2;

  int len;
  int flag = 0;

  for (ptr1 = str1; *ptr1 != '\0'; ptr1++) {
    for (ptr2 = str2; *ptr2 != '\0'; ptr2++) {
      if (*ptr1 == *ptr2 && flag != 1) {
        len = ptr1 - str1;
        flag = 1;
      }
    }
  }
  return (flag == 1) ? len : ptr1 - str1;
}