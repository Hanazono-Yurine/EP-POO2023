#pragma once

#include "Modulo.h"

class ModuloEmParalelo : public Modulo {
	public:
		ModuloEmParalelo();
		virtual ~ModuloEmParalelo();
		Sinal *processar(Sinal *sinalIN);
};

