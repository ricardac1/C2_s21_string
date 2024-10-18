#include "s21_string_test.h"

START_TEST(empty_str) {
  char dest[15] = "";
  char sym = '\0';

  ck_assert_ptr_eq(s21_strrchr(dest, sym), strrchr(dest, sym));
}
END_TEST

START_TEST(end_str) {
  char dest[15] = "sfasdf";
  char sym = '\0';

  ck_assert_ptr_eq(s21_strrchr(dest, sym), strrchr(dest, sym));
}
END_TEST

START_TEST(find_double_reg) {
  char dest[15] = "AdsfAb";
  char sym = 'A';

  ck_assert_ptr_eq(s21_strrchr(dest, sym), strrchr(dest, sym));
}
END_TEST

START_TEST(find_reg) {
  char dest[15] = "Adsfab";
  char sym = 'A';

  ck_assert_ptr_eq(s21_strrchr(dest, sym), strrchr(dest, sym));
}
END_TEST

START_TEST(find_num) {
  char dest[15] = "string123";
  char sym = '2';

  ck_assert_ptr_eq(s21_strrchr(dest, sym), strrchr(dest, sym));
}
END_TEST

START_TEST(double_sym) {
  char dest[15] = "adkfdsa";
  char sym = 'a';

  ck_assert_ptr_eq(s21_strrchr(dest, sym), strrchr(dest, sym));
}
END_TEST

START_TEST(none_sym) {
  char dest[15] = "adada";
  char sym = 'c';

  ck_assert_ptr_eq(s21_strrchr(dest, sym), strrchr(dest, sym));
}
END_TEST

Suite *suite_strrchr(void) {
  Suite *s = suite_create("suite_strrchr");
  TCase *tc = tcase_create("strrchr_tc");

  tcase_add_test(tc, empty_str);
  tcase_add_test(tc, end_str);
  tcase_add_test(tc, find_double_reg);
  tcase_add_test(tc, find_reg);
  tcase_add_test(tc, find_num);
  tcase_add_test(tc, double_sym);
  tcase_add_test(tc, none_sym);

  suite_add_tcase(s, tc);
  return s;
}