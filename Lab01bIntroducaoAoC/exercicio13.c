#include <stdio.h>
#include <string.h>

void removeChar(char string[], int index) {
	int count = 0;
	
	while(count < index) {
		count++;
	}

	for(int i = count; i < strlen(string); i++) {
		string[i] = string[i+1];
	}
}

int main(void) {
	char string[] = "Pedro";
	printf("|----------//---------- EXERCÍCIO 13 ----------//----------|\n");
	printf("String teste: %s\n", string);
	printf("Caractere na posição 2 (string[2]): %c\n", string[2]);
	removeChar(string, 2);
	printf("String após remoção do caractere: %s\n", string);
	printf("|---------//---------- //----------// ----------//----------|\n\n");
	
	return 0;
}
