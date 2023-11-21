#pragma once

#include "Circuito.h"
#include "Sinal.h"

class CircuitoSISO : public Circuito {
	public:
		CircuitoSISO();
		virtual ~CircuitoSISO();
		virtual Sinal *processar(Sinal *sinalIN) = 0;
};
