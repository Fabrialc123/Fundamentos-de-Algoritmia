/*
N? GRUPO: 2
AUTORES DE LA PRACTICA (Nombres y Apellidos): José Fabrizio Alcaraz & David Del Cerro Domínguez

*/

#include <iostream>

using namespace std;

const unsigned int MAX_LON = 1000;

/*  
  PASO 1. Describe el o los casos base y justifica 
          resultados asociados.

  Si a[i] es distinto de un operador(+,-,*,/) o a un número entonces devuelve -1, porque sino no cumple con la premisa de ser una notación prefija
  Si a[i] es igual a un número, devuelve su indice.

  PASO 2. Describe el o los casos recursivos, y justifica
          los resultados asociados. 
  Si a[i] es igual a un operador llama recursivamente a i+1 y a i+2, para encontrar los dos números que tiene emparejados.


*/
int exp_prefija(char a[], int n, int i) {
	/* A IMPLEMENTAR */
	int j = 0;
	if (i == n) j =  n ;
	else if (a[i] == '+' || a[i] == '-' || a[i] == '/' || a[i] == '*') {
		 j = exp_prefija(a, n, i + 1);
		 if (j == n) j = -1;
		 else if (j != -1) j = exp_prefija(a, n, j);
	}
	else if (a[i] >= '0' && a[i] <= '9') {
		 j =  i + 1 ;
	}
	else j = -1;


	return j;
}

bool ejecuta_caso() {
	int n;
	cin >> n;
	if (n == 0) { 
		return false;
    }		
	else {
     	char a[MAX_LON];
   	    for (int i=0; i < n; i++) {
		   cin >> a[i];
	    }
		cout << exp_prefija(a,n,0) << endl;
		return true;
	}	
}	

int main() {
	while (ejecuta_caso());

}