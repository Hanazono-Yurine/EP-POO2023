#include <algorithm>
#include <cmath>
#include <iostream>
#include "ModuloEmParalelo.h"
#include "ModuloEmSerie.h"
#include "ModuloRealimentado.h"
#include "Sinal.h"
#include "Somador.h"
#include "Amplificador.h"
#include "Integrador.h"
#include "Derivador.h"
#include "PersistenciaDeModulo.h"

const int maxSteps = 60;

Sinal *newSinal();
void getOperations(Modulo *modulo);

void menu() {

	double cosineWave[maxSteps];

	for (int i = 0; i < maxSteps; i++) {
		cosineWave[i] = 5 + 3 * cos(i*M_PI/8);
	}

	std::cout << "        Simulink em C++" << std::endl;
	std::cout << "Qual simulacao voce gostaria de fazer?\n1) Circuito advindo de arquivo" << std::endl;
	std::cout <<	"2) Sua propria sequencia de operacoes\nEscolha: ";

	int choice = 0;
	std::cin >> choice;

	Sinal* signalSim = newSinal();

	Modulo* modulo;

	if (choice == 1) {
		std::cout << "\nQual o nome do arquivo a ser lido?\nNome: ";

		std::string fileName;
		std::cin >> fileName;

		PersistenciaDeModulo persistenciaDeModulo = PersistenciaDeModulo(fileName);
		modulo = persistenciaDeModulo.lerDeArquivo();

	} else if (choice == 2) {
		std::cout << "\nQual estrutura de operações voce deseja ter como base?" << std::endl;
		std::cout << "1) Operacoes em serie nao realimentadas\n2) Operacoes em paralelo nao realimentadas" << std::endl;
		std::cout << "3) Operacoes em serie realimentadas\nEscolha: ";

		int operationStructureChoice = 0;
		std::cin >> operationStructureChoice;

		switch (operationStructureChoice) {
			case 1:
				modulo = new ModuloEmSerie();
				break;
			case 2:
				modulo = new ModuloEmParalelo();
				break;
			case 3:
				modulo = new ModuloRealimentado();
				break;
		}

		getOperations(modulo);
	}

	std::cout << std::endl;

	signalSim = modulo->processar(signalSim);
	signalSim->imprimir("Resultado Final");
	delete signalSim;

	std::cout << "\nVoce gostaria de salvar o circuito em um novo arquivo?" << std::endl;
	std::cout << "1) Sim" << std::endl;
	std::cout << "2) Nao" << std::endl;
	std::cout << "Escolha: ";

	int saveCircuitChoice = 0;
	std::cin >> saveCircuitChoice;
	
	if (saveCircuitChoice == 1) {
		std::cout << "\nQual o nome do arquivo a ser escrito?" << std::endl;
		std::cout << "Nome: ";
		std::string newFileName;
		std::cin >> newFileName;

		PersistenciaDeModulo persistenciaDeModulo = PersistenciaDeModulo(newFileName);
		persistenciaDeModulo.salvarEmArquivo(modulo);
	}
}

void getOperations(Modulo *modulo) {
	bool repeat = true;
	while (repeat) {
		repeat = false;

		std::cout << "\nQual operacao voce gostaria de fazer?" << std::endl;
		std::cout << "1) Amplificar\n2) Derivar\n3) Integrar" << std::endl;
		std::cout << "Escolha: ";

		int operationChoice = 0;
		std::cin >> operationChoice;

		switch (operationChoice) {
			case 1:
				{
					std::cout << "\nQual o ganho dessa amplificação?\ng = ";

					double userAmpValue = 0.0;
					std::cin >> userAmpValue;

					modulo->adicionar(new Amplificador(userAmpValue));
				}
				break;
			case 2:
				modulo->adicionar(new Derivador());
				break;
			case 3:
				modulo->adicionar(new Integrador());
				break;
		}

		std::cout << "\nO que voce quer fazer agora?" << std::endl;
		std::cout << "1) Realizar mais uma operacao no resultado\n2) Imprimir o resultado" << std::endl;
		std::cout << "Escolha: ";

		int repeatChoice = 0;
		std::cin >> repeatChoice;

		if (repeatChoice == 1)
			repeat = true;
	}
}

Sinal* newSinal() {

	double arraySinal[maxSteps];

	std::cout << "\nQual sinal voce gostaria de utilizar como entrada da sua simulacao?" << std::endl;
	std::cout << "1) 5+3*cos(n*pi/8)\n2) constante\n3) rampa\nEscolha: ";

	int choiceSinal = 0;
	std::cin >> choiceSinal;

	switch (choiceSinal) {
		case 1:
			for (int i = 0; i < maxSteps; i++) {
				arraySinal[i] = 5 + 3 * cos(i * M_PI / 8);
			}
			break;
		case 2:
			{
				std::cout << "\nQual o valor dessa constante?\nC = ";

				double constValue = 0;
				std::cin >> constValue;

				for (int i = 0; i < maxSteps; i++) {
					arraySinal[i] = constValue;
				}
			}
			break;
		case 3:
			std::cout << "\nQual a inclinacao dessa rampa?\na = ";

			double slope = 0;
			std::cin >> slope;

			for (int i = 0; i < maxSteps; i++) {
				arraySinal[i] = slope*i;
			}
			break;
	}

	return new Sinal(arraySinal, maxSteps);
}
