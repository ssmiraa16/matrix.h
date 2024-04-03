#include "s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int result_code = 0;
  if (s21_check(A) == 0) {
    result_code = s21_create_matrix(A->rows, A->columns, result);
    if (result_code == 0) {
      for (int i = 0; i < result->rows; i++) {
        for (int j = 0; j < result->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] * number;
        }
      }
    } else {
      result_code = 1;
    }
  } else {
    result_code = 1;
  }
  return result_code;
}