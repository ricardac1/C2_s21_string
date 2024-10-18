#ifndef S21_STRING_H
#define S21_STRING_H

#include <locale.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

typedef long unsigned int s21_size_t;
typedef long unsigned s21_size_t;
#define S21_NULL ((void *)0)
#define BUFF_SIZE 512

void *s21_memchr(const void *dest, int c, s21_size_t count);
int s21_memcmp(const void *ptr1, const void *ptr2, s21_size_t n);
void *s21_memcpy(void *dest, const void *source, s21_size_t count);
void *s21_memmove(void *dest, const void *source, s21_size_t count);
void *s21_memset(void *dest, int c, s21_size_t count);
char *s21_strcat(char *dest, const char *src);
char *s21_strchr(const char *str, int c);
int s21_strcmp(const char *str1, const char *str2);
char *s21_strcpy(char *dest, const char *src);
s21_size_t s21_strcspn(const char *str1, const char *str2);
s21_size_t s21_strlen(const char *str);
s21_size_t s21_strspn(const char *str1, const char *str2);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
int s21_strncmp(const char *str1, const char *str2, s21_size_t k);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strerror(int errnum);
char *s21_strtok(char *str, const char *delim);

int s21_sprintf(char *str, const char *format, ...);

// C#
void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *dest, const char *src, size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);

// spritnf
#define INTMAX -1

typedef struct {
  int minus;
  int plus;
  int space;
  int hash;
  int zero;
  int width;
  int accuracy;
  char length;
  char specifier;
  int number_system;
  int flag_to_size;
  int dot;
  int upper_case;
  int p;
  int e_spec;
  int g_spec;
} Spec;

int s21_sprintf(char *str, const char *format, ...);
const char *set_specs(const char *format, Spec *sp, va_list *arg);
const char *get_length(const char *format, Spec *sp);
const char *get_specs(const char *format, Spec *sp);
const char *get_width(const char *format, int *width, va_list *arg);
char *print_strings(char *str, char *str_start, va_list *arg, Spec *sp);
char *add_int(char *str, Spec *sp, va_list *arg);
s21_size_t get_size_int(Spec *sp, long int num);
int int_to_string(Spec sp, char *str_to_int, long int num, s21_size_t size_int);
char conv_num_char(int num, int upper_case);
void get_nuber_system(Spec *sp);
char *print_c(char *str, Spec sp, int sym);
char *print_u(char *str, Spec *sp, va_list *arg);
char *print_s(char *str, Spec sp, va_list *arg);
char *print_p(char *str, Spec *sp, va_list *arg);
s21_size_t get_size_num(Spec *sp, unsigned long int num);
int num_string(char *buff, Spec sp, unsigned long int num, s21_size_t size_num);

void float_format(Spec *sp);
char *print_float(char *str, Spec sp, va_list *args);
Spec normalize_precision(Spec sp, long double num);
int normalize_e(long double *num);
s21_size_t get_buf_size_double(int width, int accuracy, long double num,
                               int space);
s21_size_t float_to_string(char *buffer, Spec sp, long double num,
                           s21_size_t bufferSize);
s21_size_t check_nan(char *buffer, long double varWithLength, int upper);

#endif