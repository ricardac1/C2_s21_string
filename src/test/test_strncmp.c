#include "s21_string_test.h"

START_TEST(norm) {
  char str1[] = "Hello";
  char str2[] = "Hello";
  s21_size_t bytes = 3;

  int my = s21_strncmp(str1, str2, bytes);
  int expected = strncmp(str1, str2, bytes);

  if (my > 1) my = 1;
  if (expected > 1) expected = 1;

  if (my < -1) my = -1;
  if (expected < -1) expected = -1;

  ck_assert_int_eq(my, expected);
}
END_TEST

START_TEST(zero) {
  char str1[] = "";
  char str2[] = "";
  s21_size_t bytes = 0;

  int my = s21_strncmp(str1, str2, bytes);
  int expected = strncmp(str1, str2, bytes);

  if (my > 1) my = 1;
  if (expected > 1) expected = 1;

  if (my < -1) my = -1;
  if (expected < -1) expected = -1;

  ck_assert_int_eq(my, expected);
}
END_TEST

START_TEST(Hello_) {
  char str1[] = "Hello";
  char str2[] = "";
  s21_size_t bytes = 0;

  int my = s21_strncmp(str1, str2, bytes);
  int expected = strncmp(str1, str2, bytes);

  if (my > 1) my = 1;
  if (expected > 1) expected = 1;

  if (my < -1) my = -1;
  if (expected < -1) expected = -1;

  ck_assert_int_eq(my, expected);
}
END_TEST

START_TEST(_Hello) {
  char str1[] = "";
  char str2[] = "Hello";
  s21_size_t bytes = 0;

  int my = s21_strncmp(str1, str2, bytes);
  int expected = strncmp(str1, str2, bytes);

  if (my > 1) my = 1;
  if (expected > 1) expected = 1;

  if (my < -1) my = -1;
  if (expected < -1) expected = -1;

  ck_assert_int_eq(my, expected);
}
END_TEST

START_TEST(Shlepazxc_Shlepa) {
  char str1[] = "Shlepazxc";
  char str2[] = "Shlepa";
  s21_size_t bytes = 7;

  int my = s21_strncmp(str1, str2, bytes);
  int expected = strncmp(str1, str2, bytes);

  if (my > 1) my = 1;
  if (expected > 1) expected = 1;

  if (my < -1) my = -1;
  if (expected < -1) expected = -1;

  ck_assert_int_eq(my, expected);
}
END_TEST

START_TEST(Shlepa_Shlepa) {
  char str1[] = "Shlepa";
  char str2[] = "Shlepa";
  s21_size_t bytes = 1;

  int my = s21_strncmp(str1, str2, bytes);
  int expected = strncmp(str1, str2, bytes);

  if (my > 1) my = 1;
  if (expected > 1) expected = 1;

  if (my < -1) my = -1;
  if (expected < -1) expected = -1;

  ck_assert_int_eq(my, expected);
}
END_TEST

Suite *suite_strncmp(void) {
  Suite *s = suite_create("suite_strncmp");
  TCase *tc = tcase_create("strncmp_tc");

  tcase_add_test(tc, norm);
  tcase_add_test(tc, zero);
  tcase_add_test(tc, Hello_);
  tcase_add_test(tc, _Hello);
  tcase_add_test(tc, Shlepazxc_Shlepa);
  tcase_add_test(tc, Shlepa_Shlepa);

  suite_add_tcase(s, tc);
  return s;
}