#include <list>
#include <iostream>
#include "CircuitoSISO.h"
#include "Modulo.h"

Modulo::Modulo() : circuitList(new std::list<CircuitoSISO *>){

}
	
Modulo::~Modulo() {
	delete this->circuitList;
}
	
void Modulo::adicionar(CircuitoSISO *circ) {
	this->circuitList->push_back(circ);
}
	
std::list<CircuitoSISO*> *Modulo::getCircuitos() {
	return this->circuitList;
}

void Modulo::imprimir() {
	std::cout << "Modulo com ID " << this->getID() << " e: " << std::endl;

	std::list<CircuitoSISO *>::iterator it = this->circuitList->begin();
	while (it != this->circuitList->end()) {
		(*it)->imprimir();
		it++;
	}
	std::cout << "--" << std::endl;
}
