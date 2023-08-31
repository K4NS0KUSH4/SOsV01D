#include <stdio.h>

void sumL1toL2(int rows, int columns, int matrix[rows][columns]) {
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < columns; j++) {
			if(i == 1) {
				matrix[i][j] = matrix[i][j] + matrix[i - 1][j];
			}
		}
	}
}

void prodL1toL2(int rows, int columns, int matrix[rows][columns]) {
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < columns; j++) {
			if(i == 1) {
				matrix[i][j] = matrix[i][j] * matrix[i - 1][j];
			}
		}
	}
}

void print2dArray(int rows, int columns, int matrix[rows][columns]) {
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < columns; j++) {
			printf("%d ", matrix[i][j]);
		}

		printf("\n");
	}
}

int main(void) {
	printf("|----------//---------- EXERCÍCIO 11 ----------//----------|\n");
	int matrizA[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
	int matrizB[3][4] = {{12, 11, 10, 9}, {8, 7, 6, 5}, {4, 3, 2, 1}};
	printf("Matriz A original\n");
	print2dArray(3, 4, matrizA);
	printf("\nArmazenando a soma dos elementos de L1 e L2 em L2\n");
	sumL1toL2(3, 4, matrizA);
	print2dArray(3, 4, matrizA);
	printf("\nMatriz B original\n");
	print2dArray(3, 4, matrizB);
	printf("\nArmazenando o produto dos elementos de L1 e L2 em L2\n");
	prodL1toL2(3, 4, matrizB);
	print2dArray(3, 4, matrizB);
	printf("|----------//---------- //----------// ----------//----------|\n\n");

	return 0;
}
