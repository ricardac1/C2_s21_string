#include "s21_string_test.h"

START_TEST(HelloWorld) {
  char dest[15] = "Hello";
  char src[] = "world";

  char dest2[15] = "Hello";
  char src2[] = "world";

  s21_size_t n = 3;

  s21_strncat(dest, src, n);
  strncat(dest2, src2, n);

  ck_assert_str_eq(dest, dest2);
}
END_TEST

START_TEST(Biba) {
  char dest[15] = "";
  char src[] = "Biba";

  char dest2[15] = "";
  char src2[] = "Biba";

  s21_size_t n = 3;

  s21_strncat(dest, src, n);
  strncat(dest2, src2, n);

  ck_assert_str_eq(dest, dest2);
}
END_TEST

START_TEST(Boba) {
  char dest[] = "Boba";
  char src[] = "";

  char dest2[] = "Boba";
  char src2[] = "";

  s21_size_t n = 0;

  s21_strncat(dest, src, n);
  strncat(dest2, src2, n);

  ck_assert_str_eq(dest, dest2);
}
END_TEST

START_TEST(zero_zero) {
  char dest[] = "";
  char src[] = "";

  char dest2[] = "";
  char src2[] = "";

  s21_size_t n = 0;

  s21_strncat(dest, src, n);
  strncat(dest2, src2, n);

  ck_assert_str_eq(dest, dest2);
}
END_TEST

START_TEST(any_letters_with_register) {
  char dest[5 + 65] = "Hello";
  char src[] = "asdfj  asd1f aisdfjwASD SA asDSad SDAsdwqqeAS";

  char dest2[5 + 65] = "Hello";
  char src2[] = "asdfj  asd1f aisdfjwASD SA asDSad SDAsdwqqeAS";

  s21_size_t n = 15;

  s21_strncat(dest, src, n);
  strncat(dest2, src2, n);

  ck_assert_str_eq(dest, dest2);
}
END_TEST

START_TEST(any_letters_with_register_and_num_and_sim) {
  char dest[5 + 65] = "Hello";
  char src[] =
      "asd0fj  asd1f aisdfjw6234A1241SD SA5 asDSad 89SDAsdw7qqeAS)(?!.,";

  char dest2[5 + 65] = "Hello";
  char src2[] =
      "asd0fj  asd1f aisdfjw6234A1241SD SA5 asDSad 89SDAsdw7qqeAS)(?!.,";

  s21_size_t n = 20;

  s21_strncat(dest, src, n);
  strncat(dest2, src2, n);

  ck_assert_str_eq(dest, dest2);
}
END_TEST

Suite *suite_strncat(void) {
  Suite *s = suite_create("suite_strncat");
  TCase *tc = tcase_create("strncat_tc");

  tcase_add_test(tc, HelloWorld);
  tcase_add_test(tc, Biba);
  tcase_add_test(tc, Boba);
  tcase_add_test(tc, zero_zero);
  tcase_add_test(tc, any_letters_with_register);
  tcase_add_test(tc, any_letters_with_register_and_num_and_sim);

  suite_add_tcase(s, tc);
  return s;
}