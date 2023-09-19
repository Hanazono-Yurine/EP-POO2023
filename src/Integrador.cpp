#include "Integrador.h"
#include "Sinal.h"

Integrador::Integrador() {

}

Integrador::~Integrador() {

}

Sinal* Integrador::processar(Sinal* sinalIN) {
	const double *sequenciaClone = sinalIN->getSequencia(); 
	double *sinalProc = new double[sinalIN->getComprimento()];
	sinalProc[0] = sequenciaClone[0];
	for (int index = 1; index < sinalIN->getComprimento(); index++) {
		sinalProc[index] = sinalProc[index - 1] + sequenciaClone[index];
	}
	Sinal *sinalOUT = new Sinal(sinalProc, sinalIN->getComprimento());
	delete[] sinalProc;
	return sinalOUT;
}
