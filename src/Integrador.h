#ifndef INTEGRADOR_H
#define INTEGRADOR_H

#include "CircuitoSISO.h"
#include "Sinal.h"

class Integrador : public CircuitoSISO {
	public:
		Integrador();
		virtual ~Integrador();
		Sinal* processar(Sinal* sinalIN);
};

#endif
