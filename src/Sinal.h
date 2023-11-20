#ifndef SINAL_H
#define SINAL_H

// Eu uso o '#pragma once', mas por forças externas, acabei tendo que usar essa versão arcaica

#include <string>

class Sinal {
	public:
		Sinal(double *sequencia, int comprimento);
		Sinal(double constante, int comprimento);
		virtual ~Sinal();
		double *getSequencia();
		int getComprimento();
		void imprimir(std::string nomeDoSinal);
		void imprimir();
		void imprimir(int tamanho);
	
	private:
		double *sequencia = nullptr;
		int comprimento = 0;
		void imprimirListForm(int tamanho);
};

#endif
