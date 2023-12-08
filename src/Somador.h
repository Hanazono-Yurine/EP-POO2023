#ifndef SOMADOR_H
#define SOMADOR_H

#include "CircuitoMISO.h"
#include "Sinal.h"

class Somador : public CircuitoMISO {
	public:
		Somador();
		virtual ~Somador();
		Sinal* processar(Sinal* sinalIN, Sinal* sinalIN2);
};

#endif
