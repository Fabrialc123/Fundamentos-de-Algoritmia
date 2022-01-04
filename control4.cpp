#include <algorithm>
#include <iostream>

using namespace std;
// Nombres de alumnos : José Fabrizio Alcaraz Escobar && David del Cerro Domínguez

/*

PRECONDICION DE LA FUNCION: 
  ---Escribe aquí la precondición de la función.
  P ≡ { n >= 0 AND PARATODO i; 0 <= i < n-1; a[i] < a[i+1] AND k >= 0 }
  
*/
unsigned int num_k_emparejados(int v[], unsigned int n, unsigned int k);
/*
POSTCONDICION DE LA FUNCION: 
  ---Escribe aquí la poscondición de la función. Para refirte 
  ---al valor devuelto por la función, utiliza la pseudo-variable
  ---'resul'
  
  (1) Definiciones auxiliares (si procede):
  num_k_emparejados(a,n,k) ≡ #i,j ; 0 <= i < n AND i <= j < n; |a[i] - a[j]| = k )

  
  (2) Postcondición
  Q ≡ {resul = num_k_emparejados(a,n,k)}
  
 */
 
 /* DISEÑO DEL ALGORITMO:
 --- Detalla aquí el proceso seguido para diseñar el
 --- algoritmo
 
 
PASO 1. Variables
	Además de las variables de entrada (a,n,n), utilizaremos dos variables de control i,j
	y resul.
	
 
PASO 2. Invariante
	INV  ≡  #i',j' ; 0 <= i' <= i AND i' <= j' <= j; |a[i'] - a[j']| = k 

 
PASO 3. Inicialización:
	i = 0;
	j = 0;
	resul = 0;
	enc = false;

PASO 4: Continuación y finalización: 
 	  El bucle continuará siempre que  i != n y se finalizará en caso contrario (i == n).
 
PASO 5: Cuerpo del bucle
	En cada iteracción del bucle, cogemos a[i] y comprobamos con qué j  se cumple que
	|a[i] - a[j]| = k , para el cual utilizaremos otro bucle en el que recorreremos i <= j < n.
	En caso de que se encuentre una j, se sumará 1 a resul.

 
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
		bool fin = false;
		unsigned int j = 0;
		unsigned int i = 0;
		while (i < n-1 && !fin) {
			enc = false;
			if (abs(v[i] - v[n - 1]) < k) fin = true;
			else {
				while ( (j < n) && !enc) {
					if (abs(v[i] - v[j]) >= k) {				// Se sale porque ya se ha pasado o lo ha encontrado
						enc = true;
						if (abs(v[i] - v[j]) == k) resul++;
					}
					else if (j == n - 1 && abs(v[i] - v[j]) < k) {		// termina porque si ni con el último componente llega a ser >= K, es imposible que los siguientes lo consigan
						fin = true;
						enc = true;
					}
					else j++;
				}
				i++;
			}
		}
	}
	return resul;
}	

/*
Complejidad: Determina justificadamente el orden de complejidad
de este algoritmo: 

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