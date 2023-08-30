#include <stdio.h>

float getMediaAproveitamento(float N1, float N2, float N3, float mediaExs) {
	return (N1 + 2*N2 + 3*N3 + mediaExs)/7;
}

char getConceito(float mediaAproveitamento) {
	if(mediaAproveitamento >= 9) {
		return 'A';
	}
	if(mediaAproveitamento >= 7.5 && mediaAproveitamento < 9) {
		return 'B';
	}
	if(mediaAproveitamento >= 6 && mediaAproveitamento < 7.5) {
		return 'C';
	}
	if(mediaAproveitamento >= 4 && mediaAproveitamento < 6) {
		return 'D';
	}
	return 'E';
}

int main(void) {
	float N1 = 9.5, N2 = 7.5, N3 = 8.0, ME = 7.0;
	float mediaAproveitamento = getMediaAproveitamento(N1, N2, N3, ME);
	char conceito = getConceito(mediaAproveitamento);

	printf("|----------//---------- EXERCÍCIO 02 ----------//----------|\n");
	printf("N1: 9.5 | N2: 7.5 | N3: 8.0 | ME: 7.0\n");

	printf("Média obtida: %.2f | Conceito: %c\n", mediaAproveitamento, conceito);

	return 0;
}
