#include <stdio.h>
#include <string.h>

typedef struct {
	char name[50];
	int age;
	float weight;
	float height;
} Person;

void printPerson(Person bud) {
	printf("Nome: %s | Idade: %d | Peso: %.2f | Altura: %.2f\n", bud.name, bud.age, bud.weight, bud.height);
} 

int main(void) {
	printf("|----------//---------- EXERCÍCIO 07 ----------//----------|\n");
	Person camaradas[3];	
	Person camarada01, camarada02, camarada03;
	
	strcpy(camarada01.name, "Pedro");
	camarada01.age = 19;
	camarada01.weight = 75.00;
	camarada01.height = 1.87;

	strcpy(camarada02.name, "Lucas");
	camarada02.age = 20;
	camarada02.weight = 86.75;
	camarada02.height = 1.95;

	strcpy(camarada03.name, "Paulo");
	camarada03.age = 25;
	camarada03.weight = 70.55;
	camarada03.height = 1.75;

	camaradas[0] = camarada01;
	camaradas[1] = camarada02;
	camaradas[2] = camarada03;

	for(int i = 0; i < 3; i++) {
		printPerson(camaradas[i]);
	}

	printf("|----------//---------- //----------// ----------//----------|\n\n");

	return 0;
}
