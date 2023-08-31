#include <stdio.h>

void printSequence(int length, int array[length]) {
	for(int i = 0; i < length/2 + 1; i++) {
		for(int j = i; j < length - i; j++) {
			printf("%d ", array[j]);
		}

		printf("\n");
	}
}

int main(void) {
	printf("|----------//---------- EXERCÍCIO 03 ----------//----------|\n");
	int arrayA[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int arrayB[7] = {1, 2, 3, 4, 5, 6, 7};
	printf("Teste 01\n");
	printSequence(9, arrayA);
	printf("\nTeste 02\n");
	printSequence(7, arrayB);
	printf("|----------//---------- //----------// ----------//----------|\n\n");

	return 0;
}
