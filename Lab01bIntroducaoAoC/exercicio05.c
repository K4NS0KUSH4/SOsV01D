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
	int bidimensionalArray[2][3] = {{9, 8, 7}, {6, 5, 4}};
	printMatrix(2, 3, bidimensionalArray);
	printf("\nMultiplicando os elementos da segunda linha por 3:\n");
	lineTimesMatrix(3, 2, 2, 3, bidimensionalArray);
	printMatrix(2, 3, bidimensionalArray);
	printf("|----------//---------- //----------// ----------//----------|\n\n");

	return 0;
}	
