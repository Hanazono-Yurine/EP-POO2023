#pragma once

#include "Sinal.h"

class Somador {
	public:
		Somador();
		virtual ~Somador();
		Sinal* processar(Sinal* sinalIN, Sinal* sinalIN2);
};
