
#include "s21_string.h"

int s21_sprintf(char *str, const char *format, ...) {
  char specifiers[] = "diuoxXcsnpfeEgG%";

  va_list arg;
  va_start(arg, format);
  char *str_start = str;

  while (*format) {
    if (*format == '%') {
      format++;
      Spec sp = {0};
      sp.accuracy = INTMAX;
      sp.number_system = 10;
      format = set_specs(format, &sp, &arg);
      if (s21_strchr(specifiers, *format) != S21_NULL) {
        sp.specifier = *format;
      }
      str = print_strings(str, str_start, &arg, &sp);
    } else {
      *str = *format;
      str++;
    }
    format++;
  }

  *str = '\0';
  va_end(arg);
  printf("%s", str);
  return str - str_start;
}

const char *set_specs(const char *format, Spec *sp, va_list *arg) {
  format = get_specs(format, sp);
  format = get_width(format, &sp->width, arg);
  if (*format == '.') {
    sp->dot = 1;
    format += 1;
    format = get_width(format, &sp->accuracy, arg);
  }
  format = get_length(format, sp);
  return format;
}

const char *get_length(const char *format, Spec *sp) {
  switch (*format) {
    case 'h':
      sp->length = 'h';
      format++;
      break;
    case 'l':
      sp->length = 'l';
      format++;
      break;
    case 'L':
      sp->length = 'L';
      format++;
  }
  return format;
}

const char *get_specs(const char *format, Spec *sp) {
  while (*format == '-' || *format == '+' || *format == ' ' || *format == '0' ||
         *format == '#') {
    switch (*format) {
      case '0':
        sp->zero = 1;
        break;
      case '-':
        sp->minus = 1;
        break;
      case '+':
        sp->plus = 1;
        break;
      case ' ':
        sp->space = 1;
        break;
      case '#':
        sp->hash = 1;
        break;
    }
    format++;
  }
  sp->space = (sp->space && !sp->plus);
  sp->zero = (sp->zero && !sp->minus);
  return format;
}

const char *get_width(const char *format, int *width, va_list *arg) {
  *width = 0;
  if (*format == '*') {
    format++;
    *width = va_arg(*arg, int);
  } else if ('0' <= *format && *format <= '9') {
    while ('0' <= *format && *format <= '9') {
      *width *= 10;
      *width += *format - '0';
      format++;
    }
  }
  return format;
}

char *print_strings(char *str, char *str_start, va_list *arg, Spec *sp) {
  if (sp->specifier == 'd' || sp->specifier == 'i') {
    str = add_int(str, sp, arg);
  } else if (sp->specifier == 'o' || sp->specifier == 'u' ||
             sp->specifier == 'X' || sp->specifier == 'x') {
    get_nuber_system(sp);
    str = print_u(str, sp, arg);
  } else if (sp->specifier == 'c') {
    int sym = va_arg(*arg, int);
    str = print_c(str, *sp, sym);
  } else if (sp->specifier == 's') {
    str = print_s(str, *sp, arg);
  } else if (sp->specifier == 'p') {
    str = print_p(str, sp, arg);
  } else if (sp->specifier == 'n') {
    int *n = va_arg(*arg, int *);
    *n = (int)(str - str_start);
  } else if (sp->specifier == '%') {
    str = print_c(str, *sp, '%');
  } else if (sp->specifier == 'f') {
    str = print_float(str, *sp, arg);
  } else if (sp->specifier == 'e' || sp->specifier == 'E' ||
             sp->specifier == 'g' || sp->specifier == 'G') {
    float_format(sp);
    str = print_float(str, *sp, arg);
  }
  return str;
}

char *print_p(char *str, Spec *sp, va_list *arg) {
  unsigned long int ptr = (unsigned long int)va_arg(*arg, unsigned long int);

  if (sp->accuracy == INTMAX) sp->accuracy = 1;
  sp->number_system = 16;
  sp->hash = 1;
  sp->upper_case = 0;
  sp->p = 1;

  s21_size_t size_num = get_size_num(sp, ptr);
  char *buff = malloc(sizeof(char) * size_num);
  if (buff) {
    int i = num_string(buff, *sp, ptr, size_num);
    for (int j = i - 1; j >= 0; j--) {
      *str = buff[j];
      str++;
    }
    while (i < sp->width) {
      *str = ' ';
      str++;
      i++;
    }
  }
  if (buff) free(buff);
  return str;
}

char *print_s(char *str, Spec sp, va_list *arg) {
  char *ptr = str;
  char *string = va_arg(*arg, char *);
  if (sp.accuracy == INTMAX) sp.accuracy = 0;

  if (string) {
    int tmp = sp.width, i = 0;
    if ((s21_size_t)sp.width < s21_strlen(string))
      sp.width = s21_strlen(string);

    int blank = sp.width - s21_strlen(string);

    if (sp.accuracy == 0) sp.accuracy = sp.width;

    if (sp.accuracy != 0 && sp.accuracy < tmp) blank = tmp - sp.accuracy;

    while (blank && !sp.minus) {
      *str = ' ';
      str++;
      blank--;
    }

    while (*string != '\0' && sp.accuracy != 0) {
      *str = *string;
      str++;
      string++;
      i++;
      sp.accuracy--;
    }

    while (blank && sp.minus) {
      *str = ' ';
      str++;
      blank--;
    }
  } else {
    str = s21_memcpy(str, "(null)", 6);
    str += 6;
  }

  if (ptr) ptr = str;
  return ptr;
}

char *print_c(char *str, Spec sp, int sym) {
  char *ptr = S21_NULL;
  int i = 0;
  if (sp.accuracy == INTMAX) sp.accuracy = 1;

  while (sp.width - 1 > 0 && !sp.minus) {
    *str = ' ';
    str++;
    i++;
    sp.width--;
  }
  if (sym <= 127) {
    *str = sym;
    str++;
    i++;
    while (sp.width - 1 > 0 && sp.minus) {
      *str = ' ';
      str++;
      i++;
      sp.width--;
    }
    ptr = str;
  }
  return ptr;
}

void get_nuber_system(Spec *sp) {
  if (sp->specifier == 'o')
    sp->number_system = 8;
  else if (sp->specifier == 'x' || sp->specifier == 'X')
    sp->number_system = 16;
  if (sp->specifier == 'X') sp->upper_case = 1;
}

char *print_u(char *str, Spec *sp, va_list *arg) {
  unsigned long int num = 0;

  if (sp->accuracy == INTMAX) sp->accuracy = 1;
  if (sp->length == 'l')
    num = (unsigned long int)va_arg(*arg, unsigned long int);
  else if (sp->length == 'h')
    num = (unsigned short)va_arg(*arg, unsigned int);
  else
    num = (unsigned int)va_arg(*arg, unsigned);

  s21_size_t size_num = get_size_num(sp, num);   // сделать
  char *buff = malloc(sizeof(char) * size_num);  // сделать
  if (buff) {
    int i = num_string(buff, *sp, num, size_num);  // сделать
    for (int j = i - 1; j >= 0; j--) {
      *str = buff[j];
      str++;
    }
    while (i < sp->width) {
      *str = ' ';
      str++;
      i++;
    }
  }
  if (buff) free(buff);
  return str;
}

s21_size_t get_size_num(Spec *sp, unsigned long int num) {
  s21_size_t res = 0;
  int sign = 0;

  if (sp->p != 1)
    sign = (sp->hash * (sp->number_system == 8)) +
           2 * (sp->hash * (sp->number_system == 16));
  if ((sp->hash && sp->number_system == 8) && num != 0)
    res++;
  else if (sp->hash && sp->number_system == 16 && (num != 0 || sp->p == 1)) {
    if (sp->p == 1 && num == 0)
      res += 3;
    else
      res += 2;
  }

  if (num > 0) {
    while (num > 0) {
      num /= sp->number_system;
      res++;
    }
  }
  if (num == 0 && res == 0 && (sp->accuracy || sp->width || sp->space)) {
    res++;
  }
  if ((s21_size_t)sp->width > res) res = sp->width;
  if ((s21_size_t)sp->accuracy > res) res = sp->accuracy + sign;

  if (sp->space && sp->plus) {
    sp->flag_to_size = 1;
    res++;
  }

  if (res == 0 && num == 0 && sp->accuracy == 0 && sp->width == 0 &&
      sp->space == 0 && sp->dot == 0)
    res++;

  return res;
}

int num_string(char *buff, Spec sp, unsigned long int num,
               s21_size_t size_num) {
  int i = 0, f = 0;
  unsigned long int copy_num = num;
  if (num)
    sp.flag_to_size = ((sp.hash && sp.number_system == 8) +
                       2 * (sp.hash && sp.number_system == 16));
  if ((copy_num == 0 && (sp.accuracy || sp.width || sp.space)) ||
      (copy_num == 0 && !sp.accuracy && !sp.width && !sp.space && !sp.dot)) {
    buff[i++] = copy_num % sp.number_system + '0';
    size_num--;
    copy_num /= 10;
  }
  while (copy_num && buff && size_num) {
    buff[i++] = conv_num_char(copy_num % sp.number_system, sp.upper_case);
    size_num--;
    copy_num /= sp.number_system;
  }
  if (sp.accuracy - i > 0) {
    sp.accuracy -= i;
    sp.zero = 1;
  } else
    f = 1;  //???
  if (size_num == 1 && sp.zero == 1 && sp.flag_to_size == 1) {
    sp.zero = 0;
  }
  while (sp.zero && buff && (size_num - sp.flag_to_size > 0) &&
         (sp.accuracy || f) &&
         !(size_num == 1 && sp.flag_to_size == 1 && sp.flag_to_size == 2)) {
    buff[i++] = '0';
    size_num--;
    sp.accuracy--;
  }
  if (sp.hash && sp.number_system == 8 && num != 0) {
    buff[i++] = '0';
    size_num--;
  } else if (sp.hash && sp.number_system == 16 && sp.upper_case &&
             (num != 0 || sp.p == 1)) {  // f==1
    buff[i++] = 'X';
    buff[i++] = '0';
    size_num -= 2;

  } else if (sp.hash && sp.number_system == 16 && sp.upper_case == 0 &&
             (num != 0 || sp.p == 1)) {  // f==1
    buff[i++] = 'x';
    buff[i++] = '0';
    size_num -= 2;
  }
  if (size_num > 0 && sp.minus == 0) {  //?
    while ((size_num > 0) && buff) {
      buff[i++] = ' ';
      size_num--;
    }
  }
  return i;
}

char *add_int(char *str, Spec *sp, va_list *arg) {
  long int num = 0;
  if (sp->accuracy == INTMAX) sp->accuracy = 1;
  if (sp->length == 'l') {
    num = (long int)va_arg(*arg, long int);
  } else if (sp->length == 'h') {
    num = (short)va_arg(*arg, int);
  } else {
    num = (int)va_arg(*arg, int);
  }
  s21_size_t size_int = get_size_int(sp, num);
  char *str_to_int = malloc(sizeof(char) * size_int);
  if (str_to_int) {
    int i = int_to_string(*sp, str_to_int, num, size_int);
    for (int j = i - 1; j >= 0; j--) {
      *str = str_to_int[j];
      str++;
    }
    while (i < sp->width) {
      *str = ' ';
      str++;
      i++;
    }
  }
  if (str_to_int) free(str_to_int);
  return str;
}

s21_size_t get_size_int(Spec *sp, long int num) {
  s21_size_t res = 0;
  int f = 0;
  if (num < 0) {
    f = 1;
    num = -num;
  }
  if (num > 0) {
    while (num > 0) {
      num /= 10;
      res++;
    }
  }
  if (num == 0 && res == 0 && (sp->accuracy != 0 || sp->width || sp->space)) {
    res++;
  }
  if ((s21_size_t)sp->width > res) res = sp->width;
  if ((s21_size_t)sp->accuracy > res) res = sp->accuracy;
  if (sp->space || sp->plus || f == 1) {
    sp->flag_to_size = 1;
    res++;
  }

  if (res == 0 && num == 0 && sp->accuracy == 0 && sp->width == 0 &&
      sp->space == 0 && sp->dot == 0)
    res++;
  return res;
}

int int_to_string(Spec sp, char *str_to_int, long int num,
                  s21_size_t size_int) {
  int f = 0;
  long int numcpy = num;
  if (numcpy < 0) {
    f = 1;
    numcpy = -numcpy;
  }

  int i = 0;
  if ((numcpy == 0 && (sp.accuracy || sp.width || sp.space)) ||
      (numcpy == 0 && !sp.accuracy && !sp.width && !sp.space && !sp.dot)) {
    char sym = numcpy % sp.number_system + '0';
    str_to_int[i] = sym;
    i++;
    size_int--;
    numcpy /= 10;
  }
  while (numcpy && str_to_int && size_int) {
    char sym = conv_num_char(numcpy % sp.number_system, sp.upper_case);
    str_to_int[i] = sym;
    i++;
    size_int--;
    numcpy /= 10;
  }

  if (sp.accuracy - i > 0) {
    sp.accuracy -= i;
    sp.zero = 1;
  } else
    f = 1;

  if (size_int == 1 && sp.zero == 1 && sp.flag_to_size == 1) {
    sp.zero = 0;
  }

  while (sp.zero && str_to_int && (size_int - sp.flag_to_size > 0) &&
         (sp.accuracy || f) && !(size_int == 1 && sp.flag_to_size == 1)) {
    str_to_int[i] = '0';
    i++;
    size_int--;
    sp.accuracy--;
  }

  if (sp.space && num >= 0 && size_int) {
    str_to_int[i] = ' ';
    i++;
    size_int--;
  }
  if (num < 0 && size_int) {  // f==1
    str_to_int[i] = '-';
    i++;
    size_int--;
  }
  if (num > 0 && sp.plus && size_int) {  // f==0
    str_to_int[i] = '+';
    i++;
    size_int--;
  }

  if (size_int > 0 && sp.minus == 0) {
    while ((size_int - sp.flag_to_size > 0) && str_to_int) {
      str_to_int[i] = ' ';
      i++;
      size_int--;
    }
  }
  return i;
}

char conv_num_char(int num, int upper_case) {
  char count = '0';
  switch (num) {
    case 10:
      count = (char)('a' - upper_case * 32);
      break;

    case 11:
      count = (char)('b' - upper_case * 32);
      break;

    case 12:
      count = (char)('c' - upper_case * 32);
      break;

    case 13:
      count = (char)('d' - upper_case * 32);
      break;

    case 14:
      count = (char)('e' - upper_case * 32);
      break;

    case 15:
      count = (char)('f' - upper_case * 32);
      break;
  }
  if (0 <= num && num <= 9) count = (char)(num + 48);
  return count;
}

void float_format(Spec *sp) {
  if (sp->specifier == 'g' || sp->specifier == 'G')
    sp->g_spec = 1;
  else if (sp->specifier == 'e' || sp->specifier == 'E')
    sp->e_spec = 1;
  if (sp->specifier == 'G' || sp->specifier == 'E') sp->upper_case = 1;
}

char *print_float(char *str, Spec sp, va_list *args) {
  long double num = 0.0;
  s21_size_t size = 0;
  int e = 0;
  if (sp.accuracy == INTMAX) sp.accuracy = 6;
  if (sp.length == 'L')
    num = va_arg(*args, long double);
  else
    num = va_arg(*args, double);
  if (sp.specifier == 'g' || sp.specifier == 'G')
    sp = normalize_precision(sp, num);
  if (sp.e_spec) e = normalize_e(&num);

  int check_space_plus_min = (sp.plus || sp.space || (num < 0));
  size = get_buf_size_double(sp.width, sp.accuracy, num, check_space_plus_min);
  char *buffer = malloc(size);
  if (buffer) {
    s21_memset(buffer, 0, size);  // Инициализируем буфер
    int numberOfCharacters = (int)(float_to_string(buffer, sp, num, size));
    for (int j = numberOfCharacters - 1; j >= 0; j--, str++) *str = buffer[j];
    if (sp.e_spec) {
      *(str++) = (char)('e' - sp.upper_case * 32);
      *(str++) = (char)('-' * (e < 0) + '+' * (e >= 0));
      *(str++) = (char)(abs(e / 10) + '0');
      *(str++) = (char)(abs(e % 10) + '0');
    }
    for (; numberOfCharacters + 4 * sp.e_spec < sp.width;
         numberOfCharacters++, str++)
      *str = ' ';
  }
  if (buffer) free(buffer);
  return str;
}

Spec normalize_precision(Spec sp, long double num) {
  int e = normalize_e(&num);
  if (!sp.accuracy) sp.accuracy = 1;
  if (-4 <= e && e < sp.accuracy) {
    sp.accuracy = sp.accuracy - e - 1;
  } else {
    sp.e_spec = 1;
    sp.accuracy -= 1;
  }
  return sp;
}

int normalize_e(long double *num) {
  int e = 0;
  if (*num) {
    if (fabsl(*num) < 1.0) {
      for (; fabsl(*num) < 1.0; *num = *num * 10, e--) {
      }
    } else if (fabsl(*num) >= 10.0) {
      for (; fabsl(*num) >= 10.0; *num = *num / 10, e++) {
      }
    }
  }
  return e;
}

s21_size_t get_buf_size_double(int width, int accuracy, long double num,
                               int space) {
  s21_size_t num_of_char = 1 + (accuracy > 0);
  while (fabsl(num) - 1.0 >= 0 && isfinite(num)) {
    num /= 10.0;
    num_of_char++;
  }
  num_of_char += accuracy + space;
  if (!isfinite(num)) num_of_char = 5;
  return ((s21_size_t)width > num_of_char) ? (s21_size_t)width : num_of_char;
}

s21_size_t float_to_string(char *buffer, Spec sp, long double num,
                           s21_size_t bufferSize) {
  s21_size_t res = 0;
  res = (s21_size_t)(check_nan(buffer, num, sp.upper_case));
  if (!res) {
    long double integralPart = 0.0, fractionalPart = 0.0;
    fractionalPart = modfl(num, &integralPart);
    fractionalPart = roundl(fabsl(fractionalPart) * powl(10.0l, sp.accuracy));
    if (sp.g_spec && !sp.hash) {
      for (; (int)fractionalPart % 10 == 0 && fractionalPart > 0;
           fractionalPart /= 10.0l, sp.accuracy--) {
      }
    }
    if (sp.g_spec && !fractionalPart) sp.accuracy = 0;
    // проверяем точность и записываем дробную а затем и целую часть
    if (sp.accuracy) {
      for (; res < bufferSize && res < (s21_size_t)sp.accuracy;
           res++, fractionalPart /= 10.0l)
        buffer[res] =
            (char)((fractionalPart - floorl(fractionalPart / 10.0l) * 10.0l) +
                   '0');
      buffer[res++] = '.';
    }
    for (integralPart =
             roundl(fabsl(integralPart) + fractionalPart * (sp.accuracy == 0));
         res < bufferSize && integralPart >= 10.0l;
         res++, integralPart /= 10.0l)
      buffer[res] =
          (char)((integralPart - floorl(integralPart / 10.0l) * 10.0l) + '0');
    buffer[res++] = (char)(integralPart + '0');
    for (; res + (sp.plus || sp.space || num < 0) + 4 * sp.e_spec <
               (s21_size_t)sp.width &&
           sp.zero;
         res++)
      buffer[res] = '0';
    if (sp.space && num >= 0) buffer[res++] = ' ';
    if (num < 0) buffer[res++] = '-';
    if (sp.plus && num > 0) buffer[res++] = '+';
    for (; res + 4 * sp.e_spec < (s21_size_t)sp.width && !sp.minus; res++)
      buffer[res] = ' ';
  }
  return res;
}

s21_size_t check_nan(char *buffer, long double varWithLength, int upper) {
  int flag = 0;
  int len = s21_strlen(buffer);
  if (isnan(varWithLength)) {
    if (upper) {
      s21_strncpy(buffer, "NAN", len);
    } else {
      s21_strncpy(buffer, "nan", len);
    }
    flag = 3;
  } else if (varWithLength == INFINITY) {
    if (upper) {
      s21_strncpy(buffer, "INF", len);
    } else {
      s21_strncpy(buffer, "inf", len);
    }
    flag = 3;
  } else if (varWithLength == -INFINITY) {
    if (upper) {
      s21_strncpy(buffer, "INF-", len);
    } else {
      s21_strncpy(buffer, "inf-", len);
    }
    flag = 4;
  }
  return flag;
}