#pragma once

#include "Sinal.h"

class Derivador {
	public:
		Derivador();
		virtual ~Derivador();
		Sinal* processar(Sinal* sinalIN);
};
