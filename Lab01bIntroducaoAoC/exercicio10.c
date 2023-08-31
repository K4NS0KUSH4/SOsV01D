#include <stdio.h>

void lineTimesMatrix(int num, int line, int rows, int columns, int matrix[rows][columns]) {
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < columns; j++) {
			if(line - 1 == i) {
				matrix[i][j] = matrix[i][j] * num;
			}
		}
	}
}

void columnTimesMatrix(int num, int column, int rows, int columns, int matrix[rows][columns]) {
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < columns; j++) {
			if(column - 1 == j) {
				matrix[i][j] = matrix[i][j] * num;
			}
		}
	}
}

void printMatrix(int rows, int columns, int matrix[rows][columns]) {
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < columns; j++) {
			printf("%d ", matrix[i][j]);
		}

		printf("\n");
	}
}

int main(void) {
	printf("|----------//---------- EXERCÍCIO 05 ----------//----------|\n");
	int bidimensionalArrayA[2][3] = {{9, 8, 7}, {6, 5, 4}};
	int bidimensionalArrayB[4][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
	printf("Matriz original\n");
	printMatrix(2, 3, bidimensionalArrayA);
	printf("\nMultiplicando os elementos da segunda linha por 3:\n");
	lineTimesMatrix(3, 2, 2, 3, bidimensionalArrayA);
	printMatrix(2, 3, bidimensionalArrayA);
	printf("\nMatriz original\n");
	printMatrix(4, 3, bidimensionalArrayB);
	printf("\nMultiplicando os elementos da terceira coluna por 5:\n");
	columnTimesMatrix(5, 3, 4, 3, bidimensionalArrayB);
	printMatrix(4, 3, bidimensionalArrayB);
	printf("|----------//---------- //----------// ----------//----------|\n\n");

	return 0;
}	
