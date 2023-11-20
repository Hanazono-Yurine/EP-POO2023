#pragma once

class Circuito {
	public:
		Circuito();
		virtual ~Circuito() = 0;
		int getID();
		void imprimir();
		static int getUltimoID();
	private:
		void assignNewId();
		int currentID;
		static int lastAssignedID;
};
