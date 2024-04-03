#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int result_code = 0;
  if (s21_check(A) == 0 || result != NULL) {
    *result = 0;
    if (A->columns == A->rows) {
      if (A->rows == 1) {
        *result = A->matrix[0][0];
      } else if (A->rows == 2) {
        *result = A->matrix[0][0] * A->matrix[1][1] -
                  A->matrix[0][1] * A->matrix[1][0];
      } else {
        int sign = 1;
        for (int i = 0; i < A->columns; i++) {
          matrix_t temp = {0};
          int check_minor = s21_minor(A, &temp, 0, i);
          double temp_d = 0;
          if (s21_determinant(&temp, &temp_d) == 0 && check_minor == 0) {
            *result += A->matrix[0][i] * temp_d * sign;
            sign = -sign;
            s21_remove_matrix(&temp);
          } else
            result_code = 2;
          s21_remove_matrix(&temp);
        }
      }
    } else {
      result_code = 2;
    }
  } else {
    result_code = 1;
  }
  return result_code;
}