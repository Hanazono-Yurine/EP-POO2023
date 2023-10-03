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
	// Cria um inversor, um piloto e um somador
	Amplificador inverter = Amplificador(-1.0);
	Piloto piloto = Piloto(this->ganho);
	Somador sum = Somador();

	// Cria um array vazio com o tamanho do objeto de entrada
	double *diff = new double[sinalIN->getComprimento()];

	// Cria um objeto Sinal com a sequencia vazia
	Sinal *sinalOUT = new Sinal(diff, sinalIN->getComprimento());
	// Cria um objeto Sinal com a sequencia do objeto de entrada
	Sinal sinalDiff = Sinal(sinalIN->getSequencia(), sinalIN->getComprimento());
	// Cria um objeto Sinal com a sequencia vazia
	Sinal sinalInverted = Sinal(diff, sinalIN->getComprimento());

	// Deleta o array vazio
	delete[] diff;

	// Processa o primeiro valor da sequencia
	sinalOUT->getSequencia()[0] = piloto.processar(sinalIN)->getSequencia()[0];
	// Copia o valor processado pro primeiro elemento
	sinalDiff.getSequencia()[0] = sinalIN->getSequencia()[0];

	for (int index = 1; index < sinalIN->getComprimento(); index++) {
		// Daqui em diante é só lê no pdf


		sinalInverted.getSequencia()[index] = inverter.processar(sinalOUT)->getSequencia()[index - 1]; 
		//inverte sinalOUT, pega o valor posicao anterior e guarda em sinalInverted

		sinalDiff.getSequencia()[index] = sum.processar(&sinalDiff, &sinalInverted)->getSequencia()[index]; 
		//realiaza a soma sinalInverted + sinalDiff(que antes de ser modificado eh = ao sinalIN), pega o valor da posicao [index] e guarda no sinalDiff na [index]

		sinalOUT->getSequencia()[index] = piloto.processar(&sinalDiff)->getSequencia()[index];
		//passa o sinalDiff no piloto, pega o valor da posicao [index] e guarda no sinalOUT na [index]
	}
	return sinalOUT;
}
