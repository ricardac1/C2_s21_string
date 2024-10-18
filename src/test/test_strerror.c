#include "s21_string_test.h"

START_TEST(all_std_errors) {
  for (int i = -100; i < 150; i++) {
    char *got = s21_strerror(i);
    char *expected = strerror(i);
    ck_assert_str_eq(got, expected);
  }
}
END_TEST

Suite *suite_strerror(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("suite_strerror");
  tc = tcase_create("strerror_tc");
  tcase_add_test(tc, all_std_errors);
  suite_add_tcase(s, tc);
  return s;
}