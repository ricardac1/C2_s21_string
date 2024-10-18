#include "s21_string_test.h"

START_TEST(empty_string_haystack_and_needle) {
  char haystack[] = "";
  char needle[] = "";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(empty_string_haystack) {
  char haystack[] = "";
  char needle[] = "youjon";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(empty_string_needle) {
  char haystack[] = "hdhilljHawe2fhilu";
  char needle[] = "";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(toxic_test) {
  char haystack[] = "You are chepux!";
  char needle[] = "chepux";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(not_word_in_haystack) {
  char haystack[] = "There is no right word in this test!";
  char needle[] = "NOT";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(words_with_any_register) {
  char haystack[] = "AbOBosNyTSa";
  char needle[] = "aBoboSNYTsa";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(repeated_words) {
  char haystack[] = "AD AD AD";
  char needle[] = "AD";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(word_at_end) {
  char haystack[] = "22 321 123";
  char needle[] = "123";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(one_simbol_in_needle_and_haystack) {
  char haystack[] = "1";
  char needle[] = "1";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(one_simbol_in_needle) {
  char haystack[] = "136255234nfkfo -4trg freshtsyASFWEt wEafe";
  char needle[] = " ";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(one_simbol_in_haystack) {
  char haystack[] = "-";
  char needle[] = "1234567890qwertyuiopasdfghjk-";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

Suite *suite_strstr(void) {
  Suite *s = suite_create("suite_strstr");
  TCase *tc = tcase_create("strstr_tc");

  tcase_add_test(tc, empty_string_haystack_and_needle);
  tcase_add_test(tc, empty_string_haystack);
  tcase_add_test(tc, empty_string_needle);
  tcase_add_test(tc, toxic_test);
  tcase_add_test(tc, not_word_in_haystack);
  tcase_add_test(tc, words_with_any_register);
  tcase_add_test(tc, repeated_words);
  tcase_add_test(tc, word_at_end);
  tcase_add_test(tc, one_simbol_in_needle_and_haystack);
  tcase_add_test(tc, one_simbol_in_needle);
  tcase_add_test(tc, one_simbol_in_haystack);

  suite_add_tcase(s, tc);
  return s;
}