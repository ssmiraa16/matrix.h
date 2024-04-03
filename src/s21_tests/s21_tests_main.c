#include "s21_tests_main.h"

int main() {
  Suite *suite = s21_matrix_suite();
  SRunner *suite_runner = srunner_create(suite);
  srunner_set_fork_status(suite_runner, CK_NOFORK);
  srunner_run_all(suite_runner, CK_NORMAL);
  int failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);
  printf("\033[%dm FAILED: %d \033[0m \n", failed_count ? 41 : 42,
         failed_count);

  return (failed_count == 0) ? 0 : 1;
}
