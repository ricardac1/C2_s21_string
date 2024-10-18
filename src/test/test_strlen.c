#include "s21_string_test.h"

START_TEST(empty) {
  char src[] = "";

  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(num) {
  char src[] = "89934600127";

  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(string) {
  char src[] =
      "12345678910QWERTYUIOPASDFGHJKLZXCVBNMmnbvcxzlkjhgfdsapoiuytrewqQwErTy899"
      "63415925";

  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(Mac_top) {
  char src[] = "Mac_top";

  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

Suite *suite_strlen(void) {
  Suite *s = suite_create("suite_strlen");
  TCase *tc = tcase_create("strlen_tc");

  tcase_add_test(tc, empty);
  tcase_add_test(tc, num);
  tcase_add_test(tc, string);
  tcase_add_test(tc, Mac_top);

  suite_add_tcase(s, tc);
  return s;
}