#include "Modulo.h"
#include "PersistenciaDeModulo.h"
void menu();
void test();

int main() {
	menu();
	//test();
	return 0;
}

void test() {
	PersistenciaDeModulo backup = PersistenciaDeModulo("abobrinha.txt");

	Modulo *modulo = backup.lerDeArquivo();

	modulo->imprimir();
}
