#include <algorithm>
#include <cmath>
#include <iostream>
#include "ModuloRealimentado.h"
#include "Sinal.h"
#include "Somador.h"
#include "Amplificador.h"
#include "Integrador.h"
#include "Derivador.h"
#include "PersistenciaDeModulo.h"

const int maxSteps = 60;
// No PDF esta falando que nao pode usar outros defines,
// e eu me recuso a usar numeros magicos no meu codigo,
// por isso essa variavel constante

using namespace std;

Sinal* newSinal() { //identico ep1

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
	cout << "Qual simulacao voce gostaria de fazer ?\n1) Circuito advindo de arquivo\n2) Sua propria sequencia de operacoes\nEscolha : ";

	int choice = 0;
	cin >> choice;

	Sinal* signalSim = newSinal();

	Modulo* modulo;

	if (choice == 1) {

		cout << "Qual o nome do arquivo a ser lido?" << endl;
		cout << "Nome: ";
		std::string fileName;
		cin >> fileName;

		PersistenciaDeModulo* persistenciaDeModulo = new PersistenciaDeModulo(fileName);
		modulo = persistenciaDeModulo->lerDeArquivo();
		delete persistenciaDeModulo;

		//ModuloRealimentado *moduloRealimentado = new ModuloRealimentado(acceleration);
		//moduloRealimentado->processar(signalSim)->imprimir("Velocidade do Carro");

	} else if (choice == 2) {
		bool repeat = true;

		cout << "\nQual estrutura de operações voce deseja ter como base?" << endl;
		cout << "1) Operacoes em serie nao realimentadas\n2) Operacoes em paralelo nao realimentadas\n3) Operacoes em serie realimentadas\n" << endl;
		cout << "Escolha : ";

		int operationStructureChoice = 0;
		cin >> operationStructureChoice;

		while (repeat) {
			repeat = false;

			cout << "\nQual operacao voce gostaria de fazer?" << endl;
			cout << "1) Amplificar\n2) Derivar\n3) Integrar" << endl;
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
						Derivador deriv = Derivador();
						Sinal *tempSignal = deriv.processar(signalSim);
						delete signalSim;
						signalSim = tempSignal;
					}
					break;
				case 3:
					{
						Integrador integ = Integrador();
						Sinal *tempSignal = integ.processar(signalSim);
						delete signalSim;
						signalSim = tempSignal;
					}
					break;
			}

			cout << "\nO que voce quer fazer agora?" << endl;
			cout << "1) Realizar mais uma operacao no resultado\n2) Imprimir o resultado" << endl;
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



	cout << "Voce gostaria de salvar o circuito em um novo arquivo?" << endl;
	cout << "1) Sim" << endl;
	cout << "1) Nao" << endl;
	cout << "Escolha : ";

	int saveCircuitChoice = 0;
	cin >> saveCircuitChoice;
	
	if (saveCircuitChoice == 1)
	{
		cout << "Qual o nome do arquivo a ser escrito?" << endl;
		cout << "Nome: ";
		std::string newFileName;
		cin >> newFileName;

		PersistenciaDeModulo* persistenciaDeModulo = new PersistenciaDeModulo(newFileName);
		persistenciaDeModulo->salvarEmAquivo(modulo);

		delete persistenciaDeModulo;
	}


}
