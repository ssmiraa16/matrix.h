#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int result_code = 0;
  if (s21_check(A) != 0)
    result_code = 1;
  else if (A->rows != A->columns)
    result_code = 2;
  matrix_t calc = {0}, transpons = {0};
  double determinant = 0.0;
  s21_determinant(A, &determinant);
  if (fabs(determinant) < 1e-7)
    result_code = 2;
  else
    s21_calc_complements(A, &calc);
  s21_transpose(&calc, &transpons);
  s21_mult_number(&transpons, 1 / determinant, result);
  s21_remove_matrix(&calc);
  s21_remove_matrix(&transpons);
  return result_code;
}