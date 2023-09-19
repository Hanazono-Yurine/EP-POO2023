#pragma once

#include "Sinal.h"

class Integrador {
	public:
		Integrador();
		virtual ~Integrador();
		Sinal* processar(Sinal* sinalIN);
};
