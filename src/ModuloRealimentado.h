#ifndef MODULOREALIMENTADO_H
#define MODULOREALIMENTADO_H

#include "Modulo.h"
#include "ModuloEmSerie.h"
#include "Sinal.h"

class ModuloRealimentado : public Modulo {
	public:
		ModuloRealimentado();
		virtual ~ModuloRealimentado();
		void adicionar(CircuitoSISO *circ);
		std::list<CircuitoSISO*> *getCircuitos();
		Sinal* processar(Sinal* sinalIN);
	private:
		ModuloEmSerie *piloto = nullptr;
};

#endif
