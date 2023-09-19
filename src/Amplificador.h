#pragma once

#include "Sinal.h"

class Amplificador {
	public:
		Amplificador(double ganho);
		virtual ~Amplificador();
		Sinal* processar(Sinal* sinalIN);
		void setGanho(double ganho);
		double getGanho();
};
