/*
No Grupo:D02
Nombre y Apellidos de los miembros:
	David del Cerro Dominguez y Fabrizio Alcaraz Escobar	
*/


// Si se comenta esta definición, el programa
// autocomprobará su funcionamiento comparando
// la implementación realizada con una 
// implementación 'naif' del algoritmo
//#define DOM_JUDGE

#include <iostream>

#ifndef DOM_JUDGE 
#include <ctime>
#include <stdlib.h>
#include <climits>
#endif


using namespace std;

typedef unsigned long long t_num;
typedef bool dig[10];
typedef t_num sumaC[10];

/*
(1) Determinación de los parámetros de la generalización.
Determina los parámetros de la generalización. Para cada parámetro
indica: (i) su tipo; (ii) su nombre; (iii) si es un parámetro 
de entrada, de salida, o de entrada / salida; (iv) su propósito,
descrito de manera clara y concisa. 

  - t_num n, parámetro de entrada: El número para el cuál hay
    que calcular todos los naturales menores que él, que no 
	tengan dígitos repetidos.
  - num_menos_num_digs, parámetro de salida: Cantidad de 
    naturales postivos sin dígitos repetidos, y que tienen
	menos dígitos que 'n'
  - num_mismo_num_digs, parámetro de salida: Cantidad de
    naturales positivos menores que 'n', sin dígitos repetidos,
	y con exactamente el mismo número de dígitos que 'n'
  - num_dig, parametro de salida: Cantidad de digitos del numero n que le 
	pasas a la funcion.Uno para la ultima llamada y sumando uno cada llamada.
  - digs, parametro de entrada y salida. Contiene los digitos de n anteriores
	a la posicion que se esta tratando, es decir, contiene siendo n el numero su n'.
  - bool cardinal, parametro de entrada y salida,este bool indica si en n' hay dos digitos iguales, 
	si es asi el cardinal de n' sera 0, en otro caso se calculara el cardinal y se verá si ese digito
	ya está en digs para actualizar cardinal.
  - sumaC - parametro de salida que contiene los C Calculados
	
	
	
	
	.... *** añade y explica el resto de parámetros que
	.... *** consideres oportuno


(2) Análisis de casos para la generalización:

(2.1) Casos base
	Si n = 0 entonces la salida es 0 ya que hay 0 numeros naturales menores que 0,
	si n > 10000000000 entonces la salida es 8877691 que es la maxima cantidad de numeros sin digitos repetidos.

(2.2) Casos recursivos
	Si n > 0 y n < 10000000000 entonces por un lado 


(3) Definición por inmersión del algoritmo. Describe
de manera clara y concisa cómo se lleva a cabo el algoritmo,
en qué punto o puntos se invoca a la generalización, 
con qué parámetros reales, y cómo se genera el resultado
a partir de los devueltos por la generalización. 



*/

void cuenta_sinrepetidos_menoresque(t_num n,
 	                                t_num& num_menos_num_digs,
	                                t_num& num_mismo_num_digs,
									t_num& num_dig,
									dig& digs,
									bool& cardinal,
									sumaC sumaC
	                                           // Añade los parámetros adicionales que consideres oportuno
	                                ) {
	// A implementar
	t_num cardinalidad = 0;
	t_num dig;
	t_num suma = 0;
	if (n <= 9) {
		sumaC[0] = 0;
		num_menos_num_digs = 0;
		num_mismo_num_digs = n - 1;
		num_dig = 1;
		digs[n] = true;
	}
	else {
		cuenta_sinrepetidos_menoresque(n/10, num_menos_num_digs, num_mismo_num_digs, num_dig,digs, cardinal,sumaC);
		num_dig++;
		dig = n % 10;
		if (digs[dig] == true) {
			if (!cardinal) {
				digs[dig] = true;
				while (dig != -1) {
					if (digs[dig] == false) { cardinalidad++; }
					dig--;
				}
				cardinal = true;
			}

		}
		else digs[dig] = true;
		if (!cardinal) {
			while (dig != -1) {
				if (digs[dig] == false) { cardinalidad++; }
				dig--;
			}
		}
		num_mismo_num_digs = num_mismo_num_digs*(10 - (num_dig - 1)) + cardinalidad;
		if (n > 9 && n <= 99) {
			sumaC[1] = 9;
			num_menos_num_digs = sumaC[1];

		}
		else {

			
			for (int i = 0; i <= num_dig - 2; i++) {
				suma = suma + sumaC[i];
			}
			sumaC[num_dig - 1] = sumaC[num_dig - 2] * (10 - (num_dig - 2));
			num_menos_num_digs = sumaC[num_dig - 2] * (10 - (num_dig - 2)) + suma;
		}
	}

}

t_num num_sinrepetidos_menoresque(t_num n) {
	 // A implementar, como una inmersión de
	  // 'cuenta_sin_repetidos_menoresque 
	t_num resul, num_menos_num_digs, num_mismos_num_digs;
	t_num num_dig = 0;
	bool cardinal = false;
	num_mismos_num_digs = 0;
	num_menos_num_digs = 0;
	dig digs;
	sumaC sumaC;
	for (int i = 0; i < 10; i++) {
		digs[i] = false;
	}
	if (n == 0) {
		resul = 0;
	}
	else if (n >= 1000000000) {
		resul = 8877691;
	}
	else {
		cuenta_sinrepetidos_menoresque(n, num_menos_num_digs, num_mismos_num_digs, num_dig,digs,cardinal,sumaC);
		resul = num_menos_num_digs + num_mismos_num_digs + 1;
	}
	
	return resul;

}

/*
Determina justificadamente la complejidad del algoritmo

(1) Determinación de las ecuaciones de recurrencia para la generalización

(2) Resolución utilizando los patrones vistos en clase

(3) Determinación justificada de la complejidad del algoritmo final.


*/



// No modificar el código que sigue

#ifndef DOM_JUDGE

bool digs_reps(t_num n) {
	bool digs[10];
	for (unsigned short d = 0; d < 10; d++) {
		digs[d] = false;
	}
	while (n > 0 && !digs[n % 10]) {
		digs[n % 10] = true;
		n /= 10;
	}
	return n != 0;
}

t_num num_sinrepetidos_menoresque_naif(t_num n) {
	t_num num = 0;
	for (t_num i = 0; i < n; i++) {
		if (!digs_reps(i)) num++;
	}
	return num;
}
#endif


#ifdef DOM_JUDGE

bool ejecuta_caso() {
	long long n;
	cin >> n;
	if (n == -1) {
		return false;
	}
	else {
		cout << num_sinrepetidos_menoresque(n) << endl;
		return true;
	}
}
#endif


int main() { 
#ifdef DOM_JUDGE
	while (ejecuta_caso());
#endif

#ifndef DOM_JUDGE

	srand(time(NULL));
	for (int i = 1; i < 1000; i++) {
		t_num  n = (t_num)rand();
		if (num_sinrepetidos_menoresque_naif(n) != num_sinrepetidos_menoresque(n)) {
			cout << "NO FUNCIONA" << endl;
			cout << n << ":" << num_sinrepetidos_menoresque_naif(n) << "..." << num_sinrepetidos_menoresque(n) << endl;
			break;
		}
	}
	cout << "OK" << endl;
	system("pause"); 
#endif

}

