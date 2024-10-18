#include "s21_string_test.h"

START_TEST(Hello_beautiful_world) {
  const char *original = "Hello, world!";
  const char *to_insert = "beautiful ";

  char test[30] = "Hello, beautiful world!";

  char *result = s21_insert(original, to_insert, 7);
  ck_assert_pstr_eq(result, test);
}
END_TEST

START_TEST(null) {
  const char *original = "Hello, world!";
  const char *to_insert = "beautiful ";

  char *test = S21_NULL;

  char *result = s21_insert(original, to_insert, 15);
  ck_assert_pstr_eq(result, test);
}
END_TEST

Suite *suite_insert(void) {
  Suite *s = suite_create("suite_insert");
  TCase *tc = tcase_create("insert_tc");

  tcase_add_test(tc, Hello_beautiful_world);
  tcase_add_test(tc, null);

  suite_add_tcase(s, tc);
  return s;
}