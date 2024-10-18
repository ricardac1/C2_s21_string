#include "s21_string.h"

int s21_memcmp(const void *ptr1, const void *ptr2, size_t n) {
  unsigned char *pt1 = (unsigned char *)ptr1;
  unsigned char *pt2 = (unsigned char *)ptr2;
  int res = 0;
  for (s21_size_t i = 0; i < n; i++) {
    res = *pt1 - *pt2;
    if (*pt1 != *pt2) {
      break;
    }
    pt1++;
    pt2++;
  }
  return res;
}