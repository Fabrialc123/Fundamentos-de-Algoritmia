/*

NUMERO DE GRUPO:02

NOMBRRE Y APELLIDOS DE LOS AUTORES:
	David del Cerro Dominguez y Fabrizio Alcaraz Escobar

*/


#include <iostream>

using namespace std;



/*

(1) En caso de utilizar una generalización, indicar su parámetros, y explicar para que
sirven cada uno de ellos

(2) ¿Cómo son las soluciones parciales de este problema?

(3) ¿Cuándo una solución parcial es viable?

(4) ¿Cuándo una solución parcial es una solución final al problema?

(5) Dada una solución parcial, ¿cómo se generan las siguientes soluciones
parciales viables?

(6) Análisis de casos

(6.1) Caso(s) base


(6.2) Caso(s) recursivos

(7) En caso de utilizar una generalización, explicar cómo se define el algoritmo final
a partir de la misma, por inmersión.



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
	
	