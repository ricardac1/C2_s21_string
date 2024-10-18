#include "s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  char *res_str = S21_NULL;
  if (!trim_chars || s21_strlen(trim_chars) == 0) {
    trim_chars = "\f\n\v\t\r ";
  }
  if (src && trim_chars) {
    char *first_str = (char *)src;
    char *last_str = (char *)src + s21_strlen(src);
    for (; *first_str && s21_strchr(trim_chars, *first_str); first_str++) {
    }
    for (; last_str != first_str && s21_strchr(trim_chars, *(last_str - 1));
         last_str--) {
    }
    res_str = (char *)calloc((last_str - first_str + 1), sizeof(char));
    if (res_str) {
      s21_strncpy(res_str, first_str, last_str - first_str);
      *(res_str + (last_str - first_str)) = '\0';
    }
  }
  return res_str;
}