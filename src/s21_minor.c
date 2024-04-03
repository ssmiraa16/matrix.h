#include "s21_matrix.h"

int s21_minor(matrix_t *A, matrix_t *result, int rows, int columns) {
  int result_code = 0;
  if (s21_create_matrix(A->rows - 1, A->columns - 1, result) == 0) {
    int minor_row = 0;
    for (int i = 0; i < A->rows; i++) {
      if (i == rows) continue;
      int minor_columns = 0;
      for (int j = 0; j < A->columns; j++) {
        if (j == columns) continue;
        result->matrix[minor_row][minor_columns] = A->matrix[i][j];
        minor_columns++;
      }
      minor_row++;
    }
  } else
    result_code = 1;
  return result_code;
}