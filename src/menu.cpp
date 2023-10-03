#include <cmath>
#include <iostream>
#include "ModuloRealimentado.h"
#include "Sinal.h"
#include "Amplificador.h"
#include "Integrador.h"

#define MAX_STEPS 60

using namespace std;

Sinal* newSinal() {

	double arraySinal[MAX_STEPS];

	cout << "Qual sinal voce gostaria de utilizar como entrada da sua simulacao?\n1) 5 + 3 * cos(n * pi / 8)\n2) constante\n3) rampa\nEscolha : ";
	int choiceSinal = 0;
	cin >> choiceSinal;
	if (choiceSinal == 1) {

		for (int i = 0; i < MAX_STEPS; i++) {
			arraySinal[i] = 5 + 3 * cos(i * M_PI / 8);
		}

		return new Sinal(arraySinal, MAX_STEPS);
	}
	else if (choiceSinal == 2) {
		cout << "Qual o valor dessa constante?\nC = ";

		double constValue = 0;
		cin >> constValue;

		for (int i = 0; i < MAX_STEPS; i++) {
			arraySinal[i] = constValue;
		}

		return new Sinal(arraySinal, MAX_STEPS);
	}
	//supondo que o usuario so digita 1, 2 e 3

	cout << "Qual a inclinacao dessa rampa?\na = ";

	double slope = 0;
	cin >> slope;

	for (int i = 0; i < MAX_STEPS; i++) {
		arraySinal[i] = slope*i;
	}

	return new Sinal(arraySinal, MAX_STEPS);

}

void menu() {

	double cosineWave[60];

	for (int i = 0; i < 60; i++) {
		cosineWave[i] = 5 + 3 * cos(i*M_PI/8);
		//cout << cosineWave[i] << ", ";
	}

	cout << "Simulink em C++\nQual simulacao voce gostaria de fazer ?\n1) Piloto Automatico\n2) Sua propria sequencia de operacoes\nEscolha : ";

	int choice = 0;
	cin >> choice;

	Sinal* signalSim = newSinal();

	if (choice == 1) {

		cout << "Qual o ganho do acelerador?\ng = ";

		double acceleration = 0;
		cin >> acceleration;

		ModuloRealimentado *moduloRealimentado = new ModuloRealimentado(acceleration);
		Sinal* processedSignal = moduloRealimentado->processar(signalSim);

		processedSignal->imprimir("Velocidade do Carro");

	}

}
