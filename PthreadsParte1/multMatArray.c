/* This code was developed by Pedro Henrique Araujo Farias.
 * Feel free to use. It's totally open source. */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int matrix[5][5] = {
    {1, 2, 3, 4, 5},
    {2, 3, 4, 5, 6},
    {3, 4, 5, 6, 7},
    {4, 5, 6, 7, 8},
    {5, 6, 7, 8, 9}
};

int array[5] = {1, 2, 3, 4, 5};

int result[5];

void* Pth_mat_vect(void* threadNum) {
    long resultElement = (long) threadNum;
    int arrayLength = sizeof(array)/sizeof(int);

    result[resultElement] = 0;
    for(int i = 0; i < arrayLength; i++) {
        result[resultElement] += matrix[resultElement][i] * array[i];
    }

    printf("Elemento de índice %ld calculado pela Thread %ld: %d\n", resultElement, threadNum, result[resultElement]);

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

    printf("Matriz exemplo: \n");
    printMatrix(matrixLines, matrixColumns, matrix);
    printf("\n");

    printf("Vetor exemplo: ");
    for(int l = 0; l < matrixLines; l++) {
        printf("%d ", array[l]);
    }
    printf("\n\n");

    for(long line = 0; line < matrixLines; line++) {
        pthread_create(&threadArray[line], NULL, Pth_mat_vect, (void*) line);
    }

    for(int i = 0; i < matrixLines; i++) {
        pthread_join(threadArray[i], NULL);
    }

    printf("\nVetor resultante da multiplicação matriz-vetor: ");
    for(int k = 0; k < matrixLines; k++) {
	    printf("%d ", result[k]);
    }
    printf("\n");

    free(threadArray);

    return 0;
}
