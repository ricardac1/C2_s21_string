#include "test/s21_string_test.h"

int main(void) {
  run_tests();
  return 0;
}

void run_testcase(Suite *testcase) {
  setlocale(LC_ALL, "");
  static int counter_testcase = 1;

  if (counter_testcase > 1) putchar('\n');
  printf("%s%d%s", "CURRENT TEST: ", counter_testcase, "\n");
  counter_testcase++;

  SRunner *sr = srunner_create(testcase);

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);

  srunner_free(sr);
}

void run_tests(void) {
  Suite *list_cases[] = {suite_memcpy(),
                         suite_strcat(),
                         suite_strcspn(),
                         suite_strlen(),
                         suite_strpbrk(),
                         suite_strrchr(),
                         suite_strchr(),
                         suite_strcmp(),
                         suite_strncmp(),
                         suite_strncat(),
                         suite_strcpy(),
                         suite_strstr(),
                         suite_strncpy(),
                         suite_strerror(),
                         suite_strtok(),
                         suite_to_lower(),
                         suite_to_upper(),
                         suite_insert(),
                         suite_memcmp(),
                         suite_memset(),
                         suite_memmove(),
                         suite_memchr(),
                         suite_trim(),
                         suite_sprintf(),
                         NULL};

  for (Suite **current_testcase = list_cases; *current_testcase != NULL;
       current_testcase++) {
    run_testcase(*current_testcase);
  }
}