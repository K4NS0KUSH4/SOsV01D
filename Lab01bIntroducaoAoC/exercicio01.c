#include <stdio.h>

int lowestValue(int rowsColumns, int matrix[rowsColumns][rowsColumns]) {
	int lowest = matrix[0][0];
	int line = 0;

	for(int i = 0; i < rowsColumns; i++) {
		for(int j = 0; j < rowsColumns; j++) {
			if(lowest > matrix[i][j]) {
				lowest = matrix[i][j];
				line = i;
			}
		}
	}

	return line;
}

int main(void) {
	printf("|----------//---------- EXERCÍCIO 01 ----------//----------|\n");

	int threeSqrdMatrix[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
	int fourSqrdMatrix[4][4] = {{1, 2, 3, 4}, {0, 9, 7, 8}, {1, 3, 6, 5}, {9, 9, 3, 5}};
	
	int lowestValueLine = lowestValue(3, threeSqrdMatrix);
	printf("Test 01\nLine with lowest value: %d.\n", lowestValueLine);
	
	lowestValueLine = lowestValue(4, fourSqrdMatrix);
	printf("\nTest 02\nLine with lowest value: %d.\n", lowestValueLine);

	printf("|---------//---------- //----------// ----------//----------|\n\n");
	
	return 0;
}
