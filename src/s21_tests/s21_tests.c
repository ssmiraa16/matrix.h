#include <check.h>

#include "../s21_matrix.h"

START_TEST(s21_create_matrix_1) {
  matrix_t A = {0};
  int reza = s21_create_matrix(2, 2, &A);
  ck_assert_int_eq(0, reza);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_2) {
  matrix_t B = {0};
  int reza2 = s21_create_matrix(-2, -2, &B);
  ck_assert_int_eq(1, reza2);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_create_matrix_3) {
  matrix_t C = {0};
  int reza3 = s21_create_matrix(0, 2, &C);
  ck_assert_int_eq(1, reza3);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_remove_matrix_test) {
  matrix_t A = {0};
  s21_create_matrix(3, 3, &A);
  s21_remove_matrix(&A);
  ck_assert_int_eq(A.rows, 0);
  ck_assert_int_eq(A.columns, 0);
  ck_assert_ptr_eq(NULL, A.matrix);
}
END_TEST

START_TEST(s21_eq_matrix_1) {
  int reza = 0;
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  reza = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(1, reza);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_2) {
  int reza = 0;
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(2, 3, &B);
  reza = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(0, reza);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(s21_eq_matrix_3) {
  int reza2 = 0;
  matrix_t C = {0};
  matrix_t D = {0};
  s21_create_matrix(3, 3, &C);
  s21_create_matrix(3, 3, &D);
  C.matrix[0][0] = 2;
  C.matrix[0][1] = 4;
  C.matrix[0][2] = 6;
  C.matrix[1][0] = 8;
  C.matrix[1][1] = 10;
  C.matrix[1][2] = 12;
  C.matrix[2][0] = 14;
  C.matrix[2][1] = 16;
  C.matrix[2][2] = 18;
  reza2 = s21_eq_matrix(&C, &D);
  ck_assert_int_eq(0, reza2);
  s21_remove_matrix(&C);
  s21_remove_matrix(&D);
}
END_TEST

START_TEST(s21_sum_matrix_2) {
  int reza = 0;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t R = {0};
  s21_create_matrix(-2, -2, &A);
  s21_create_matrix(3, 3, &B);
  reza = s21_sum_matrix(&A, &B, &R);
  ck_assert_int_eq(1, reza);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
}
END_TEST

START_TEST(s21_sum_matrix_3) {
  int reza = 0;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t R = {0};
  s21_create_matrix(2, 3, &A);
  s21_create_matrix(3, 3, &B);
  reza = s21_sum_matrix(&A, &B, &R);
  ck_assert_int_eq(2, reza);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
}
END_TEST

START_TEST(s21_sub_matrix_2) {
  int reza = 0;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t R = {0};
  s21_create_matrix(-2, -2, &A);
  s21_create_matrix(3, 3, &B);
  reza = s21_sub_matrix(&A, &B, &R);
  ck_assert_int_eq(1, reza);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
}
END_TEST

START_TEST(s21_sub_matrix_3) {
  int reza = 0;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t R = {0};
  s21_create_matrix(2, 3, &A);
  s21_create_matrix(3, 3, &B);
  reza = s21_sub_matrix(&A, &B, &R);
  ck_assert_int_eq(2, reza);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
}
END_TEST

START_TEST(s21_transpose_test) {
  int reza = 0;
  matrix_t A = {0};
  matrix_t R = {0};
  matrix_t R2 = {0};
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(2, 3, &R2);
  R2.matrix[0][0] = 1;
  R2.matrix[0][1] = 2;
  R2.matrix[0][2] = 3;
  R2.matrix[1][0] = 4;
  R2.matrix[1][1] = 5;
  R2.matrix[1][2] = 6;
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 4;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 5;
  A.matrix[2][0] = 3;
  A.matrix[2][1] = 6;
  reza = s21_transpose(&A, &R);
  ck_assert_int_eq(0, reza);
  ck_assert_int_eq(1, s21_eq_matrix(&R2, &R));
  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
  s21_remove_matrix(&R2);
}
END_TEST

START_TEST(s21_calc_complements_1x1) {
  int reza = 0;
  matrix_t A = {0};
  matrix_t R = {0};
  matrix_t R2 = {0};
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &R2);
  reza = s21_calc_complements(&A, &R);
  ck_assert_int_eq(0, reza);
  ck_assert_int_eq(1, s21_eq_matrix(&R2, &R));
  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
  s21_remove_matrix(&R2);
}
END_TEST

START_TEST(s21_calc_complements_1) {
  int reza = 0;
  matrix_t A = {0};
  matrix_t R = {0};
  matrix_t R2 = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &R2);
  R2.matrix[0][0] = 0;
  R2.matrix[0][1] = 10;
  R2.matrix[0][2] = -20;
  R2.matrix[1][0] = 4;
  R2.matrix[1][1] = -14;
  R2.matrix[1][2] = 8;
  R2.matrix[2][0] = -8;
  R2.matrix[2][1] = -2;
  R2.matrix[2][2] = 4;
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;
  reza = s21_calc_complements(&A, &R);
  ck_assert_int_eq(0, reza);
  ck_assert_int_eq(1, s21_eq_matrix(&R2, &R));
  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
  s21_remove_matrix(&R2);
}
END_TEST

START_TEST(s21_determinant_1) {
  int reza = 0;
  double r = 0;
  matrix_t A = {0};
  s21_create_matrix(3, 3, &A);
  reza = s21_determinant(&A, &r);
  ck_assert_int_eq(0, reza);
  ck_assert_double_eq(0, r);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_2) {
  int reza = 0;
  double r = 0;
  matrix_t A = {0};
  s21_create_matrix(2, 1, &A);
  reza = s21_determinant(&A, &r);
  ck_assert_int_eq(2, reza);
  ck_assert_double_eq(0, r);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_inverse_matrix_1) {
  int reza = 0;
  matrix_t A = {0};
  matrix_t R = {0};
  matrix_t R2 = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &R2);
  R2.matrix[0][0] = 1;
  R2.matrix[0][1] = -1;
  R2.matrix[0][2] = 1;
  R2.matrix[1][0] = -38;
  R2.matrix[1][1] = 41;
  R2.matrix[1][2] = -34;
  R2.matrix[2][0] = 27;
  R2.matrix[2][1] = -29;
  R2.matrix[2][2] = 24;
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;
  reza = s21_inverse_matrix(&A, &R);
  ck_assert_int_eq(0, reza);
  ck_assert_int_eq(1, s21_eq_matrix(&R2, &R));
  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
  s21_remove_matrix(&R2);
}
END_TEST

START_TEST(sum_matrix) {
  matrix_t A, B, result;
  A.matrix = NULL, B.matrix = NULL;
  int rows = 5, columns = 5;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = (double)(rand()) / RAND_MAX;
      B.matrix[i][j] = (double)(rand()) / RAND_MAX;
    }
  }
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &result), 0);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert_double_eq_tol(A.matrix[i][j] + B.matrix[i][j],
                              result.matrix[i][j], 1e-8);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);

  //

  rows = 5;
  columns = 5;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = (double)(rand()) / RAND_MAX;
      B.matrix[i][j] = (double)(rand()) / RAND_MAX;
    }
  }
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &result), 0);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert_double_eq_tol(A.matrix[i][j] + B.matrix[i][j],
                              result.matrix[i][j], 1e-8);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);

  //

  rows = 5;
  columns = 5;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = (double)(rand()) / RAND_MAX;
      B.matrix[i][j] = (double)(rand()) / RAND_MAX;
    }
  }
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &result), 0);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert_double_eq_tol(A.matrix[i][j] + B.matrix[i][j],
                              result.matrix[i][j], 1e-8);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);

  //

  s21_create_matrix(5, 5, &A);
  s21_create_matrix(4, 5, &B);
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &result), 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);

  //

  A.matrix = NULL, B.matrix = NULL;
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &result), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sub_matrix) {
  matrix_t A, B, result;
  A.matrix = NULL, B.matrix = NULL;
  int rows = 5, columns = 5;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = (double)(rand()) / RAND_MAX;
      B.matrix[i][j] = (double)(rand()) / RAND_MAX;
    }
  }
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), 0);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert_double_eq_tol(A.matrix[i][j] - B.matrix[i][j],
                              result.matrix[i][j], 1e-8);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);

  //

  rows = 5;
  columns = 5;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = (double)(rand()) / RAND_MAX;
      B.matrix[i][j] = (double)(rand()) / RAND_MAX;
    }
  }
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), 0);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert_double_eq_tol(A.matrix[i][j] - B.matrix[i][j],
                              result.matrix[i][j], 1e-8);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);

  //

  rows = 5;
  columns = 5;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = (double)(rand()) / RAND_MAX;
      B.matrix[i][j] = (double)(rand()) / RAND_MAX;
    }
  }
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), 0);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert_double_eq_tol(A.matrix[i][j] - B.matrix[i][j],
                              result.matrix[i][j], 1e-8);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);

  //

  s21_create_matrix(5, 5, &A);
  s21_create_matrix(4, 5, &B);
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);

  //

  A.matrix = NULL, B.matrix = NULL;
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_matrix) {
  matrix_t A, B, result;
  int Arows = 3, Acolumns = 5;
  int Brows = 5, Bcolumns = 6;
  s21_create_matrix(Arows, Acolumns, &A);
  s21_create_matrix(Brows, Bcolumns, &B);
  for (int i = 0; i < Arows; i++) {
    for (int j = 0; j < Acolumns; j++) {
      A.matrix[i][j] = (double)(rand()) / RAND_MAX;
    }
  }
  for (int i = 0; i < Brows; i++) {
    for (int j = 0; j < Bcolumns; j++) {
      B.matrix[i][j] = (double)(rand()) / RAND_MAX;
    }
  }
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);

  //

  Arows = 30;
  Acolumns = 144;
  Brows = 144;
  Bcolumns = 27;
  s21_create_matrix(Arows, Acolumns, &A);
  s21_create_matrix(Brows, Bcolumns, &B);
  for (int i = 0; i < Arows; i++) {
    for (int j = 0; j < Acolumns; j++) {
      A.matrix[i][j] = (double)(rand()) / RAND_MAX;
    }
  }
  for (int i = 0; i < Brows; i++) {
    for (int j = 0; j < Bcolumns; j++) {
      B.matrix[i][j] = (double)(rand()) / RAND_MAX;
    }
  }
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);

  //

  Arows = 4;
  Acolumns = 10;
  Brows = 13;
  Bcolumns = 27;
  s21_create_matrix(Arows, Acolumns, &A);
  s21_create_matrix(Brows, Bcolumns, &B);
  for (int i = 0; i < Arows; i++) {
    for (int j = 0; j < Acolumns; j++) {
      A.matrix[i][j] = (double)(rand()) / RAND_MAX;
    }
  }
  for (int i = 0; i < Brows; i++) {
    for (int j = 0; j < Bcolumns; j++) {
      B.matrix[i][j] = (double)(rand()) / RAND_MAX;
    }
  }
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);

  //

  Arows = 3;
  Acolumns = 10;
  Brows = 14;
  Bcolumns = 2;
  s21_create_matrix(Arows, Acolumns, &A);
  s21_create_matrix(Brows, Bcolumns, &B);
  for (int i = 0; i < Arows; i++) {
    for (int j = 0; j < Acolumns; j++) {
      A.matrix[i][j] = (double)(rand()) / RAND_MAX;
    }
  }
  for (int i = 0; i < Brows; i++) {
    for (int j = 0; j < Bcolumns; j++) {
      B.matrix[i][j] = (double)(rand()) / RAND_MAX;
    }
  }
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);

  //

  A.matrix = NULL;
  B.matrix = NULL;
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

Suite *s21_matrix_suite(void) {
  Suite *suite;

  suite = suite_create("s21_matrix");
  TCase *tcase_core = tcase_create("Core");

  tcase_add_test(tcase_core, s21_create_matrix_1);
  tcase_add_test(tcase_core, s21_create_matrix_2);
  tcase_add_test(tcase_core, s21_create_matrix_3);
  tcase_add_test(tcase_core, s21_remove_matrix_test);
  tcase_add_test(tcase_core, s21_eq_matrix_1);
  tcase_add_test(tcase_core, s21_eq_matrix_2);
  tcase_add_test(tcase_core, s21_eq_matrix_3);
  tcase_add_test(tcase_core, s21_sum_matrix_2);
  tcase_add_test(tcase_core, s21_sum_matrix_3);
  tcase_add_test(tcase_core, s21_sub_matrix_2);
  tcase_add_test(tcase_core, s21_sub_matrix_3);
  tcase_add_test(tcase_core, s21_transpose_test);
  tcase_add_test(tcase_core, s21_calc_complements_1x1);
  tcase_add_test(tcase_core, s21_calc_complements_1);
  tcase_add_test(tcase_core, s21_determinant_1);
  tcase_add_test(tcase_core, s21_determinant_2);
  tcase_add_test(tcase_core, s21_inverse_matrix_1);
  tcase_add_test(tcase_core, sum_matrix);
  tcase_add_test(tcase_core, sub_matrix);
  tcase_add_test(tcase_core, mult_matrix);

  suite_add_tcase(suite, tcase_core);

  return suite;
}