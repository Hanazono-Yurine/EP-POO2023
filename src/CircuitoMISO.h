#pragma once

#include "Circuito.h"
#include "Sinal.h"

class CircuitoMISO : public Circuito {
	public:
		CircuitoMISO();
		virtual ~CircuitoMISO();
		virtual Sinal *processar(Sinal *sinalIN1, Sinal *sinalIN2) = 0;
};
