#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "C:/untitled/libs/data_structures/Matrix/Matrix.h"

void outputArray(int *a, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d, ", a[i]);
    }
}


double getVectorLength(int *a, int n) {
    double len = 0;
    for (int i = 0; i < n; i++)
        len += a[i] * a[i];

    return sqrt(len);
}

double getScalarProduct(int *a, int *b, int n) {
    return (a[0]*b[0] + a[1] * b[1] + a[2] * b[2]);
}


double getCosine(int *a, int *b, int n) {
    return getScalarProduct(a,b,n) / (getVectorLength(a,n) + getVectorLength(b,n));
}

int getVectorIndexWithMaxAngle(Matrix m, int *b) {
    double *arrayCos = (double *)malloc(sizeof(double) * m.nRows);
    for (int i = 0; i < m.nRows; i++)
        arrayCos[i] = getCosine(m.values[i], b,m.nCols);

    double maxCos = 0;
    int index = 0;
    for (int i = 0; i < m.nRows; i++) {
        if (maxCos < arrayCos[i]) {
            maxCos = arrayCos[i];
            index = i;
        }
    }

    return index;
}

int main() {
    Matrix m1 = createMatrixFromArray((int[]) {
            1, 1, 1,
            6, 3, 3,
            10, 1, 0
    }, 3, 3);

    int v1[3] = {1, 1, 1};
    int index1 = getVectorIndexWithMaxAngle(m1,v1);
    printf("vector (ROW = %d ) ", index1);
    printf(" = ");
    printf("[ ");

    outputArray( m1.values[index1], m1.nRows);

    printf("]");

    freeMatrix(m1);
    printf("\n");

    Matrix m2 = createMatrixFromArray((int[]) {
            4, 1, 1,6,
            6, 3, 3,1,
            10, 1, 0,5
    }, 3, 4);

    int v2[3] = {1, 0, 0};
    int index2 = getVectorIndexWithMaxAngle(m2,v2);
    printf("vector (ROW = %d ) ", index2);
    printf(" = ");
    printf("[ ");

    outputArray( m2.values[index2], m2.nRows);

    printf("]");

    freeMatrix(m2);
    printf("\n");

    Matrix m3 = createMatrixFromArray((int[]) {
            1, 0, 0,
            0, 1, 0,
            0, 0, 1,
    }, 3, 3);

    int v3[3] = {0, 0, 9};
    int index3 = getVectorIndexWithMaxAngle(m3,v3);
    printf("vector (ROW = %d ) ", index3);
    printf(" = ");
    printf("[ ");

    outputArray( m3.values[index1], m3.nRows);

    printf("]");

    freeMatrix(m3);
    printf("\n");

    return 0;

}

