#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int result_code = 0;
  if (s21_check(A) == 0 && s21_check(B) == 0) {
    if ((A->columns == B->rows)) {
      result_code = s21_create_matrix(A->rows, B->columns, result);
      if (result_code == 0) {
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < B->columns; j++) {
            result->matrix[i][j] = 0;
            for (int k = 0; k < A->columns; k++) {
              result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
            }
          }
        }
      } else {
        result_code = 1;
      }
    } else {
      result_code = 2;
    }
  } else {
    result_code = 1;
  }
  return result_code;
}