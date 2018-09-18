#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#ifndef CALC_H_INCLUDED
#define CLAC_H_INCLUDED

//int **matrix;
//int *rows;

float **createMatrix(float **matrix, int rows, int cols);
float **fillMatrix(float **matrix, int rows, int cols);
void printMatrix(float **matrix, int rows, int cols);
void desrtroyMatrix(float **matrix, int rows, int cols);
void rowMult(float **matrix, int rows, int cols, int numRow, float num);
void rowAdd(float **matrix, int rows, int cols, int addRow1, int addRow2, int numRow);
void rowSwap(float **matrix, int rows, int cols, int swapRow1, int swapRow2);
void printMenu();

#endif
