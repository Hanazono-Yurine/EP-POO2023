#include <list>
#include <stdexcept>
#include "ModuloEmSerie.h"
#include "CircuitoSISO.h"
#include "Sinal.h"


ModuloEmSerie::ModuloEmSerie() {

}

ModuloEmSerie::~ModuloEmSerie() {

}

Sinal *ModuloEmSerie::processar(Sinal *sinalIN) {
	if (this->getCircuitos()->size() < 1)
		throw new std::logic_error("List has to have at least one item");

	std::list<CircuitoSISO*>::iterator it = this->getCircuitos()->begin();
	Sinal *sinal = (*it++)->processar(sinalIN);

	while (it != this->getCircuitos()->end()) {
		sinal = (*it)->processar(sinal);
	}

	return sinal;
}
