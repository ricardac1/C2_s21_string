#include "s21_string.h"

void *s21_memcpy(void *dest, const void *source, s21_size_t count) {
  unsigned char *dest0 = (unsigned char *)dest;
  unsigned char *source0 = (unsigned char *)source;

  for (s21_size_t i = 0; i <= count; i++) {
    dest0[i] = source0[i];
  }
  return dest;
}