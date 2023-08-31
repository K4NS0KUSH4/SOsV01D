#include <stdio.h>
#include <stdlib.h>

int** transpose(int rows, int columns, int matrix[rows][columns]) {
	int** transpose = (int**) calloc(columns, sizeof(int*));
    	for(int i = 0; i < columns; i++) {
        	transpose[i] = (int*) calloc(rows, sizeof(int));
    	}

    	for(int m = 0; m < rows; m++) {
        	for(int n = 0; n < columns; n++) {
            	transpose[n][m] = matrix[m][n];
        	}
    	}

    	return transpose;
}

int main(void) {
	printf("|----------//---------- EXERCÍCIO 08 ----------//----------|\n");
    	int matrix[2][3] = {{1, 2, 3}, {4, 5, 6}};

	printf("Matriz original\n");

	for(int a = 0; a < 2; a++) {
		for(int b = 0; b < 3; b++) {
			printf("%d ", matrix[a][b]);
		}
		
		printf("\n");
	}

    	int** transposeMatrix = transpose(2, 3, matrix);

	printf("\nMatriz transposta\n");

    	for(int i = 0; i < 3; i++) {
        	for(int j = 0; j < 2; j++) {
            	printf("%d ", transposeMatrix[i][j]);
        	}

        	printf("\n");
    	}

    	for(int p = 0; p < 3; p++) {
        	free(transposeMatrix[p]);
    	}

    	free(transposeMatrix);

	printf("|----------//---------- //----------// ----------//----------|\n\n");

    	return 0;
}
