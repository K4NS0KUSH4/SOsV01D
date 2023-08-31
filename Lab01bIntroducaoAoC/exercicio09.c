#include <stdio.h>
#include <stdlib.h>

void switch2Abs(int rows, int columns, int matrix[rows][columns]) {
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < columns; j++) {
			if(matrix[i][j] < 0) {
				matrix[i][j] = abs(matrix[i][j]);
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
	int matriz[3][3] = {{1, 2, -3}, {-4, -5, 6}, {-7, 8, -9}};
	printf("|----------//---------- EXERCÍCIO 09 ----------//----------|\n");
	printf("Matriz original\n");
	print2dArray(3, 3, matriz);
	printf("\nMudando negativos para seu módulo:\n");
	switch2Abs(3, 3, matriz);
	print2dArray(3, 3, matriz);
	printf("|----------//---------- //----------// ----------//---------|\n\n");

	return 0;
}
