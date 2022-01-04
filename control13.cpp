/*

NUMERO DE GRUPO:02

NOMBRRE Y APELLIDOS DE LOS AUTORES:	Fabrizio Alcaraz Escobar & David Del Cerro Dom�nguez


*/

#include <iostream>
using namespace std;

typedef unsigned long long t_num;

/*

PRECONDICION DE LA FUNCION:
---Escribe aqu� la precondici�n de la funci�n.

	P = { alpha > 0 && d < 10 }

*/
bool es_limpio(unsigned short d, unsigned short alpha, t_num n);


/*
POSTCONDICION DE LA FUNCION:
---Escribe aqu� la poscondici�n de la funci�n. Para refirte
---al valor devuelto por la funci�n, utiliza la pseudo-variable
---'resul'

(1) Definiciones auxiliares (si procede):
	es_limpio(d, alpha, n) = (MAX i,j: (0 <= i <= j < longitud(n)) &&  tramo_constante(i, j , d): (i - j) + 1) < alpha
	tramo_constante(i, j , d) = PARATODO v: i <= v <= j: n[v] = d

(2) Postcondici�n
	
	Q = { resul = es_limpio(d, alpha, n) }

*/

/* DISE�O DEL ALGORITMO:
--- Detalla aqu� el proceso seguido para dise�ar el algoritmo

PASO 1: Variables

	d, alpha, n, i, limpio

PASO 2: Invariante

	limpio = es_limpio_hasta(d, alpha, n, i) = (MAX u,w: (0 <= u <= w < i <= longitud(n)) && tramo_constante(u, w , d): (u - w) + 1) < alpha

PASO 3: Inicio
	i = 0
	limpio = es_limpio_hasta(d, alpha, n, i) = es_limpio_hasta(d, alpha, n, 0) =  
		   = (MAX u,w: (0 <= u <= w < 0 <= longitud(n)) &&  tramo_constante(u, w , d): (u - w) + 1) < alpha =
		   = (MAX u,w: false: (u - w) + 1) < alpha = 
		   = true

PASO 4: Continuaci�n y finalizaci�n
	
	i != longitud(n)

	Si i = longitud(n), entonces, el invariante asegura que limpio = es_limpio_hasta(d, alpha, n, i), pero como i = longitud(n), entonces
	limpio = es_limpio_hasta(d, alpha, n, longitud(n))


PASO 5: Bloque del bucle

	Como 0 <= i < n (por la condici�n del bucle), ya podemos ir buscando el tramo constante m�s largo que se encuentre hasta la posici�n i,
	por lo que en cada iteracci�n se comprobar� si se ha encontrado uno m�s largo y posteriormente se aumentar� i.
	Si se ha encontrado un tramo constante m�s grande o igual que alpha, por el invariante podemos asegurar que
		limpio = es_limpio_hasta(d, alpha, n, i)  = (MAX u,w: (0 <= u <= w < i <= longitud(n)) && tramo_constante(u, w , d): (u - w) + 1) < alpha 
			   = !((MAX u,w: (0 <= u <= w < i <= longitud(n)) && tramo_constante(u, w , d): (u - w) + 1) < alpha) = false
		En caso contrario seguiria siendo true.


PASO 6: Terminaci�n.
	
	longitud(n) - i es una expresi�n de cota, ya que en cada iteracci�n del bucle se aumenta i hasta alcanzar longitud(n), por lo que es 
	seguro que en todo momento longitud(n) - i >= 0.
		

*/

bool es_limpio(unsigned short d, unsigned short alpha, t_num n) {
	// IMPLEMENTACION DEL ALGORITMO
	t_num n_restante;
	unsigned short digito_actual;

	unsigned int ocurrencias_consecutivas = 0;
	bool limpio = true;

	n_restante = n / 10;
	digito_actual = n % 10;

	if (n == 0 && d == 0 && alpha == 1) limpio = false;

	while (!(n_restante == 0 && digito_actual == 0) && (limpio)) {
	
		if (digito_actual == d) {
			ocurrencias_consecutivas++;
			if (ocurrencias_consecutivas >= alpha) limpio = false;
		}
		else {
			ocurrencias_consecutivas = 0;
		}

		digito_actual = n_restante % 10;
		n_restante = n_restante / 10;

	}
	
	return limpio;
}

/*
COMPLEJIDAD: Determina razonadamente la
complejidad del algoritmo

	Como en cada iteracci�n del bucle se est� dividiendo n entre 10, acabando este cuando n sea 0, la complejidad final del algoritmo resulta ser de log(n).

*/



bool procesa_caso() {
	int d;
	unsigned short alpha;
	t_num n;
	cin >> d;
	if (d != -1) {
	  cin >> alpha >> n;
	  if (es_limpio((unsigned short)d,alpha,n)) {
		  cout << "SI" << endl;
	  }
	  else {
		  cout << "NO" << endl;
	  }
	  return true;
	}
	else {
		return false;
	}
}	

int main() {
	while (procesa_caso());
}