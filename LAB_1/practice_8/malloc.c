#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int** allocateMatrix(int rows, int cols) {
  int** matrix = (int**)malloc(rows * sizeof(int*));
  if (matrix == NULL) {
    printf("Memory allocation failed.\n");
    exit(-1);
  }

  for (int i = 0; i < rows; i++) {
    matrix[i] = (int*)malloc(cols * sizeof(int));
    if (matrix[i] == NULL) {
      printf("Memory allocation failed.\n");
      exit(-1);
    }
  }

  return matrix;
}

void freeMatrix(int** matrix, int rows) {
  for (int i = 0; i < rows; i++) {
    free(matrix[i]);
  }
  free(matrix);
}

void addMatrices(int** matrix1,
                 int** matrix2,
                 int** result,
                 int rows,
                 int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      result[i][j] = matrix1[i][j] + matrix2[i][j];
    }
  }
}

int main(int argc, char* argv[]) {
  if (argc != 3) {
    printf("Usage: matrix_add rows cols\n");
    return 1;
  }

  int rows = atoi(argv[1]);
  int cols = atoi(argv[2]);

  int** matrix1 = allocateMatrix(rows, cols);
  int** matrix2 = allocateMatrix(rows, cols);
  int** result = allocateMatrix(rows, cols);

  srand(time(NULL));

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      matrix1[i][j] = rand() % 100;  // 랜덤 값을 행렬에 저장
      matrix2[i][j] = rand() % 100;
    }
  }

  addMatrices(matrix1, matrix2, result, rows, cols);

  printf("Matrix 1:\n");
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%d\t", matrix1[i][j]);
    }
    printf("\n");
  }

  printf("Matrix 2:\n");
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%d\t", matrix2[i][j]);
    }
    printf("\n");
  }

  printf("Result Matrix:\n");
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%d\t", result[i][j]);
    }
    printf("\n");
  }

  freeMatrix(matrix1, rows);
  freeMatrix(matrix2, rows);
  freeMatrix(result, rows);

  return 0;
}
