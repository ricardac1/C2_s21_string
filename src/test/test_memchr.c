#include "s21_string_test.h"

START_TEST(empty_str) {
  s21_size_t byte = 0;
  char dest[15] = "";
  int sym = '\0';

  ck_assert_ptr_eq(s21_memchr(dest, sym, byte), memchr(dest, sym, byte));
}
END_TEST

START_TEST(end_str) {
  s21_size_t byte = 7;
  char dest[15] = "sfasdf";
  int sym = '\0';

  ck_assert_ptr_eq(s21_memchr(dest, sym, byte), memchr(dest, sym, byte));
}
END_TEST

START_TEST(find_double_reg) {
  s21_size_t byte = 6;
  char dest[15] = "AdsfAb";
  int sym = 'A';

  ck_assert_ptr_eq(s21_memchr(dest, sym, byte), memchr(dest, sym, byte));
}
END_TEST

START_TEST(find_reg) {
  s21_size_t byte = 0;
  char dest[15] = "Adsfab";
  int sym = 'A';

  ck_assert_ptr_eq(s21_memchr(dest, sym, byte), memchr(dest, sym, byte));
}
END_TEST

START_TEST(find_num) {
  s21_size_t byte = 0;
  char dest[15] = "string123";
  int sym = '2';

  ck_assert_ptr_eq(s21_memchr(dest, sym, byte), memchr(dest, sym, byte));
}
END_TEST

START_TEST(find_num_in_array_num) {
  int array[] = {1, 2, 3, 666, 5, 99, 100};
  s21_size_t byte = sizeof(int) * 7;
  int sym = 666;

  ck_assert_ptr_eq(s21_memchr(array, sym, byte), memchr(array, sym, byte));
}
END_TEST

START_TEST(find_float_in_array) {
  float array[] = {1, 2, 3, 666, 5, 99, 100};
  s21_size_t byte = sizeof(float) * 7;
  int sym = 666;

  ck_assert_ptr_eq(s21_memchr(array, sym, byte), memchr(array, sym, byte));
}
END_TEST

START_TEST(double_sym) {
  s21_size_t byte = 8;
  char dest[15] = "adkfdsa";
  int sym = 'a';

  ck_assert_ptr_eq(s21_memchr(dest, sym, byte), memchr(dest, sym, byte));
}
END_TEST

START_TEST(none_sym) {
  s21_size_t byte = 6;
  char dest[15] = "adada";
  int sym = 'c';

  ck_assert_ptr_eq(s21_memchr(dest, sym, byte), memchr(dest, sym, byte));
}
END_TEST

Suite *suite_memchr(void) {
  Suite *s = suite_create("suite_memchr");
  TCase *tc = tcase_create("memchr_tc");

  tcase_add_test(tc, empty_str);
  tcase_add_test(tc, end_str);
  tcase_add_test(tc, find_double_reg);
  tcase_add_test(tc, find_reg);
  tcase_add_test(tc, find_num);
  tcase_add_test(tc, find_num_in_array_num);
  tcase_add_test(tc, find_float_in_array);
  tcase_add_test(tc, double_sym);
  tcase_add_test(tc, none_sym);

  suite_add_tcase(s, tc);
  return s;
}