#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "C:/untitled/libs/data_structures/Matrix/Matrix.h"

bool isUnique(Matrix m, int n) {
    int *criteria = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < m.nRows; i++)
        criteria[i] = getSum(m.values[i],m.nCols);

    for (int i = 0; i < m.nRows; i++) {
        for(int j = i + 1; j < m.nRows; j++)
            if (criteria[i] == criteria[j])
                return false;
    }

    return true;
}
void transposeIfMatrixHasNotEqualSumOfRows(Matrix m) {
    assert(isSquareMatrix(m));

    if (isUnique(m,m.nRows))
        transposeSquareMatrix(m);
}


int main() {
    Matrix m1 = createMatrixFromArray((int[]) {
            1, 4, 5,
            4, 5, 8,
            5, 1, 0
    }, 3,3);

    transposeIfMatrixHasNotEqualSumOfRows(m1);

    outputMatrix(m1);

    freeMatrix(m1);
    printf("\n");

    Matrix m2 = createMatrixFromArray((int[]) {
            1, 4, 5, 6,
            4, 5, 8, 7,
            5, 1, 0, 8
    }, 3,4);

    transposeIfMatrixHasNotEqualSumOfRows(m2);

    outputMatrix(m2);

    freeMatrix(m2);
    printf("\n");

    Matrix m3 = createMatrixFromArray((int[]) {
            1, 0, 1,
            4, 5, 8,
            1, 1, 0,
    }, 3,3);

    transposeIfMatrixHasNotEqualSumOfRows(m3);

    outputMatrix(m3);

    freeMatrix(m3);
    printf("\n");

    return 0;
}

