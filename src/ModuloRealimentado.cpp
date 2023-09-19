#include "ModuloRealimentado.h"
#include "Amplificador.h"
#include "Somador.h"
#include "Integrador.h"
#include "Piloto.h"
#include "Somador.h"
#include "Sinal.h"
#include <iostream>

ModuloRealimentado::ModuloRealimentado(double ganho):
ganho(ganho) {
}

ModuloRealimentado::~ModuloRealimentado() {

}

Sinal* ModuloRealimentado::processar(Sinal* sinalIN) {
	Amplificador inverter = Amplificador(-1.0);
	Piloto piloto = Piloto(this->ganho);
	Somador sum = Somador();

	double *finalVelocid = new double[sinalIN->getComprimento()];
	double *diff = new double[sinalIN->getComprimento()];
	double x = 0.0;
	double y = sinalIN->getSequencia()[0];

	Sinal *sinalOUT = new Sinal(diff, sinalIN->getComprimento());
	Sinal *sinalDiff = new Sinal(sinalIN->getSequencia(), sinalIN->getComprimento());
	Sinal *sinalInverted = new Sinal(diff, sinalIN->getComprimento());

	sinalOUT->getSequencia()[0] = piloto.processar(sinalIN)->getSequencia()[0];
	sinalDiff->getSequencia()[0] = sinalIN->getSequencia()[0];

	for (int index = 1; index < sinalIN->getComprimento(); index++) {
		sinalInverted->getSequencia()[index] = inverter.processar(sinalOUT)->getSequencia()[index - 1];
		std::cout << sinalInverted->getSequencia()[index] << std::endl;

		std::cout << sinalDiff->getSequencia()[index] << " ";
		sinalDiff->getSequencia()[index] = sum.processar(sinalDiff, sinalInverted)->getSequencia()[index];
		std::cout << sinalDiff->getSequencia()[index] << std::endl;

		sinalOUT->getSequencia()[index] = piloto.processar(sinalDiff)->getSequencia()[index];
		std::cout << sinalOUT->getSequencia()[index] << std::endl;
	}
	return sinalOUT;
}
