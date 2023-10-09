#include "ModuloRealimentado.h"
#include "Sinal.h"
#include "Amplificador.h"
#include "Integrador.h"

const int maxSteps = 60;
// No PDF esta falando que nao pode usar outros defines,
// e eu me recuso a usar numeros magicos no meu codigo,
// por isso essa variavel constante

void menu();
void test();
void teste();

int main() {
	//Bom dia
	menu();
	//teste();
	return 0;
}

void test() {
	ModuloRealimentado test = ModuloRealimentado(0.2);
	double justatest[maxSteps];
	for (int i = 0; i < maxSteps; i++) {
		justatest[i] = 5;
	}
	Sinal *finalTest = test.processar(new Sinal(justatest, maxSteps));
	finalTest->imprimir("test");
}
