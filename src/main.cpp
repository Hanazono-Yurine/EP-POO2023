#include "Derivador.h"
#include "Modulo.h"
#include "ModuloEmParalelo.h"
#include "ModuloEmSerie.h"
#include "ModuloRealimentado.h"
#include "PersistenciaDeModulo.h"
#include "Sinal.h"
#include "Amplificador.h"
#include "Integrador.h"
#include <algorithm>
#include <iostream>

const int maxSteps = 60;

void menu();
void test();
void teste();

int main() {
	//menu();
	test();
	return 0;
}

void test() {
	PersistenciaDeModulo backup = PersistenciaDeModulo("test.txt");

	Modulo *serie = backup.lerDeArquivo();

	serie->imprimir();

}
