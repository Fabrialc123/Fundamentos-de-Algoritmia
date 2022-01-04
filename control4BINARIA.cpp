#include <algorithm>
#include <iostream>

using namespace std;
// Nombres de alumnos : José Fabrizio Alcaraz Escobar && David del Cerro Domínguez

/*

PRECONDICION DE LA FUNCION: 
  ---Escribe aquí la precondición de la función.
  P ? { n >= 0 AND PARATODO i; 0 <= i < n-1; a[i] < a[i+1] AND k >= 0 }
  
*/
unsigned int num_k_emparejados(int v[], unsigned int n, unsigned int k);
/*
POSTCONDICION DE LA FUNCION: 
  ---Escribe aquí la poscondición de la función. Para refirte 
  ---al valor devuelto por la función, utiliza la pseudo-variable
  ---'resul'
  
  (1) Definiciones auxiliares (si procede):
  num_k_emparejados(a,n,k) ? #i,j ; 0 <= i < n AND i <= j < n; |a[i] - a[j]| = k )

  
  (2) Postcondición
  Q ? {resul = num_k_emparejados(a,n,k)}
  
 */
 
 /* DISEÑO DEL ALGORITMO:
 --- Detalla aquí el proceso seguido para diseñar el
 --- algoritmo
 
 
PASO 1. Variables
	Además de las variables de entrada (a,k,n), utilizaremos dos variables de control i,j
	y resul.
	
 
PASO 2. Invariante
	INV  ?  #i',j' ; 0 <= i' <= i AND i' <= j' <= j; |a[i'] - a[j']| = k 

 
PASO 3. Inicialización:
	i = 0;
	j = 0;
	resul = 0;
	enc = false;

PASO 4: Continuación y finalización: 
 	  El bucle continuará siempre que  i != n y se finalizará en caso contrario (i == n).
 
PASO 5: Cuerpo del bucle
	En cada iteracción del bucle, cogemos a[i] y comprobamos con qué j  se cumple que
	|a[i] - a[j]| = k , para el cual utilizaremos otro bucle en el que buscamos binariamente el j que lo cumple.
	En caso de que se encuentre una j, se sumará 1 a resul.
	Y para finalizar sumara en uno i.
 
PASO 6: Terminación		  
	La cota que utilizaremos es i - n = 0
 
*/
 

unsigned int num_k_emparejados(int v[], unsigned int n, unsigned int k) {
    /* IMPLEMENTACION: COMPLETA EL CUERPO DE LA FUNCION
       CON EL CODIGO QUE IMPLEMENTA EL ALGORITMO */
	unsigned int resul = 0;
	if (k == 0) resul = n;
	else {
		bool enc = false;
		unsigned int i = 0;
		unsigned int ini, fin,aux;
		while (i < n-1) {
			enc = false;
			fin = n-1;
			ini = i + 1;
			while (!enc) {
				aux = (ini + fin) / 2;
				if (ini > fin) enc = true;
				else if (abs(v[i] - v[aux]) == k) {
					resul++;
					enc = true;
				}
				else if (abs(v[i] - v[aux]) > k) fin = aux - 1;
				else if (abs(v[i] - v[aux]) < k) ini = aux + 1;	
			}
					i++;
		}
	}
	return resul;
}	

/*
Complejidad: Determina justificadamente el orden de complejidad
de este algoritmo: 
K0 Coste inicializacion del bucle y finalizacion
K1 Coste constante cada iteraccion del bucle
K2 Coste constante de cada iteraccion de la busqueda binaria.
En el mejor de los casos (k == 0), la ecuacion quedaria : K0.
En el peor de los casos, la ecuacion quedaria: K0 + n*K1 * K2*log(n).

La complejidad final resulta ser lineal
*/ 



bool procesa_caso() {
	int v[100];
	int n, k;
	cin >> n;
	if (n != -1) {
		cin >> k;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		cout << num_k_emparejados(v, n, k) << endl;
		return true;
	}
	else {
		return false;
	}
}

int main() {
	while (procesa_caso());
}