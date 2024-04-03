#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int result_code = 0;
  if (s21_check(A) == 0) {
    if (A->rows != A->columns) {
      result_code = 2;
    } else if (A->rows == 1) {
      if (s21_create_matrix(A->rows, A->columns, result) == 0) {
        result->matrix[0][0] = A->matrix[0][0];
      }
    } else if (s21_create_matrix(A->rows, A->columns, result) == 0) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          matrix_t temp = {0};
          double t = 0;
          s21_minor(A, &temp, i, j);
          if (s21_determinant(&temp, &t) == 0) {
            result->matrix[i][j] = pow(-1, (i + j)) * t;
            s21_remove_matrix(&temp);
          } else
            result_code = 2;
        }
      }
    }
  }
  return result_code;
}