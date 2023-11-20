#include "Circuito.h"
#include <iostream>

Circuito::Circuito() { 
	this->assignNewId();
}

Circuito::~Circuito() {
}

int Circuito::getID() {
	return this->currentID;
}

void Circuito::imprimir() {
	std::cout << "Circuito com ID " << this->currentID << std::endl;
}

int Circuito::getUltimoID() {
	return Circuito::lastAssignedID;
}

void Circuito::assignNewId() {
	Circuito::lastAssignedID = getUltimoID() + 1;
	this->currentID = Circuito::lastAssignedID;
}

int Circuito::lastAssignedID = 0;
