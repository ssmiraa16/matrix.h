#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int result_code = 0;
  if ((rows < 1) || (columns < 1)) {
    result_code = 1;
  } else {
    result->columns = columns;
    result->rows = rows;

    result->matrix = malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++) {
      result->matrix[i] = malloc(columns * sizeof(double));
    }
  }
  return result_code;
}