/* This code was developed by Pedro Henrique Araujo Farias.
 * Feel free to use. It's totally open source. */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int matrix[3][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12}
};

int array[4] = {1, 2, 3, 4};
int matrixLines = sizeof(matrix)/sizeof(matrix[0]);
int matrixColumns = sizeof(matrix[0])/sizeof(int);
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
    pthread_t* threadArray = malloc(matrixLines * sizeof(pthread_t));
    int* result = malloc(matrixLines * sizeof(int));

    for(long line = 0; line < matrixLines; line++) {
        pthread_create(&threadArray[line], NULL, Pth_mat_vect, (void*) line);
    }

    for(int i = 0; i < matrixLines; i++) {
        pthread_join(threadArray[i], NULL);
    }

    for(int k = 0; k < matrixColumns; k++) {
	printf("%d ", result[k]);
    }

    return 0;
}
