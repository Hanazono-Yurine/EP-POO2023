#include "ModuloRealimentado.h"
#include "Sinal.h"
#include "Amplificador.h"
#include "Integrador.h"

#define MAX_STEPS 60

void menu();
void test();

int main() {
	//Bom dia
	menu();
	test();
	return 0;
}

void menu() {

}

void test() {
	ModuloRealimentado test = ModuloRealimentado(0.2);
	double justatest[MAX_STEPS];
	for (int i = 0; i < MAX_STEPS; i++) {
		justatest[i] = 5;
	}
	Sinal *finalTest = test.processar(new Sinal(justatest, MAX_STEPS));
	finalTest->imprimir("test");
}
