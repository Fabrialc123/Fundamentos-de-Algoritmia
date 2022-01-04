/*
Nº Grupo:2

Nombre y apellidos de los miembros del grupo:
	David del Cerro Dominguez y Fabrizio Alcaraz Escobar
*/

#define DOM_JUDGE

#include <iostream>

#ifndef DOM_JUDGE
#include <ctime>
#include <stdlib.h>
#endif

using namespace std;


/*
(1) En caso de utilizar una generalización, indicar su parámetros, y explicar para que
    sirven cada uno de ellos
	
-Parametro de entrada a[] el vector sobre el que estamos trabajando
-Parametro de entrada n longitud total del array 
-Parametro de entrada inicio para la busqueda binaria
-Parametro de entrada fin para la busqueda binaria
-Parametro de entrada longitud, parametro de acumulacion para algunos casos de la busqueda
-Parametro de entrada primerelemento, indica cual es el primer elemento que se está tratando actualmente
-Parametro de salida indice, al encontrar un tramo indica cual es la posicion del siguiente elemento.
(2) Análisis de casos

     (2.1) Caso(s) base
		Si el primer elemento y ultimo numero (n) son iguales entonces nos encontramos ante un tramo de longitud n - inicio;

	 (2.2) Caso(s) recursivos
		En otro caso entonces buscamos el ultimo elemento del tramo realizando una busqueda binaria, de forma que calculamos el indice medio ( (ini + fin) / 2) y
		comparamos con el primer elemto del tramo, si este es igual miramos el siguiente para comprobar si nos encontramos en el ultimo, si no es asi llamamos recursivamente
		para buscar en el tramo  definido ahora por (ini + fin) / 2 y fin.
		Si el numero es el buscado entonces calcularemos la longitud, la compararemos con el mayor tramo encontrado hasta ahora y si es mayoer entonces lo actualizaremos.Una vez
		hecho esto llamaremos a la funcion recursivamente actualizando sus valores adecuadamente.
		Si el numero es distinto al primer elemento entonces llamaremos recursivamentte a la funcion pero ahora en el tramo que comprende a ini y (ini + fin) / 2;

(3) En caso de utilizar una generalización, explicar cómo se define el algoritmo final
    a partir de la misma, por inmersión. 

	Se invoca la generalización como  busq_tramo(a[],n,resul) siendo resul donde se devuelve el resultado
*/

int busqueda(int a[], int n, int inicio, int fin,int longitud, int primerelemento, int & indice) {
	int mitad = (fin + inicio) / 2;
	if (primerelemento == a[n - 1]) {
		indice = n - 1;
		return (n - inicio);
	}
	if (primerelemento == a[mitad]) {
		if (primerelemento == a[mitad + 1]) {
			return busqueda(a, n, mitad + 1, fin, longitud + (mitad - inicio)+ 1,primerelemento,indice);
		}
		else {
			indice = mitad + 1;
			return longitud + (mitad - inicio) + 1;
		}
	}
	else {
		return busqueda(a, n, inicio, mitad - 1, longitud, primerelemento, indice);
	}
	
}

void busq_tramo(int a[], int n, int & resul) {
	int indice = 0;
	int resul_aux = 0;
	if (a[0] == a[n - 1]){
		resul = n;
	}
	else {

		while (indice < n - 1) {
			resul_aux = busqueda(a, n, indice, n, 0, a[indice], indice);
			if (resul_aux > resul) {
				resul = resul_aux;
			}
		}
	}
}


//pre: a está ordenado. n > 0
int lon_tramo_cte_max(int a[], int n) {
	int resultado = 0;
	busq_tramo(a, n, resultado);
	return resultado;
}


/*
(1) Ecuaciones de recurrencia
  t(1) = co
  t(n) = c1 + t(n/2)
(2) Resolución de las ecuaciones (aplicación de los patrones de resoulución)
   - a=1
	- k = 0
	- b = 2
(3) Complejidad final del algoritmo.
	Por tanto, b^k = 1. Es decir, estamos en el caso
   a = b^k. Por tanto t(n) sera O( log2 n). Es decir,
   O(n^0 log 2n). Es decir O(log2 n)
(4) Posibles ventajas y desventajas de tu algoritmo frente a una solución iterativa de coste
     lineal
	En la mayoria de casos el algoritmo es mas eficiente que una solucion linear.
*/


#ifndef DOM_JUDGE
int lon_tramo_cte_max_it(int a[], int n) {
	int lon = 1;
	int pos = 1;
	int lon_max = 1;
	while (pos != n) {
		if (a[pos] == a[pos - 1]) {
			lon++;
		}
		else {
			lon = 1;
		}
		if (lon > lon_max) {
			lon_max = lon;
		}
		pos++;
	}
	return lon_max;
}


const int MAX_LON = 40;
const int MAX_INIT = 20;
const int MAX_INC = 10;


void genera_caso(int a[], int & n) {
	n = (rand() % MAX_LON) + 1;
	a[0] = rand()%MAX_INIT;
	for (int i = 1; i < n; i++) {
		if (rand() % 2 == 0) {
			a[i] = a[i - 1];
		}
		else {
			a[i] = a[i - 1] + (rand()%MAX_INC);
		}
	}

}

const int MAX_PRUEBAS = 1000;
#endif

#ifdef DOM_JUDGE
const int MAX_LON = 10000;

bool ejecuta_caso() {
	int a[MAX_LON];
	int n;
	cin >> n;
	if (n == 0) {
		return false;
	}
	else {
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		cout << lon_tramo_cte_max(a, n) << endl;
		return true;
	}
}

#endif

int main() {
#ifndef DOM_JUDGE
	int a[MAX_LON];
	int n;
	srand(time(NULL));
	int i = 0;
	int ok = true;
	while (i < MAX_PRUEBAS && ok) {
		genera_caso(a, n);
		if (lon_tramo_cte_max_it(a, n) != lon_tramo_cte_max(a, n)) {
			cout << "NO FUNCIONA PARA: ";
			for (int i = 0; i < n; i++) {
				cout << a[i] << " ";
			}
			cout << endl;
			ok = false;
		}
		i++;
	}
	if (ok) {
		cout << "OK" << endl;
	}
	system("pause");
#endif

#ifdef DOM_JUDGE
	while (ejecuta_caso());
#endif

}