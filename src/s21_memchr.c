#include "s21_string.h"

void *s21_memchr(const void *dest, int c, s21_size_t count) {
  const unsigned char *char_ptr;
  char_ptr = (const unsigned char *)dest;
  int flag = 0;

  while (count-- && !flag) {
    if (*char_ptr == (unsigned char)c) {
      flag = 1;
      break;
    }
    char_ptr++;
  }

  return flag ? (void *)char_ptr : S21_NULL;
}
