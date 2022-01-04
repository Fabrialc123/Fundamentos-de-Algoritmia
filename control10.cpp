/*

NUMERO DE GRUPO: 02

NOMBRE Y APELLIDOS DE LOS AUTORES: Jose Fabrizio Alcaraz Escobar & David del Cerro Dominguez


*/


#include <iostream>

using namespace std;

const int MAXN = 10;


/*

(1) En caso de utilizar una generalización, indicar su parámetros, y explicar para que
    sirven cada uno de ellos

		Parámetro 1 : colección, es el array inicial.
		Parámetro 2 : n, es la longitud del array.
		Parámetro 3 : k, suma que deben de alcanzar las subcolecciones del array.
		Parámetro 4 : i, índice utlizado para recorrer el array.
		Parámetro 5 : subcolección, suma acumulada de la subcolección actual.

(2) ¿Cómo son las soluciones parciales de este problema?
	
		Las soluciones parciales de este problema son la acumulación de sumas de las subcolecciones.

(3) ¿Cuándo una solución parcial es viable?

		Una solución parcial es viable cuando su valor es menor a k.

(4) ¿Cuándo una solución parcial es una solución final al problema?

		Una solución parcial es una solución final cuando su valor es igual a k, si se pasa deja de ser viable.

(5) Dada una solución parcial, ¿cómo se generan las siguientes soluciones
    parciales viables?

		Las siguientes soluciones parciales viables se generan sumandoles el siguiente vector del array, en caso de que con este se pase se vuelve atrás y se le suma el siguiente de este.
		Se termina de generar la siguiente solución cuando se pase del array.
	
(6) Análisis de casos

     (6.1) Caso(s) base

		Si la subcolección actual ha alcanzado el valor k, se suma 1 al contador.
		Si la subcolección actual se ha pasado del valor de k, acaba la recursión.

	 (6.2) Caso(s) recursivos

		Si la subcolección actual aún no ha alcanzado k, se recorre el array en busca de todos los posibles valores que , o siga siendo inferior a k o se alcance a k.

(7) En caso de utilizar una generalización, explicar cómo se define el algoritmo final
    a partir de la misma, por inmersión. 
	
		Dado un vector inicial, se buscan todas las combinaciones posibles con los siguientes vectores que alcancen a k.
	
*/

int cuenta_subcolecciones(int coleccion[], int n, int k,int i , int subcoleccion) {
	subcoleccion += coleccion[i];
	if (subcoleccion == k) {
		return 1;
	}
	else if (subcoleccion > k) {
		return 0;
	}
	else if (subcoleccion < k) {
		int acumulador = 0;
		for (int j = i + 1; j < n; j++) {
			acumulador += cuenta_subcolecciones(coleccion, n, k, j, subcoleccion);
		}
		return acumulador;
	}
}


int modulo(int coleccion[], int n, int k) {
	/* A IMPLEMENTAR */
	int contador = 0;
	int subcoleccion = 0;
	for (int i = 0; i < n; i++) {
		contador += cuenta_subcolecciones(coleccion, n, k, i, subcoleccion);
	}
	return contador;
}

	
void lee_datos(int & n, int coleccion[], int& k) {
	cin >> n;
	if (n != 0) {
		for (int i = 0; i < n; i++) {
            cin >> coleccion[i];
		}
		cin >> k;
	}
}

bool ejecuta_caso() {
    int coleccion[MAXN];
	int n;
	int k;
	lee_datos(n,coleccion,k);
	if (n != 0) {
	  cout << modulo(coleccion,n,k) << endl;
      return true;	  
	}
	else {
	  return false;	
	}
}

int main() {
	while (ejecuta_caso());
}

