#include "s21_string_test.h"

START_TEST(token_operation) {
  char str1[] = "aboBA+ pipka = = pppp +++ !s21+=21+++";
  char str2[] = "aboBA+ pipka = = pppp +++ !s21+=21+++";
  const char delims[] = "+ =";

  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);

  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_pstr_eq(got, expected);

  while (got && expected) {
    got = s21_strtok(NULL, delims);
    expected = strtok(NULL, delims);

    ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));

    if (got || expected) {
      ck_assert_pstr_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(no_del) {
  char str1[] = "aboBApipkapppps2121";
  char str2[] = "aboBApipkapppps2121";
  const char delims[] = "+ = ! _ ";

  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);

  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_pstr_eq(got, expected);

  while (got && expected) {
    got = s21_strtok(NULL, delims);
    expected = strtok(NULL, delims);

    ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));

    if (got || expected) {
      ck_assert_pstr_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(hard_str) {
  char str1[] = "=               3kk! =_  my111!!!!!!!=1!!!!";
  char str2[] = "=               3kk! =_  my111!!!!!!!=1!!!!";
  const char delims[] = "=! _";

  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);

  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_pstr_eq(got, expected);

  while (got && expected) {
    got = s21_strtok(NULL, delims);
    expected = strtok(NULL, delims);

    ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));

    if (got || expected) {
      ck_assert_pstr_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(only_del) {
  char str1[] = "!!!!!!!!!!!!!!!+ _!!=";
  char str2[] = "!!!!!!!!!!!!!!!+ _!!=";
  const char delims[] = "+ = ! _ ";

  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);

  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_pstr_eq(got, expected);

  while (got && expected) {
    got = s21_strtok(NULL, delims);
    expected = strtok(NULL, delims);

    ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));

    if (got || expected) {
      ck_assert_pstr_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

Suite *suite_strtok(void) {
  Suite *s = suite_create("suite_strtok");
  TCase *tc = tcase_create("strtok_tc");

  tcase_add_test(tc, token_operation);
  tcase_add_test(tc, no_del);
  tcase_add_test(tc, only_del);
  tcase_add_test(tc, hard_str);

  suite_add_tcase(s, tc);
  return s;
}