/* This code was developed by Pedro Henrique Araujo Farias.
 * Feel free to use. It's totally open source. */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int matrix[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};

int array[3] = {1, 2, 3};

int result[3];

void* Pth_mat_vect(void* threadNum) {
    long resultElement = (long) threadNum;
    int arrayLength = sizeof(array)/sizeof(int);

    result[resultElement] = 0;
    for(int i = 0; i < arrayLength; i++) {
        result[resultElement] += matrix[resultElement][i] * array[i];
    }

    return NULL;
}

void printMatrix(int argLines, int argColumns, int argMatrix[argLines][argColumns]) {
    for(int i = 0; i < argLines; i++) {
        for(int j = 0; j < argColumns; j++) {
            printf("%d ", argMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrixLines = sizeof(matrix)/sizeof(matrix[0]);
    int matrixColumns = sizeof(matrix[0])/sizeof(int);
    pthread_t* threadArray = malloc(matrixLines * sizeof(pthread_t));

    for(long line = 0; line < matrixLines; line++) {
        pthread_create(&threadArray[line], NULL, Pth_mat_vect, (void*) line);
    }

    for(int i = 0; i < matrixLines; i++) {
        pthread_join(threadArray[i], NULL);
    }

    printMatrix(matrixLines, matrixColumns, result);

    return 0;
}