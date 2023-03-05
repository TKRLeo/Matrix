#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "math.h"
#include "C:/untitled/libs/data_structures/Matrix/Matrix.h"

float getDistance(int *a, int n) {
    float nPow2 = 0;
    for (int i = 0; i < n; i++) {
        nPow2 += a[i] * a[i];
    }

    return sqrt(nPow2);
}

void insertionSortRowsMatrixByRowCriteriaF(Matrix m,
                                           float (*criteria)(int *, int)) {
    float *criteriaValues = (int *) malloc(sizeof(float) * m.nRows);
    for (int i = 0; i < m.nRows; i++)
        criteriaValues[i] = criteria(m.values[i], m.nCols);


    for (int i = 1; i < m.nRows; i++) {
        int index = i;
        while (index > 0 && criteriaValues[index - 1] > criteriaValues[index] ) {
            swap(&criteriaValues[index], &criteriaValues[index - 1]);
            swapRows(m,index - 1, index);
            index--;
        }
    }
}

void sortByDistance(Matrix m) {
    insertionSortRowsMatrixByRowCriteriaF(m,getDistance);
}

int main() {
    Matrix m1 = createMatrixFromArray((int[]) {
            4,1,
            0,3
    }, 2,2);

    sortByDistance(m1);

    outputMatrix(m1);

    freeMatrix(m1);
    printf("\n");

    Matrix m2 = createMatrixFromArray((int[]) {
            7,1,5,
            8,3,7
    }, 2,3);

    sortByDistance(m2);

    outputMatrix(m2);
    freeMatrix(m2);
    printf("\n");

    Matrix m3 = createMatrixFromArray((int[]) {
            4,1,7,
            0,3,8,
            7,4,1
    }, 3,3);

    sortByDistance(m3);

    outputMatrix(m3);

    freeMatrix(m3);
    printf("\n");


    Matrix m4 = createMatrixFromArray((int[]) {
            4,1,7,
    }, 1,3);

    sortByDistance(m4);

    outputMatrix(m4);

    freeMatrix(m4);
    printf("\n");
}
