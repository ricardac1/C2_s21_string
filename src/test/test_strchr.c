#include "s21_string_test.h"

START_TEST(first) {
  const char *str = "Hello world";
  char *result = s21_strchr(str, 'o');
  char *expect = strchr(str, 'o');
  ck_assert_pstr_eq(result, expect);
}
END_TEST

START_TEST(second) {
  const char *str = "1234";
  char *result = s21_strchr(str, '1');
  char *expect = strchr(str, '1');
  ck_assert_pstr_eq(result, expect);
}
END_TEST

START_TEST(firdth) {
  const char *str = "_alowJAlw_skw";
  char *result = s21_strchr(str, 's');
  char *expect = strchr(str, 's');
  ck_assert_pstr_eq(result, expect);
}
END_TEST

START_TEST(foor) {
  const char *str = "";
  char *result = s21_strchr(str, 'o');
  char *expect = strchr(str, 'o');
  ck_assert_pstr_eq(result, expect);
}
END_TEST

START_TEST(five) {
  const char *str = "asdkdu";
  char *result = s21_strchr(str, 'o');
  char *expect = strchr(str, 'o');
  ck_assert_pstr_eq(result, expect);
}
END_TEST

START_TEST(six) {
  const char *str = "Char102ps";
  char *result = s21_strchr(str, '0');
  char *expect = strchr(str, '0');
  ck_assert_pstr_eq(result, expect);
}
END_TEST

START_TEST(seven) {
  const char *str = "asdjew";
  char *result = s21_strchr(str, 's');
  char *expect = strchr(str, 's');
  ck_assert_pstr_eq(result, expect);
}
END_TEST

Suite *suite_strchr(void) {
  Suite *s = suite_create("suite_strchr");
  TCase *tc = tcase_create("strchr_tc");

  tcase_add_test(tc, first);
  tcase_add_test(tc, second);
  tcase_add_test(tc, firdth);
  tcase_add_test(tc, foor);
  tcase_add_test(tc, five);
  tcase_add_test(tc, six);
  tcase_add_test(tc, seven);

  suite_add_tcase(s, tc);
  return s;
}