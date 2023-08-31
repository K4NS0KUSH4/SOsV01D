#include <stdio.h>
#include <string.h>

int indexOfChar(char item, char string[]) {
	int count = 0;

	while(string[count] != '\0') {
		if(string[count] == item) {
			return count;
		}

		count++;
	}

	return -1;
}

int main(void) {
	printf("|----------//---------- EXERCÍCIO 12 ----------//----------|\n");
	char toBeFound = 'v';
	char evangelion[] = "Neon Genesis Evangelion";
	printf("String: Neon Genesis Evangelion | Char: v\n");
	printf("Posição do caractere: %d\n", indexOfChar(toBeFound, evangelion));
	printf("|----------//---------- //----------// ----------//----------|\n\n");

	return 0;
}
