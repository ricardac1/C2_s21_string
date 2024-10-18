#include "s21_string.h"

s21_size_t s21_strlen(const char *str) {
  s21_size_t len = 0;
  if (str != S21_NULL) {
    for (int i = 0; str[i] != '\0'; i++) {
      len++;
    }
  }
  return len;
}
