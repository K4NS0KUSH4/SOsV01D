#include <stdio.h>
#include <string.h>

void insertChar(char string[], char letter, int index) {
	for(int i = strlen(string); i >= index; i--) {
		string[i + 1] = string[i];
	}

	string[index] = letter;
}

int main(void) {
	printf("|----------//---------- EXERCÍCIO 14 ----------//----------|\n");
	char string[100] = "The beast that shouted 'I' at the heart of the world";
	printf("String: %s\n", string);
	printf("Adicionando caractere 't' na posição 25 (string[25])\n");
	insertChar(string, 't', 25);
	printf("Resultado: %s\n", string);
	printf("|----------//---------- //----------// ----------//----------|\n\n");

	return 0;
}
