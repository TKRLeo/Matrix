#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "math.h"
#include "C:/untitled/libs/data_structures/Matrix/Matrix.h"

int* getSumCols(Matrix m) {
    int *sum = (int*)calloc(sizeof(int) , m.nCols);
    for (int j = 0; j < m.nCols; j++) {
        for (int i = 0; i < m.nRows; i++)
            sum[j] += m.values[i][j];
    }

    return sum;
}
int getNSpecialElement(Matrix m) {
    int specialCount = 0;
    int *sum = getSumCols(m);

    for (int j = 0, i = 0; j < m.nCols; i++) {
        if (m.values[i][j] > (sum[j] - m.values[i][j])) {
            specialCount++;
            j++;
            i = 0;
        } else if (i + 1 == m.nRows) {
            i = -1;
            j++;
        }
    }

    free(sum);
    return specialCount;
}


int main() {
    Matrix m1 = createMatrixFromArray((int[]) {
            100,100,0,0,
            100,5,0,80,
            12,2,1,2
    }, 3,4);
    printf("%d",getNSpecialElement(m1));

    freeMatrix(m1);

    printf("\n");

    Matrix m2 = createMatrixFromArray((int[]) {
            100,100,0,0,
            100,5,0,80,
            12,2,1,2,5,
            1,7,8,9,0
    }, 4,4);
    printf("%d",getNSpecialElement(m2));

    freeMatrix(m2);

    printf("\n");

    Matrix m3 = createMatrixFromArray((int[]) {
            1,0,0,0,
            0,1,0,0,
            0,0,1,0,
            0,0,0,1
    }, 4,4);
    printf("%d",getNSpecialElement(m3));

    freeMatrix(m3);

    printf("\n");
}

