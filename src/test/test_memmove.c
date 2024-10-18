#include "s21_string_test.h"

START_TEST(empty_dest_and_src) {
  char string[100] = "";
  char string2[100] = "";
  s21_size_t copy_kB = 0;

  char *res = string;
  char *expected = string2;
  s21_size_t kB = 0;

  s21_memmove(res, string, copy_kB);
  memmove(expected, string2, copy_kB);

  ck_assert_mem_eq(res, expected, kB);
}
END_TEST

START_TEST(empty_dest) {
  char string[100] = "123SDFAZ`ESFsdfsdf";
  char string2[100] = "123SDFAZ`ESFsdfsdf";
  s21_size_t copy_kB = 10;

  char res[100] = "";
  char expected[100] = "";
  s21_size_t kB = 10;

  s21_memmove(res, string, copy_kB);
  memmove(expected, string2, copy_kB);

  ck_assert_mem_eq(res, expected, kB);
}
END_TEST

START_TEST(empty_src) {
  char string[100] = "";
  char string2[100] = "";
  s21_size_t copy_kB = 0;

  char res[100] = "i asdqwe love";
  char expected[100] = "i asdqwe love";
  s21_size_t kB = 13;

  s21_memmove(res, string, copy_kB);
  memmove(expected, string2, copy_kB);

  ck_assert_mem_eq(res, expected, kB);
}
END_TEST

START_TEST(write_in_left) {
  char string[100] = "Hate";
  char string2[100] = "Hate";
  s21_size_t copy_kB = 4;

  char res[100] = "i hate memcmp";
  char expected[100] = "i hate memcmp";
  s21_size_t kB = 17;

  s21_memmove(res, string, copy_kB);
  memmove(expected, string2, copy_kB);

  ck_assert_mem_eq(res, expected, kB);
}
END_TEST

START_TEST(write_in_right) {
  char string[100] = "like";
  char string2[100] = "like";
  s21_size_t copy_kB = 4;

  char res[100] = "I asdadasgtrs...";
  char expected[100] = "I asdadasgtrs...";
  s21_size_t kB = 17;

  s21_memmove(res + 13, string, copy_kB);
  memmove(expected + 13, string2, copy_kB);

  ck_assert_mem_eq(res, expected, kB);
}
END_TEST

START_TEST(write_in_mid) {
  char string[100] = "like";
  char string2[100] = "like";
  s21_size_t copy_kB = 4;

  char res[100] = "I asdadasgtrs";
  char expected[100] = "I asdadasgtrs";
  s21_size_t kB = 17;

  s21_memmove(res + 5, string, copy_kB);
  memmove(expected + 5, string2, copy_kB);

  ck_assert_mem_eq(res, expected, kB);
}
END_TEST

START_TEST(overlap_write_in_left) {
  char string[100] = "I asdadasgtrs...";
  char string2[100] = "I asdadasgtrs...";
  s21_size_t copy_kB = 17;

  char *res = string;
  char *expected = string2;
  s21_size_t kB = 34;

  s21_memmove(res, string, copy_kB);
  memmove(expected, string2, copy_kB);

  ck_assert_mem_eq(res, expected, kB);
}
END_TEST

START_TEST(overlap_write_in_mid) {
  char string[100] = "u love memsets...";
  char string2[100] = "u love memsets...";
  s21_size_t copy_kB = 17;

  char *res = string + 5;
  char *expected = string2 + 5;
  s21_size_t kB = 34;

  s21_memmove(res, string, copy_kB);
  memmove(expected, string2, copy_kB);

  ck_assert_mem_eq(res, expected, kB);
}
END_TEST

Suite *suite_memmove(void) {
  Suite *s = suite_create("suite_memmove");
  TCase *tc = tcase_create("memmove_tc");

  tcase_add_test(tc, empty_dest_and_src);
  tcase_add_test(tc, empty_dest);
  tcase_add_test(tc, empty_src);
  tcase_add_test(tc, write_in_left);
  tcase_add_test(tc, write_in_right);
  tcase_add_test(tc, write_in_mid);
  tcase_add_test(tc, overlap_write_in_left);
  tcase_add_test(tc, overlap_write_in_mid);

  suite_add_tcase(s, tc);
  return s;
}