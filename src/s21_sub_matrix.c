#include "s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int result_code = 0;
  if (s21_check(A) == 0 && s21_check(B) == 0) {
    if ((A->columns == B->columns) && (A->rows == B->rows)) {
      result_code = s21_create_matrix(A->rows, A->columns, result);
      if (result_code == 0) {
        for (int i = 0; i < result->rows; i++) {
          for (int j = 0; j < result->columns; j++) {
            result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
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