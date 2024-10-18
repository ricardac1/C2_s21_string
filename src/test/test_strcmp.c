#include "s21_string_test.h"

START_TEST(norm) {
  char str1[] = "Hello";
  char str2[] = "Hello";

  int my = s21_strcmp(str1, str2);
  int expected = strcmp(str1, str2);

  ck_assert_int_eq(my, expected);
}
END_TEST

START_TEST(zero) {
  char str1[] = "";
  char str2[] = "";

  int my = s21_strcmp(str1, str2);
  int expected = strcmp(str1, str2);

  ck_assert_int_eq(my, expected);
}
END_TEST

START_TEST(not_eq) {
  char str1[] = "Qweraqdf";
  char str2[] = "Helloasd";

  int my = s21_strcmp(str1, str2);
  int expected = strcmp(str1, str2);

  ck_assert_int_eq(my, expected);
}
END_TEST

START_TEST(not_eq_first_zero) {
  char str1[] = "";
  char str2[] = "Helloasd";

  int my = s21_strcmp(str1, str2);
  int expected = strcmp(str1, str2);

  ck_assert_int_eq(my, expected);
}
END_TEST

START_TEST(not_eq_second_zero) {
  char str1[] = "Helloasd";
  char str2[] = "";

  int my = s21_strcmp(str1, str2);
  int expected = strcmp(str1, str2);

  ck_assert_int_eq(my, expected);
}
END_TEST

Suite *suite_strcmp(void) {
  Suite *s = suite_create("suite_strcmp");
  TCase *tc = tcase_create("strcmp_tc");

  tcase_add_test(tc, norm);
  tcase_add_test(tc, zero);
  tcase_add_test(tc, not_eq);
  tcase_add_test(tc, not_eq_first_zero);
  tcase_add_test(tc, not_eq_second_zero);

  suite_add_tcase(s, tc);
  return s;
}