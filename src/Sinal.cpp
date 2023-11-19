#include <stdexcept>
#include "Sinal.h"
#include "Grafico.h"

Sinal::Sinal(double *sequencia, int comprimento):
comprimento(comprimento), sequencia(new double[comprimento]) {
	if (comprimento <= 0)
		throw new std::invalid_argument("Comprimento must be at least 1");

	for (int i = 0; i < comprimento; i++) {
		this->sequencia[i] = sequencia[i];
	}
}

Sinal::Sinal(double constante, int comprimento):
comprimento(comprimento), sequencia(new double[comprimento]) {
	if (comprimento <= 0)
		throw new std::invalid_argument("Comprimento must be at least 1");

	for (int i = 0; i < comprimento; i++) {
		this->sequencia[i] = constante;
	}
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
