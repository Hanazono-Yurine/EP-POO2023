#ifndef PILOTO_H
#define PILOTO_H

#include "Sinal.h"

class Piloto {
	public:
		Piloto(double ganho);
		virtual ~Piloto();
		Sinal* processar(Sinal* sinalIN);
	private:
		double ganho = 0.0;
};

#endif
