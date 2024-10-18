#include "s21_string.h"

void *s21_memmove(void *dest, const void *source, s21_size_t count) {
  char *dest0 = (char *)dest;
  char *source0 = (char *)source;

  if (dest0 - source0 >= (long int)count) {
    dest = s21_memcpy(dest, source, count);
  } else {
    dest0 += count - 1;
    source0 += count - 1;
    while (count--) *dest0-- = *source0--;
  }
  return dest;
}