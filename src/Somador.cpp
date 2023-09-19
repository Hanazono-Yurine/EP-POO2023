#include "Somador.h"
#include "Sinal.h"

Somador::Somador() {
}

Somador::~Somador() {
}

Sinal* Somador::processar(Sinal* sinalIN, Sinal* sinalIN2) {
	const double *sequenciaClone = sinalIN->getSequencia(); 
	const double *sequencia2Clone = sinalIN2->getSequencia(); 
	const int maxLengthOut = (sinalIN->getComprimento() <= sinalIN2->getComprimento()) ? sinalIN->getComprimento() : sinalIN2->getComprimento();
	double *sinalProc = new double[maxLengthOut];
	for (int index = 0; index < maxLengthOut; index++) {
		sinalProc[index] = sequenciaClone[index] + sequencia2Clone[index];
	}
	Sinal *sinalOUT = new Sinal(sinalProc, maxLengthOut);
	delete[] sinalProc;
	return sinalOUT;
}
