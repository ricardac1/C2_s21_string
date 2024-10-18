#include "s21_string_test.h"

START_TEST(to_lower_test) {
  char str[] = "MAC TOP";
  char expected[] = "mac top";
  char *got = s21_to_lower(str);
  ck_assert_str_eq(got, expected);
  if (got) {
    free(got);
  }
}
END_TEST

START_TEST(numbers) {
  char str[] = "123";
  char expected[] = "123";
  char *got = s21_to_lower(str);
  ck_assert_str_eq(got, expected);
  if (got) {
    free(got);
  }
}
END_TEST

START_TEST(null) {
  char str[] = "";
  char expected[] = "";
  char *got = s21_to_lower(str);
  ck_assert_str_eq(got, expected);
  if (got) {
    free(got);
  }
}
END_TEST

START_TEST(space) {
  char str[] = " ";
  char expected[] = " ";
  char *got = s21_to_lower(str);
  ck_assert_str_eq(got, expected);
  if (got) {
    free(got);
  }
}
END_TEST

Suite *suite_to_lower(void) {
  Suite *s = suite_create("suite_to_lower");
  TCase *tc = tcase_create("to_lower_tc");

  tcase_add_test(tc, to_lower_test);
  tcase_add_test(tc, numbers);
  tcase_add_test(tc, null);
  tcase_add_test(tc, space);

  suite_add_tcase(s, tc);
  return s;
}