#include "ModuloRealimentado.h"
#include "Sinal.h"
#include "Amplificador.h"
#include "Integrador.h"

void menu();
void test();

int main() {
	menu();
	test();
	return 0;
}

void menu() {

}

void test() {
	ModuloRealimentado test = ModuloRealimentado(0.3);
	double justatest[20] = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
	Sinal *finalTest = test.processar(new Sinal(justatest, 20));
	finalTest->imprimir("test");
}
