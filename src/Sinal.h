#ifndef SINAL_H
#define SINAL_H

// Eu uso o '#pragma once', mas por forças externas, acabei tendo que usar essa versão arcaica

#include <string>

class Sinal {
	public:
		Sinal(double *sequencia, int comprimento);
		virtual ~Sinal();
		double *getSequencia();
		int getComprimento();
		void imprimir(std::string nomeDoSinal);
	
	private:
		double *sequencia = nullptr;
		int comprimento = 0;
};

#endif
