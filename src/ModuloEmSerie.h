#pragma once

#include "Modulo.h"

class ModuloEmSerie : public Modulo {
	public:
		ModuloEmSerie();
		virtual ~ModuloEmSerie();
		Sinal *processar(Sinal *sinalIN);
};
