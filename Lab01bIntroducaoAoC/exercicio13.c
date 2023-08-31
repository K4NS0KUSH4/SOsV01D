#include <stdio.h>
#include <string.h>

void removeChar(char string[], int index) {
	for(int i = index; i < strlen(string); i++) {
		string[i] = string[i+1];
	}
}

int main(void) {
	char string[] = "Episode 25: The beast that shouted 'I' at the heart of the world";
	printf("|----------//---------- EXERCÍCIO 13 ----------//----------|\n");
	printf("String teste: %s\n", string);
	printf("Caractere na posição 25 (string[25]): %c\n", string[25]);
	removeChar(string, 25);
	printf("String após remoção do caractere: %s\n", string);
	printf("|---------//---------- //----------// ----------//----------|\n\n");
	
	return 0;
}
