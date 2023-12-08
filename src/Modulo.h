#pragma once

#include "CircuitoSISO.h"
#include <list>

class Modulo : public CircuitoSISO {
	public:
		Modulo();
		virtual ~Modulo();
		virtual void adicionar(CircuitoSISO *circ);
		virtual std::list <CircuitoSISO*> *getCircuitos();
		void imprimir();
	private:
		std::list<CircuitoSISO *> *circuitList;
};
