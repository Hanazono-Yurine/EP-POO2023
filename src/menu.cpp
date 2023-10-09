#include <algorithm>
#include <cmath>
#include <iostream>
#include "ModuloRealimentado.h"
#include "Sinal.h"
#include "Somador.h"
#include "Amplificador.h"
#include "Integrador.h"
#include "Derivador.h"

const int maxSteps = 60;
// No PDF esta falando que nao pode usar outros defines,
// e eu me recuso a usar numeros magicos no meu codigo,
// por isso essa variavel constante

using namespace std;

Sinal* newSinal() {

	double arraySinal[maxSteps];

	cout << "\nQual sinal voce gostaria de utilizar como entrada da sua simulacao?" << endl;
	cout << "1) 5 + 3 * cos(n * pi / 8)\n2) constante\n3) rampa\nEscolha : ";

	int choiceSinal = 0;
	cin >> choiceSinal;

	switch (choiceSinal) {
		case 1:
			for (int i = 0; i < maxSteps; i++) {
				arraySinal[i] = 5 + 3 * cos(i * M_PI / 8);
			}
			break;
		case 2:
			{
				cout << "\nQual o valor dessa constante?\nC = ";

				double constValue = 0;
				cin >> constValue;

				for (int i = 0; i < maxSteps; i++) {
					arraySinal[i] = constValue;
				}
			}
			break;
		case 3:
			cout << "\nQual a inclinacao dessa rampa?\na = ";

			double slope = 0;
			cin >> slope;

			for (int i = 0; i < maxSteps; i++) {
				arraySinal[i] = slope*i;
			}
			break;
	}

	return new Sinal(arraySinal, maxSteps);
}

void menu() {

	double cosineWave[maxSteps];

	for (int i = 0; i < maxSteps; i++) {
		cosineWave[i] = 5 + 3 * cos(i*M_PI/8);
		//cout << cosineWave[i] << ", ";
	}

	cout << "        Simulink em C++" << endl;
	cout << "Qual simulacao voce gostaria de fazer ?\n1) Piloto Automatico\n2) Sua propria sequencia de operacoes\nEscolha : ";

	int choice = 0;
	cin >> choice;

	Sinal* signalSim = newSinal();

	if (choice == 1) {

		cout << "\nQual o ganho do acelerador?\ng = ";

		double acceleration = 0;
		cin >> acceleration;

		cout << endl;

		ModuloRealimentado *moduloRealimentado = new ModuloRealimentado(acceleration);
		moduloRealimentado->processar(signalSim)->imprimir("Velocidade do Carro");

	} else if (choice == 2) {
		bool repeat = true;

		while (repeat) {
			repeat = false;

			cout << "\nQual operacao voce gostaria de fazer?" << endl;
			cout << "1) Amplificar\n2) Somar\n3) Derivar\n4) Integrar" << endl;
			cout << "Escolha : ";

			int operationChoice = 0;
			cin >> operationChoice;

			switch (operationChoice) {
				case 1:
					{
						cout << "\nQual o ganho dessa amplificação?\ng = ";

						double userAmp = 0.0;
						cin >> userAmp;

						Amplificador amp = Amplificador(userAmp);
						Sinal *tempSignal = amp.processar(signalSim);
						delete signalSim;
						signalSim = tempSignal;
					}
					break;
				case 2:
					{
						cout << "\nInforme mais um sinal para ser somado.";

						Sinal *signalToSum = newSinal();

						Somador sum = Somador();
						Sinal *tempSignal = sum.processar(signalSim, signalToSum);
						delete signalToSum;
						delete signalSim;
						signalSim = tempSignal;
					}
					break;
				case 3:
					{
						Derivador deriv = Derivador();
						Sinal *tempSignal = deriv.processar(signalSim);
						delete signalSim;
						signalSim = tempSignal;
					}
					break;
				case 4:
					{
						Integrador integ = Integrador();
						Sinal *tempSignal = integ.processar(signalSim);
						delete signalSim;
						signalSim = tempSignal;
					}
					break;
			}

			cout << "\nO que voce quer fazer agora?" << endl;
			cout << "1) Realizar mais uma operacao no resultado\n2) Imprimir o resultado para terminar" << endl;
			cout << "Escolha : ";

			int repeatChoice = 0;
			cin >> repeatChoice;

			if (repeatChoice == 1)
				repeat = true;
		}

		cout << endl;

		signalSim->imprimir("Resultado Final");
		delete signalSim;
	}

}
