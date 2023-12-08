#pragma once

#include "Modulo.h"
#include <fstream>
#include <string>

class PersistenciaDeModulo {
	public:
		PersistenciaDeModulo(std::string nomeDoArquivo);
		virtual ~PersistenciaDeModulo();
		void salvarEmAquivo(Modulo *mod);
		Modulo *lerDeArquivo();
	private:
		std::string fileName;
		template<typename T> void writeModuloToFile(T *module, std::ofstream &file);
		void writeCircuitToFile(std::ofstream &file, char circuit, double value = 0.0);
		Modulo *readModuleFromFile(std::ifstream &file);
};
