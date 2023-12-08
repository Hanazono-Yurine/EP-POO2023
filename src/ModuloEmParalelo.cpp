#include <list>
#include <stdexcept>
#include "ModuloEmParalelo.h"
#include "CircuitoSISO.h"
#include "Sinal.h"
#include "Somador.h"


ModuloEmParalelo::ModuloEmParalelo() {

}

ModuloEmParalelo::~ModuloEmParalelo() {

}

Sinal *ModuloEmParalelo::processar(Sinal *sinalIN) {
	if (this->getCircuitos()->size() < 1)
		throw new std::logic_error("List has to have at least one item");

	std::list<CircuitoSISO*>::iterator it = this->getCircuitos()->begin();
	Somador sum = Somador();
	Sinal *sinal = (*it++)->processar(sinalIN);

	while (it != this->getCircuitos()->end()) {
		sinal = sum.processar(sinal, (*it++)->processar(sinalIN));
	}

	return sinal;
}

