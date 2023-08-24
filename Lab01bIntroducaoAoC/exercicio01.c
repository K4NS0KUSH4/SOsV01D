#include <stdio.h>
#include <stdlib.h>

int lowestValueLine(int rows, int columns, int matrix[rows][columns]) {
	int lowestValue = matrix[0][0];
	int valueLine = 0;

	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < columns; j++) {
			if(lowestValue > matrix[i][j]) {
				lowestValue = matrix[i][j];
				valueLine = i;
			}
		}
	}

	return valueLine;
}

int main(void) {
	int testMatrix[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
	int theLine = lowestValueLine(3, 3, testMatrix);
	printf("Line with lowest value: %d\n", theLine);

	return 0;
}
