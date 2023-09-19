#pragma once

#include "Sinal.h"

class Piloto {
	public:
		Piloto(double ganho);
		virtual ~Piloto();
		Sinal* processar(Sinal* sinalIN);
	private:
		double ganho = 0.0;
};
