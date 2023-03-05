#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "math.h"
#include "C:/untitled/libs/data_structures/Matrix/Matrix.h"

Position getLeftMin(Matrix m) {
    int leftMinRow = 0;
    int leftMinCol = 0;

    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            if (m.values[i][j] < m.values[leftMinRow][leftMinCol]) {
                leftMinRow = i;
                leftMinCol = j;
            }
        }
    }

    return (Position) {leftMinRow, leftMinCol};
}


void swapPointer(int** a, int** b) {
    int *t = *a;
    *a = *b;
    *b = t;
}

void swapPenultimateRow(Matrix m, int n) {
    assert(m.nRows >= 2);

    int* arrayCols = (int*)malloc(sizeof(int) * m.nRows);
    for (int i = 0; i < m.nRows; i++)
        arrayCols[i] = m.values[i][n];

    swapPointer(&arrayCols,&m.values[m.nRows - 2]);
}

int main() {

    Matrix m1 = createMatrixFromArray((int[]) {
            6, 3, 3,
            4, 5, 6,
            10, 1, 0,
    }, 3, 3);


    Position leftPos1 = getLeftMin(m1);

    swapPenultimateRow(m1, leftPos1.colIndex);

    outputMatrix(m1);
    printf("\n");

    freeMatrix(m1);

    Matrix m2 = createMatrixFromArray((int[]) {
            6, 3, 3,0,
            4, 5, 6,6,
            10, 1, 0,5,
            5,0,0,0
    }, 4, 4);


    Position leftPos2 = getLeftMin(m2);

    swapPenultimateRow(m2, leftPos2.colIndex);

    outputMatrix(m2);
    printf("\n");

    freeMatrix(m2);

    Matrix m3 = createMatrixFromArray((int[]) {
            6, 3,
            5,0
    }, 2, 2);


    Position leftPos3 = getLeftMin(m3);

    swapPenultimateRow(m3, leftPos3.colIndex);

    outputMatrix(m3);
    printf("\n");

    freeMatrix(m3);

    return 0;
}

