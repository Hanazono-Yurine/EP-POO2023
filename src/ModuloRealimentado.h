#ifndef MODULOREALIMENTADO_H
#define MODULOREALIMENTADO_H

#include "Modulo.h"
#include "ModuloEmSerie.h"
#include "Sinal.h"

class ModuloRealimentado : public Modulo {
	public:
		ModuloRealimentado();
		virtual ~ModuloRealimentado();
		virtual void adicionar(CircuitoSISO *circ);
		Sinal* processar(Sinal* sinalIN);
	private:
		ModuloEmSerie *piloto = nullptr;
};

#endif
