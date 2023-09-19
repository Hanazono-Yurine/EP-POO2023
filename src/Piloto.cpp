#include "Piloto.h"
#include "Amplificador.h"
#include "Integrador.h"

Piloto::Piloto(double ganho):
ganho(ganho) {

}

Piloto::~Piloto() {

}

Sinal* Piloto::processar(Sinal* sinalIN) {
	Amplificador amp = Amplificador(this->ganho);
	Sinal *amplifiedSinal = amp.processar(sinalIN);
	Integrador intregador = Integrador();
	return intregador.processar(amplifiedSinal);
}
