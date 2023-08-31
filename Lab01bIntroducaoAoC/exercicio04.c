#include <stdio.h>
#include <string.h>

int main(void) {
	char stringA[] = "Pedro", stringB[] = "Yasmin";

	printf("|----------//---------- EXERCÍCIO 04 ----------//----------|\n");

	if(strcmp(stringA, stringB) >= 0) {
		printf("%s\n%s\n", stringB, stringA);
	} else {
		printf("%s\n%s\n", stringA, stringB);
	}

	printf("|----------//---------- //----------// ----------//----------|\n\n");

	return 0;
}
