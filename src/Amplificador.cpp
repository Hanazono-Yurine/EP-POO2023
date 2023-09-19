#include "Amplificador.h"
#include "Sinal.h"

Amplificador::Amplificador(double ganho):
ganho(ganho) {

}

Amplificador::~Amplificador() {
}

Sinal* Amplificador::processar(Sinal* sinalIN) {
	const double *sequenciaClone = sinalIN->getSequencia(); 
	double *sinalProc = new double[sinalIN->getComprimento()];
	for (int index = 0; index < sinalIN->getComprimento(); index++) {
		sinalProc[index] = sequenciaClone[index] * this->ganho;
	}
	Sinal *sinalOUT = new Sinal(sinalProc, sinalIN->getComprimento());
	delete[] sinalProc;
	return sinalOUT;
}

void Amplificador::setGanho(double ganho) {
	this->ganho = ganho;
}

double Amplificador::getGanho() {
	return this->ganho;
}
