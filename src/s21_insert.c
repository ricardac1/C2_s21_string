#include "s21_string.h"

void *s21_insert(const char *dest, const char *src, size_t start_index) {
  char *res_str = S21_NULL;
  if (dest && src && start_index < s21_strlen(dest)) {
    size_t dest_len = s21_strlen(dest);
    size_t src_len = s21_strlen(src);
    size_t dest_src_len = dest_len + src_len;

    res_str = (char *)calloc(dest_src_len + 1, sizeof(char));
    if (res_str) {
      s21_strncpy(res_str, dest, start_index);
      s21_strcpy(res_str + start_index, src);
      s21_strcpy(res_str + start_index + src_len, dest + start_index);
    }
  }
  return res_str;
}