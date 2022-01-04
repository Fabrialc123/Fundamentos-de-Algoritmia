/*

NUMERO DE GRUPO:02

NOMBRRE Y APELLIDOS DE LOS AUTORES:
	David del Cerro Dominguez y Fabrizio Alcaraz Escobar

*/


#include <iostream>

using namespace std;



/*

(1) En caso de utilizar una generalizaci�n, indicar su par�metros, y explicar para que
sirven cada uno de ellos

(2) �C�mo son las soluciones parciales de este problema?

(3) �Cu�ndo una soluci�n parcial es viable?

(4) �Cu�ndo una soluci�n parcial es una soluci�n final al problema?

(5) Dada una soluci�n parcial, �c�mo se generan las siguientes soluciones
parciales viables?

(6) An�lisis de casos

(6.1) Caso(s) base


(6.2) Caso(s) recursivos

(7) En caso de utilizar una generalizaci�n, explicar c�mo se define el algoritmo final
a partir de la misma, por inmersi�n.



*/

void esSumDivisible (int numDig,int digActual,int suma, int & cont) {
	if (digActual == numDig) {
		if (suma % numDig == 0) cont++;
	}
	else if (digActual + 1 == numDig) {
		if ((suma % (numDig - 1)) == 0) {
			for (int i = 0; i < 10; i++) {
				esSumDivisible(numDig, digActual + 1, suma + i, cont);
			}
		}
	}
	else {
		for (int i = 0; i < 10; i++) {
			esSumDivisible(numDig, digActual + 1, suma + i, cont);
		}
	}
}

int num_sumdivisibles(int d, int k) {
	int cont = 0;
	esSumDivisible(k,1 ,d, cont);
	return cont;
}   


int main() {
	int d;
	do {
		cin >> d;
		if (d > 0) {
			int k;
			cin >> k;
			cout << num_sumdivisibles(d,k) << endl;
		}
	} while (d > 0);
}
	
	