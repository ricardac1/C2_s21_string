#include "s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t k) {
  int res = 0;
  if (str1 && str2 && k > 0) {
    for (s21_size_t i = 0; i < k; i++) {
      if (str1[i] == '\0' || str1[i] != str2[i]) {
        res = str1[i] - str2[i];
        break;
      }
    }
  }
  return res;
}