#include "calc.c"

int main() {
  int choice,rows,cols = 0;
  float **matrix;
  do {
    printMenu();
    scanf("%d", &choice);
    if(choice == 1) {
      printf("How many rows are in your matrix?\n");
      scanf("%d",&rows);
      printf("How many cols are in your matrix?\n");
      scanf("%d",&cols);
      matrix = malloc(rows * sizeof(float*));
      if(matrix){
      matrix = createMatrix(matrix, rows, cols);
      }else {
      free(matrix);
      }
      matrix = fillMatrix(matrix, rows, cols);

    }
    if(choice == 2){
      printMatrix(matrix, rows, cols);
    }
    if(choice == 3){
      float num;
      int numRow;
      printf("What number do you want to multiply a row by?\n");
      scanf("%f",&num);
      printf("which row do you want to multiply that number by?\n");
      scanf("%i",&numRow);
      rowMult(matrix, rows, cols, numRow, num);
    }
    if(choice == 4){
      int addRow1, addRow2, numRow;
      printf("What rows do you want to add together?\n First Row: ");
      scanf("%d", &addRow1);
      printf("Second Row: \n");
      scanf("%d", &addRow2);
      printf("What row would you like to replace with the result?\n");
      scanf("%d", &numRow);
      rowAdd(matrix, rows, cols, addRow1, addRow2, numRow);
    }
    if(choice == 5){
      int swapRow1,swapRow2;
      printf("What rows would you like to swap?\n First Row: ");
      scanf("%d", &swapRow1);
      printf("Second Row: ");
      scanf("%d", &swapRow2);
      rowSwap(matrix, rows, cols, swapRow1, swapRow2);

    }
    if(choice == 6){
      desrtroyMatrix(matrix, rows, cols);
    }

  } while(choice != 6);


  return 0;
}
