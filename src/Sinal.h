#pragma once

#include <string>

class Sinal {
	public:
		Sinal(double *sequencia, int comprimento);
		virtual ~Sinal();
		double *getSequencia();
		int getComprimento();
		void imprimir(std::string nomeDoSinal);
};
