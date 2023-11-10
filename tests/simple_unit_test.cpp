#include <catch2/catch_test_macros.hpp>
#include "../src/Amplificador.h"
#include "../src/Somador.h"
#include "../src/Sinal.h"

TEST_CASE( "Verify Amplificador class", "[Amplificador]") {
	double simpleArray[5] = {1.0, 2.0, 3.0, 4.0, 5.0};
	Sinal sinal = Sinal(simpleArray, 5);
	SECTION("Amplificador as inverter") {
		Amplificador *p = new Amplificador(-1);
		double *ampArray = p->processar(&sinal)->getSequencia();

		REQUIRE( (ampArray[0] == -1 && ampArray[1] == -2 &&
				ampArray[2] == -3 && ampArray[3] == -4 &&
				ampArray[4] == -5)
		);

		delete [] ampArray;
		delete p;
	}

	SECTION("Gain set to 2") {
		Amplificador *p = new Amplificador(2);
		double *ampArray = p->processar(&sinal)->getSequencia();

		REQUIRE( (ampArray[0] == 2 && ampArray[1] == 4 &&
				ampArray[2] == 6 && ampArray[3] == 8 &&
				ampArray[4] == 10)
		);

		delete [] ampArray;
		delete p;
	}
}

TEST_CASE("Verify Somador class", "[Somador]") {
	double simpleArray[5] = {1.0, 2.0, 3.0, 4.0, 5.0};
	Sinal sinal = Sinal(simpleArray, 5);
	SECTION("Sum with value 5") {
		double arrayWithFive[5] = {5.0, 5.0, 5.0, 5.0, 5.0};
		Sinal sinalFive = Sinal(arrayWithFive, 5);
		Somador *sum = new Somador();
		double *sumArray = sum->processar(&sinal, &sinalFive)->getSequencia();

		REQUIRE( (sumArray[0] == 6 && sumArray[1] == 7 &&
				sumArray[2] == 8 && sumArray[3] == 9 &&
				sumArray[4] == 10)
		);

		delete [] sumArray;
		delete sum;
	}
}
