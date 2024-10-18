#include "s21_string_test.h"

START_TEST(middle) {
  char string[] = "It's gonna be sad, you know";
  s21_size_t kB = 28;
  char s21_memcpy_result[kB + 10];
  char memcpy_result[kB + 10];
  s21_memcpy(s21_memcpy_result, string, kB);
  memcpy(memcpy_result, string, kB);
  ck_assert_int_eq(memcmp(s21_memcpy_result, memcpy_result, kB), 0);
}
END_TEST

START_TEST(empty) {
  char string[] = "";
  s21_size_t kB = 0;
  char s21_memcpy_result[kB + 10];
  char memcpy_result[kB + 10];
  s21_memcpy(s21_memcpy_result, string, kB);
  memcpy(memcpy_result, string, kB);
  ck_assert_int_eq(memcmp(s21_memcpy_result, memcpy_result, kB), 0);
}
END_TEST

START_TEST(alone_char) {
  char string[] = "I";
  s21_size_t kB = 1;
  char s21_memcpy_result[kB + 10];
  char memcpy_result[kB + 10];
  s21_memcpy(s21_memcpy_result, string, kB);
  memcpy(memcpy_result, string, kB);
  ck_assert_int_eq(memcmp(s21_memcpy_result, memcpy_result, kB), 0);
}
END_TEST

START_TEST(long_string) {
  char string[] =
      "It's gonna be sad, you know. It's gonna be sad, you know. It's gonna be "
      "sad, you know. It's gonna "
      "be sad, you know. It's gonna be sad, you know. It's gonna be sad, you "
      "know. It's gonna be sad, you "
      "know. It's gonna be sad, you know. It's gonna be sad, you know. ";
  s21_size_t kB = 270;
  char s21_memcpy_result[kB + 10];
  char memcpy_result[kB + 10];
  s21_memcpy(s21_memcpy_result, string, kB);
  memcpy(memcpy_result, string, kB);
  ck_assert_int_eq(memcmp(s21_memcpy_result, memcpy_result, kB), 0);
}
END_TEST

START_TEST(empty_memory) {
  char string[] = "It's gonna be sad, you know";
  s21_size_t kB = 0;
  char s21_memcpy_result[kB + 10];
  char memcpy_result[kB + 10];
  s21_memcpy(s21_memcpy_result, string, kB);
  memcpy(memcpy_result, string, kB);
  ck_assert_int_eq(memcmp(s21_memcpy_result, memcpy_result, kB), 0);
}
END_TEST

START_TEST(nums) {
  char string[] = "123321";
  s21_size_t kB = 5;
  char s21_memcpy_result[kB + 10];
  char memcpy_result[kB + 10];
  s21_memcpy(s21_memcpy_result, string, kB);
  memcpy(memcpy_result, string, kB);
  ck_assert_int_eq(memcmp(s21_memcpy_result, memcpy_result, kB), 0);
}
END_TEST

START_TEST(registr) {
  char string[] = "It's gonna be sad, you know";
  s21_size_t kB = 2;
  char s21_memcpy_result[kB + 10];
  char memcpy_result[kB + 10];
  s21_memcpy(s21_memcpy_result, string, kB);
  memcpy(memcpy_result, string, kB);
  ck_assert_int_eq(memcmp(s21_memcpy_result, memcpy_result, kB), 0);
}
END_TEST

START_TEST(one_num) {
  char string[] = "123321";
  s21_size_t kB = 1;
  char s21_memcpy_result[kB + 10];
  char memcpy_result[kB + 10];
  s21_memcpy(s21_memcpy_result, string, kB);
  memcpy(memcpy_result, string, kB);
  ck_assert_int_eq(memcmp(s21_memcpy_result, memcpy_result, kB), 0);
}
END_TEST

START_TEST(long_registr) {
  char string[] = "SDKJGALDFG;ADFJNG;DFNG";
  s21_size_t kB = 28;
  char s21_memcpy_result[kB + 10];
  char memcpy_result[kB + 10];
  s21_memcpy(s21_memcpy_result, string, kB);
  memcpy(memcpy_result, string, kB);
  ck_assert_int_eq(memcmp(s21_memcpy_result, memcpy_result, kB), 0);
}
END_TEST

START_TEST(long_string_with_registr_and_num) {
  char string[] = "aodasf ieuwfh luhasdfLIAUSHD liuh 12li3uh 12i4ouhsdfh";
  s21_size_t kB = 53;
  char s21_memcpy_result[kB + 10];
  char memcpy_result[kB + 10];
  s21_memcpy(s21_memcpy_result, string, kB);
  memcpy(memcpy_result, string, kB);
  ck_assert_int_eq(memcmp(s21_memcpy_result, memcpy_result, kB), 0);
}
END_TEST

Suite *suite_memcpy(void) {
  Suite *s = suite_create("suite_memcpy");
  TCase *tc = tcase_create("memcpy_tc");

  tcase_add_test(tc, empty);
  tcase_add_test(tc, middle);
  tcase_add_test(tc, alone_char);
  tcase_add_test(tc, long_string);
  tcase_add_test(tc, empty_memory);
  tcase_add_test(tc, nums);
  tcase_add_test(tc, registr);
  tcase_add_test(tc, one_num);
  tcase_add_test(tc, long_registr);
  tcase_add_test(tc, long_string_with_registr_and_num);

  suite_add_tcase(s, tc);
  return s;
}