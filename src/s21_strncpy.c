#include "s21_string.h"

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  s21_size_t cnt = 0;
  while (cnt < n && src[cnt] && src && dest) {
    dest[cnt] = src[cnt];
    cnt++;
  }
  while (cnt < n && src && dest) {
    dest[cnt] = '\0';
    cnt++;
  }
  return dest;
}
