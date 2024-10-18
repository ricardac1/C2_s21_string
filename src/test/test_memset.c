#include "s21_string_test.h"

START_TEST(first_test) {
  char res[] = "string";
  char expected[] = "string";
  char replace = 'g';
  s21_size_t bytes = 5;

  s21_memset(res, replace, bytes);
  memset(expected, replace, bytes);

  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(second_test) {
  char res[] = "string";
  char expected[] = "string";
  char replace = '\0';
  s21_size_t bytes = 0;

  s21_memset(res, replace, bytes);
  memset(expected, replace, bytes);

  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(third_test) {
  char res[] = "string";
  char expected[] = "string";
  char replace = 'g';
  s21_size_t bytes = 6;

  s21_memset(res, replace, bytes);
  memset(expected, replace, bytes);

  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(fourth_test) {
  char res[] = "string";
  char expected[] = "string";
  char replace = '1';
  s21_size_t bytes = 1;

  s21_memset(res, replace, bytes);
  memset(expected, replace, bytes);

  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(fith_test) {
  char res[] = "string";
  char expected[] = "string";
  char replace = 'A';
  s21_size_t bytes = 2;

  s21_memset(res, replace, bytes);
  memset(expected, replace, bytes);

  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(sixth_test) {
  char res[] = "string";
  char expected[] = "string";
  char replace = '+';
  s21_size_t bytes = 3;

  s21_memset(res, replace, bytes);
  memset(expected, replace, bytes);

  ck_assert_str_eq(res, expected);
}
END_TEST

Suite *suite_memset(void) {
  Suite *s = suite_create("suite_memset");
  TCase *tc = tcase_create("memset_tc");

  tcase_add_test(tc, first_test);
  tcase_add_test(tc, second_test);
  tcase_add_test(tc, third_test);
  tcase_add_test(tc, fourth_test);
  tcase_add_test(tc, fith_test);
  tcase_add_test(tc, sixth_test);

  suite_add_tcase(s, tc);
  return s;
}