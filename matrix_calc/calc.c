#include "calc.h"

float **createMatrix(float **matrix, int rows, int cols){
  int r, c;
  for(r = 0; r < rows; r++){
    matrix[r] = malloc(cols * sizeof(float));
    if(!matrix[r]){
      if(r > 1){
        int i;
        for(i = 0; i < r; i++){
          free(matrix[i]);
        }
      }
      free(matrix[r]);
      break;
    }
  }
  return matrix;
}

float **fillMatrix(float **matrix, int rows, int cols){
  int r, c;
  float entry;
  for(r = 0; r < rows; r++){
    for(c = 0; c < cols; c++){
      printf("Entry for Row: %i , Column: %i\n", r + 1, c + 1);
      scanf("%f", &entry);
      matrix[r][c] = entry;
    }
  }
  return matrix;
}

void printMatrix(float **matrix, int rows, int  cols){
  int r,c;
  for(r = 0; r < rows; r++){
    printf("[ ");
    for(c = 0; c < cols; c++){
      printf("%f ", matrix[r][c]);
    }
    printf("] \n");
  }
}

void desrtroyMatrix(float **matrix, int rows, int cols){
  int r;
  for(r = 0; r < rows; r++){
      free(matrix[r]);
  }
  free(matrix);
}

void rowMult(float **matrix, int rows, int cols, int numRow, float num){
  int c;
  for(c = 0; c < cols; c++){
    float temp = matrix[numRow - 1][c];
    matrix[numRow - 1][c] = temp * num;
  }
}

void rowAdd(float **matrix, int rows, int cols, int addRow1, int addRow2, int numRow){
  int c;
  for(c = 0; c < cols; c++){
    matrix[numRow - 1][c] = matrix[addRow1 - 1][c] + matrix[addRow2 - 1][c];
  }
}

void rowSwap(float **matrix, int rows, int cols, int swapRow1, int swapRow2){
  int c;
  float temp[cols];
  for(c = 0; c < cols; c++){
    temp[c] = matrix[swapRow1 - 1][c];
    matrix[swapRow1 - 1][c] = matrix[swapRow2 - 1][c];
    matrix[swapRow2 - 1][c] = temp[c];
  }
}

void printMenu() {
  printf("Welcome to your Matrix calculator please type the number of the option you want and hit enter\n");
  printf("1. Create matrix and enter in values\n");
  printf("2. Print matrix\n");
  printf("3. Multiply a row by a number\n");
  printf("4. Add one row to another and replace a row\n");
  printf("5. Swap rows\n");
  printf("6. Exit\n");
}
