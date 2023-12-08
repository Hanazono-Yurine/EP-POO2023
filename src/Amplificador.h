#ifndef AMPLIFICADOR_H
#define AMPLIFICADOR_H

#include "CircuitoSISO.h"
#include "Sinal.h"

class Amplificador : public CircuitoSISO {
	public:
		Amplificador(double ganho);
		virtual ~Amplificador();
		Sinal* processar(Sinal* sinalIN);
		void setGanho(double ganho);
		double getGanho();

	private:
		double ganho = 0.0;
};

#endif
