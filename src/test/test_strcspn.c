#include "s21_string_test.h"

START_TEST(empty) {
  char src[] = "";
  char res[] = "";
  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(kazan) {
  char src[] = "kazan";
  char res[] = "";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(num_num) {
  char src[] = "123";
  char res[] = "123";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(aboba) {
  char src[] = "";
  char res[] = "aboba";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(Register) {
  char src[] = "aboba";
  char res[] = "ABOBA";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(long_num) {
  char src[] = "12345";
  char res[] = "123";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(num_long_num) {
  char src[] = "123";
  char res[] = "12345";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(any_num) {
  char src[] = "1234567890";
  char res[] = "0987654321";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(num_with_letter) {
  char src[] = "1A2A3A4A5A";
  char res[] = "123";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(num_with_letter2) {
  char src[] = "a1aaa23aaa41235";
  char res[] = "123";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(basic_test) {
  char src[] = "absD";
  char res[] = "aD";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(any_sim) {
  char src[] = "01j1kdewre23nsjlnINOISM:OK32923????;owrmd";
  char res[] = "0987654321";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(lower_letter) {
  char src[] = "32jersASDASDPare[0g9jf m07y271234567890";
  char res[] = "1234567890qwertyuiopasdfghjklczxcvbnm";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(not_uniq_sim) {
  char src[] =
      "333333333333333333333333333333333333333333333333333333333333333333333333"
      "33333333333333";
  char res[] =
      "111111111111111111111111111111111111111111111111111111111111111111111111"
      "11111111111113";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

Suite *suite_strcspn(void) {
  Suite *s = suite_create("suite_strcspn");
  TCase *tc = tcase_create("strcspn_tc");

  tcase_add_test(tc, empty);
  tcase_add_test(tc, basic_test);
  tcase_add_test(tc, any_sim);
  tcase_add_test(tc, not_uniq_sim);
  tcase_add_test(tc, kazan);
  tcase_add_test(tc, aboba);
  tcase_add_test(tc, Register);
  tcase_add_test(tc, num_num);
  tcase_add_test(tc, long_num);
  tcase_add_test(tc, num_long_num);
  tcase_add_test(tc, any_num);
  tcase_add_test(tc, num_with_letter);
  tcase_add_test(tc, num_with_letter2);
  tcase_add_test(tc, lower_letter);

  suite_add_tcase(s, tc);
  return s;
}