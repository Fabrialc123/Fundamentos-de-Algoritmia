/*

NUMERO DE GRUPO:D02

NOMBRRE Y APELLIDOS DE LOS AUTORES:
	David del Cerro Dominguez y Fabrizio Alcaraz Escobar

*/

#include <iostream>

using namespace std;




	
/*
(1) En caso de utilizar una generalizacion, 
determinación de los parámetros de la generalización.
Determina los parámetros de la generalización. Para cada parámetro
indica: (i) su tipo; (ii) su nombre; (iii) si es un parámetro
de entrada, de salida, o de entrada / salida; (iv) su propósito,
descrito de manera clara y concisa.


(2) Análisis de casos:

(2.1) Casos base
	Vector de longitud 1, entonces el impar es el primer elemento, tambien en el caso que el primer elemento sea impar.

(2.2) Casos recursivos
	En el resto de casos usaremos una busqueda binaria para buscar el impar, en el caso que el impar no esté en el elemento central, se comprobará que no esté en la mitad - 1(si esta aquí se devolverá como
	resultado, para despúes hacer una comparación entre la longitud del tramo (0 - (mitad - 1)) y asi saber si el impar se encuentra en ese tramo, si es así volveremos a llamar a
	busqueda(a,inicio,mitad - 1), en caso negativo llamaremos a busqueda como busqueda(a,mitad + 1,final).
(3) En caso de utilizar una generalizacion, definición por inmersión 
del algoritmo. Describe de manera clara y concisa cómo se lleva a 
cabo el algoritmo, en qué punto o puntos se invoca a la generalización,
con qué parámetros reales, y cómo se genera el resultado
a partir de los devueltos por la generalización.

	Se invoca a busqueda como una generalización con el vector a[], 0(inicio) y n - 1 (final).

*/
int busqueda(int a[],int inicio, int final) {
	int mitad = (inicio + final) / 2;
	if (a[mitad] % 2 == 1) {
		return mitad;
	}
	else {
		if (a[mitad - 1] % 2 == 0) {
			if (a[mitad - 1] / 2 == (mitad - 1) + a[0]/2) return busqueda(a,mitad + 1, final);
			else return busqueda(a, inicio, mitad - 1);
		}
		else return mitad - 1;
	}
}
	
int posicion_impar(int a[], int n) {
	if (n == 1 ||a[0] % 2 == 1) {
		return 0;
	}
	else
	{
		return busqueda(a, 0, n - 1);
	}
}

/*
Determina justificadamente la complejidad del algoritmo

(1) Determinación de las ecuaciones de recurrencia para la generalización
	t(1) = co
    t(n) = c1 + t(n/2)
(2) Resolución utilizando los patrones vistos en clase
	  Es una recurrencia por division, donde:
    - a=1
	- k = 0
	- b = 10
  Por tanto, b^k = 1. Es decir, estamos en el caso
   a = b^k. Por tanto t(n) ser� O(n^k log n). Es decir,
   O(n^0 log n). Es decir O(log n)   
(3) Determinación justificada de la complejidad del algoritmo final.
	El algoritmo será logaritmico, es decir, 0(log n), debido a que no se encuentra acotado.

*/



const int MAX=10000;

void genera_vector(int prim,int ult, int impar, int a[], int& n) {
   n=0;
   for (int i=prim; i <= ult; i++) {
	 if (i%2 == 0 || i == impar) {
		 a[n++] = i;
	 }   
   }   
}

bool ejecuta_caso() {
	int a[MAX];
	int prim;
	cin >> prim;
	if (prim == -1) {
		return false;
	}
	else {
	  int ult, impar;
      cin >> ult >> impar;
	  int n;
	  genera_vector(prim,ult,impar,a,n);
      cout << posicion_impar(a,n) << endl;	  
	  return true;
	}
}

int main() {
	while(ejecuta_caso());
}