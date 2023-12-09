#include "PersistenciaDeModulo.h"
#include "Amplificador.h"
#include "Integrador.h"
#include "Derivador.h"
#include "Modulo.h"
#include "ModuloEmSerie.h"
#include "ModuloEmParalelo.h"
#include "ModuloRealimentado.h"
#include <cstring>
#include <fstream>
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <string>

PersistenciaDeModulo::PersistenciaDeModulo(std::string nomeDoArquivo) : fileName(nomeDoArquivo) {
}

PersistenciaDeModulo::~PersistenciaDeModulo() {
}

void PersistenciaDeModulo::salvarEmArquivo(Modulo *mod) {
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
	std::ifstream file;
	file.open(this->fileName);

	if (file.fail()) throw new std::invalid_argument("Erro de Leitura");

	Modulo *modulo = this->readModuleFromFile(file);

	file.close();
	return modulo;
}

Modulo *PersistenciaDeModulo::readModuleFromFile(std::ifstream &file) {
	//Seria melhor usar vector, eu sei, mas mó preguica de mudar :)
	Modulo *modulesList[1000] = {nullptr};
	std::string readChar;
	int nestedModule = -1;

	while (!file.fail()) {
		file >> readChar;

		switch (readChar[0]) {
			case 'S':
				nestedModule++;
				modulesList[nestedModule] = new ModuloEmSerie();
				if (nestedModule != 0) modulesList[nestedModule - 1]->adicionar(modulesList[nestedModule]);
				break;
			case 'P':
				nestedModule++;
				modulesList[nestedModule] = new ModuloEmParalelo();
				if (nestedModule != 0) modulesList[nestedModule - 1]->adicionar(modulesList[nestedModule]);
				break;
			case 'R':
				nestedModule++;
				modulesList[nestedModule] = new ModuloRealimentado();
				if (nestedModule != 0) modulesList[nestedModule - 1]->adicionar(modulesList[nestedModule]);
				break;
			case 'A':
				double value;
				file >> value;
				if (!file.fail()) {
					modulesList[nestedModule]->adicionar(new Amplificador(value));
				} else {
					throw new std::logic_error("Wrong value for Amplificador");
				}
				break;
			case 'I':
				modulesList[nestedModule]->adicionar(new Integrador());
				break;
			case 'D':
				modulesList[nestedModule]->adicionar(new Derivador());
				break;
			case 'f':
				nestedModule--;
				break;
			default:
				throw new std::logic_error("Coringando");
				break;
		}
	}

	if (nestedModule != -2) {
		throw new std::logic_error("Algo de errado não esta certo");
	}

	return modulesList[0];
}
