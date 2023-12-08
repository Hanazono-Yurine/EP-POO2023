#include "PersistenciaDeModulo.h"
#include "Amplificador.h"
#include "Integrador.h"
#include "Derivador.h"
#include "Modulo.h"
#include "ModuloEmSerie.h"
#include "ModuloEmParalelo.h"
#include "ModuloRealimentado.h"
#include <fstream>
#include <ostream>
#include <string>

PersistenciaDeModulo::PersistenciaDeModulo(std::string nomeDoArquivo) : fileName(nomeDoArquivo) {
}

PersistenciaDeModulo::~PersistenciaDeModulo() {
}

void PersistenciaDeModulo::salvarEmAquivo(Modulo *mod) {
	std::ofstream file = std::ofstream(this->fileName);

	this->writeModuloToFile<Modulo>(mod, file);

	file.close();
}

template<typename T> void PersistenciaDeModulo::writeModuloToFile(T *module, std::ofstream &file) {
	std::list<CircuitoSISO *>::iterator it = module->getCircuitos()->begin();

		if (dynamic_cast<ModuloEmSerie*>( module )) {
			this->writeCircuitToFile(file, 'S');
		} else if (dynamic_cast<ModuloRealimentado*>( module )) {
			this->writeCircuitToFile(file, 'R');
		} else if (dynamic_cast<ModuloEmParalelo*>( module )) {
			this->writeCircuitToFile(file, 'P');
		}

	while (it != module->getCircuitos()->end()) {
		if (dynamic_cast<ModuloEmSerie*>( (*it) ) != nullptr) {
			this->writeModuloToFile<ModuloEmSerie>(dynamic_cast<ModuloEmSerie*>((*it)), file);
		} else if (dynamic_cast<ModuloRealimentado*>( (*it) )) {
			this->writeModuloToFile<ModuloRealimentado>(dynamic_cast<ModuloRealimentado*>((*it)), file);
		} else if (dynamic_cast<ModuloEmParalelo*>( (*it) )) {
			this->writeModuloToFile<ModuloEmParalelo>(dynamic_cast<ModuloEmParalelo*>((*it)), file);
		} else if (dynamic_cast<Amplificador*>( (*it) )) {
			this->writeCircuitToFile(file, 'A', dynamic_cast<Amplificador*>( (*it) )->getGanho());
		} else if (dynamic_cast<Integrador*>( (*it) )) {
			this->writeCircuitToFile(file, 'I');
		} else if (dynamic_cast<Derivador*>( (*it) )) {
			this->writeCircuitToFile(file, 'D');
		}

		it++;
	}

	this->writeCircuitToFile(file, 'f');
}

void PersistenciaDeModulo::writeCircuitToFile(std::ofstream &file, char circuit, double value) {
	file << circuit;
	if (circuit == 'A') file << " " << value;
	file << std::endl;
}

Modulo *PersistenciaDeModulo::lerDeArquivo() {
	return nullptr;
}
