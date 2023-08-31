#include <stdio.h>
#include <stdlib.h>

int** transpose(int rows, int columns, int matrix[rows][columns]) {
	int** transpose = (int**) calloc(columns, sizeof(int*));
	for(int i = 0; i < rows; i++) {
		transpose[i] = (int*) calloc(rows, sizeof(int));
	}

	for(int j = 0; j < rows; j++) {
		for(int k = 0; k < columns; k++) {
			transpose[k][j] = matrix[j][k];
		}
	}

	return transpose;
}

int main(void) {
	int matrixA[2][3] = {{1, 2, 3}, {4, 5, 6}};
	int** matrixB = transpose(2, 3, matrixA);

	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 2; j++) {
			printf("%d ", matrixB[i][j]);
		}

		printf("\n");
	}

	for(int l = 0; l < 3; l++) {
		free(matrixB[l]);
	}

	free(matrixB);

	return 0;	
}
