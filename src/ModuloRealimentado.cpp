#include "ModuloRealimentado.h"
#include "Amplificador.h"
#include "Somador.h"
#include "Modulo.h"
#include "ModuloEmSerie.h"
#include "Somador.h"
#include "Sinal.h"

ModuloRealimentado::ModuloRealimentado() : Modulo(), piloto(new ModuloEmSerie()) {
}

ModuloRealimentado::~ModuloRealimentado() {
	delete this->piloto;
}

void ModuloRealimentado::adicionar(CircuitoSISO *circ) {
	this->piloto->adicionar(circ);
}

Sinal* ModuloRealimentado::processar(Sinal* sinalIN) {
	Amplificador inverter = Amplificador(-1.0);
	Somador sum = Somador();

	double *diff = new double[sinalIN->getComprimento()];

	Sinal *sinalOUT = new Sinal(diff, sinalIN->getComprimento());
	Sinal sinalDiff = Sinal(sinalIN->getSequencia(), sinalIN->getComprimento());
	Sinal sinalInverted = Sinal(diff, sinalIN->getComprimento());

	delete[] diff;

	sinalOUT->getSequencia()[0] = this->piloto->processar(sinalIN)->getSequencia()[0];

	for (int index = 1; index < sinalIN->getComprimento(); index++) {

		sinalInverted.getSequencia()[index] = inverter.processar(sinalOUT)->getSequencia()[index - 1]; 

		sinalDiff.getSequencia()[index] = sum.processar(&sinalDiff, &sinalInverted)->getSequencia()[index]; 

		sinalOUT->getSequencia()[index] = this->piloto->processar(&sinalDiff)->getSequencia()[index];
	}
	return sinalOUT;
}
