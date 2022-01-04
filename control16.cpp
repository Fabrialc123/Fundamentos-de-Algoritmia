/*

NUMERO DE GRUPO:02

NOMBRRE Y APELLIDOS DE LOS AUTORES: Fabrizio Alcaraz Escobar && David Del Cerro Dominguez


*/


#include <iostream>

using namespace std;

typedef unsigned long long t_num;
	

/*

(1) En caso de utilizar una generalización, indicar su parámetros, y explicar para que
sirven cada uno de ellos
	
	siguienteNum, se utiliza para ver por cual número va el recorrida y si se ha hecho más grande que n.
	sumaSactual, sirve para acumular la suma de los dígitos actuales.
	cantidadDs, sirve para acumular la cantidad de Ds consecutivos actuales.
	contador, sirve para acumular el número de resultados obtenidos.

(2) ¿Cómo son las soluciones parciales de este problema?

	Las soluciones parciales de este problema son generaciones de números desde el 1 hasta n-1

(3) ¿Cuándo una solución parcial es viable?

	Una solución parcial es viable cuando es menor que n ,no contiene ningún 0, la suma de sus dígitos no se ha pasado de S  
	y la mayor cantidad consecutiva de Ds es menor estricto que alpha.

(4) ¿Cuándo una solución parcial es una solución final al problema?

	Una solución parcial es una solución final al problema cuando la suma de esus dígitos es igual a S.

(5) Dada una solución parcial, ¿cómo se generan las siguientes soluciones
parciales viables?

	Las siguientes soluciones parciales viables se generan agregando un dígito al final del número actual, siempre y cuando cumpla con los requisitos del punto (3).

(6) Análisis de casos

(6.1) Caso(s) base

	Si la suma de sus dígitos ha alcanzado S , se ha encontrado una solución.


(6.2) Caso(s) recursivos

	Si el número generado aún no ha alcanzado S y sigue siendo viable, se llama recursivamente agregando un dígito.

(7) En caso de utilizar una generalización, explicar cómo se define el algoritmo final
a partir de la misma, por inmersión.

	Dado un número N, se van generando números desde 0 hasta N-1 que cumplan con (3), agregando dígitos al final del número en cada llamada recursiva hasta que se alcanza (4).


*/

void cuenta_limpios(unsigned short d, unsigned short alpha, t_num n, unsigned int s, t_num siguienteNum,unsigned int sumaSActual,unsigned int cantidadDs, int & contador) {
	if (sumaSActual == s && siguienteNum != 0) {
			contador++;
	}
	else {
		unsigned int digSiguiente = 1;
		bool seguir = true;
		while (seguir) {
			if (digSiguiente > 9 || sumaSActual + digSiguiente > s || (siguienteNum * 10) + digSiguiente >= n) seguir = false;
			else {
					if (digSiguiente != d)cuenta_limpios(d, alpha, n, s, (siguienteNum * 10) + digSiguiente, sumaSActual + digSiguiente, 0, contador);
					else if (cantidadDs + 1 < alpha) cuenta_limpios(d, alpha, n, s, (siguienteNum * 10) + digSiguiente, sumaSActual + digSiguiente, cantidadDs + 1, contador);
					digSiguiente++;
				}
		}
	}
}


int num_limpios(unsigned short d, unsigned short alpha, t_num n, unsigned int s) {
	// PUNTO DE ENTRADA DEL ALGORITMO

	int contador = 0;
	cuenta_limpios(d, alpha, n, s, 0, 0, 0, contador);
	return contador;

}


bool ejecuta_caso() {
	int d;
	cin >> d;
	if (d == -1) {
		return false;
	}
	else {
		unsigned short alpha; 
		unsigned int s;
		t_num n;
		cin >> alpha >> s >> n;
		cout << num_limpios(d, alpha, n, s) << endl;
		return true;
	}
}


int main() {
	while (ejecuta_caso());
}