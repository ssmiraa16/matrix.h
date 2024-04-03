#include "s21_matrix.h"

int s21_check(matrix_t *matrix) {
  int result_code;
  if (matrix != NULL && matrix->matrix != NULL && matrix->rows >= 1 &&
      matrix->columns >= 1) {
    result_code = 0;
  } else {
    result_code = 1;
  }
  return result_code;
}