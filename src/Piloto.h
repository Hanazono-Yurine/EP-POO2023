#pragma once

#include "Sinal.h"

class Piloto {
	public:
		Piloto(double ganho);
		virtual ~Piloto();
		Sinal* processar(Sinal* sinalIN);
};
