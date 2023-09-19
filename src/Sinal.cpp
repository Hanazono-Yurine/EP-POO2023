#include "Sinal.h"
#include "Grafico.h"

Sinal::Sinal(double *sequencia, int comprimento):
comprimento(comprimento), sequencia(new double[comprimento]) {

}

Sinal::~Sinal() {
	delete[] this->sequencia;
}

double* Sinal::getSequencia() {
	return this->sequencia;
}

int Sinal::getComprimento() {
	return this->comprimento;
}

void Sinal::imprimir(std::string nomeDoSinal) {
	Grafico graph = Grafico(nomeDoSinal, this->sequencia, this->comprimento);
	graph.plot();
}
