#include "Derivador.h"

Derivador::Derivador() {

}

Derivador::~Derivador() {

}

Sinal* Derivador::processar(Sinal* sinalIN) {
	const double *sequenciaClone = sinalIN->getSequencia(); 
	double *sinalProc = new double[sinalIN->getComprimento()];
	sinalProc[0] = sequenciaClone[0];
	for (int index = 1; index < sinalIN->getComprimento(); index++) {
		sinalProc[index] = sequenciaClone[index] - sequenciaClone[index - 1];
	}
	Sinal *sinalOUT = new Sinal(sinalProc, sinalIN->getComprimento());
	delete[] sinalProc;
	return sinalOUT;
}
