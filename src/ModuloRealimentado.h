#pragma once

#include "Sinal.h"

class ModuloRealimentado {
	public:
		ModuloRealimentado(double ganho);
		virtual ~ModuloRealimentado();
		Sinal* processar(Sinal* sinalIN);
};
