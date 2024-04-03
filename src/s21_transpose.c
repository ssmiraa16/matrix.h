#include "s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int result_code = 0;
  if (s21_check(A) == 0) {
    result_code = s21_create_matrix(A->columns, A->rows, result);
    if (result_code == 0) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[j][i] = A->matrix[i][j];
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