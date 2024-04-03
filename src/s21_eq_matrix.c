#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int result_code = SUCCESS;
  if (s21_check(A) == 0 && s21_check(B) == 0) {
    if ((A->columns == B->columns) && (A->rows == B->rows)) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 1e-6) {
            result_code = FAILURE;
          }
        }
      }
    } else {
      result_code = FAILURE;
    }
  } else {
    result_code = FAILURE;
  }
  return result_code;
}