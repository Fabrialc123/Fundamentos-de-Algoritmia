/*

NUMERO DE GRUPO:02

NOMBRRE Y APELLIDOS DE LOS AUTORES:
	David del Cerro Dominguez Y Fabrizio Alcaraz Escobar


*/

#include <iostream>
using namespace std;


typedef unsigned long long t_num;


/*
(1) En caso de utilizar una generalizacion, 
determinación de los parámetros de la generalización.
Determina los parámetros de la generalización. Para cada parámetro
indica: (i) su tipo; (ii) su nombre; (iii) si es un parámetro
de entrada, de salida, o de entrada / salida; (iv) su propósito,
descrito de manera clara y concisa.
	i. Parametro de entrada K el numero con el que estamos tratando y el cual buscamos los alternados menores que K
	ii.Parametro de entrada/salida booleano cuenta, sirve para saber si al saber quie el numero con el que estamos tratando no es alternado no seguir conttando mas numeros en siguientes
		iteraciones.
	iii. Parametro de salida d, guarda el digito anterior para asi calcular el cardinal.
	iv. Parametro de salida num_alt_men_digs, aqui está el resultado de los numeros con menos digitos que son altgernados de K
	v.	Parametro de salida num_alt_mis_digs, aquí está el resultado de los numeros con mismo digitos que K cuales son alternados.
	vi. Parametro de salida mult guarda el numero para obtener la cuenta de los alternados de menos digitos que K.
(2) Análisis de casos:

(2.1) Casos base
	Caso base n < 10 entonces:
		mult = 0;
		num_alt_mis_digs = n-1;
		num_alt_menos_digs = 0;
	Caso base n < 100 entonces:
		mult = 9;
		num_alt_menos_digs = 9;

(2.2) Casos recursivos
	Si n > 100 entonces 
		Se llama a la funcion para k/10
		num_alt_menos_digs = mult * 5 + num_alt_menos_digs;
		num_alt_mis_digs = num_alt_mis_digs * 5 + cardinal;
		cardinal se calcula sabiendo si el digito es alternado con cuenta y con el digito anterior 
 
(3) En caso de utilizar una generalizacion, definición por inmersión 
del algoritmo. Describe de manera clara y concisa cómo se lleva a 
cabo el algoritmo, en qué punto o puntos se invoca a la generalización,
con qué parámetros reales, y cómo se genera el resultado
a partir de los devueltos por la generalización.

	Todos los casos se tratan invocando a la generalización como calc_num_alternados(n, cuenta, d, men_digs, mis_digs, mult);
	devolviendo el resultado como men_digs + mis_digs + 1;

*/

void calc_num_alternados(t_num k, bool& cuenta, t_num& d, t_num& num_alt_men_digs,t_num& num_alt_mis_digs, t_num& mult) {
	t_num cardinal = 0;
	if (k < 10) {
		d = k;
		num_alt_men_digs = 0;
		num_alt_mis_digs = k - 1;
		mult = 0;
	}
	else {
		calc_num_alternados(k / 10, cuenta, d, num_alt_men_digs, num_alt_mis_digs, mult);
		if (k < 100) {
			mult = 9;
			num_alt_men_digs = 9;
		}
		else {
			num_alt_men_digs = mult * 5 + num_alt_men_digs;
			mult = mult * 5;
		}
		if (cuenta) {
			if (((k % 10) % 2) == (d % 2)) {
				cuenta = false;
				if (d % 2 == 1) {
					cardinal = (((k % 10) + 1) / 2);
				}
				else {
					cardinal = ((k % 10) / 2);
				}
			}
			else {
				cardinal = ((k % 10) / 2);
			}
			
		}
		d = k % 10;
		num_alt_mis_digs = num_alt_mis_digs * 5 + cardinal;
	}
}

t_num num_alternados(t_num n) {
	// PUNTO ENTRADA AL ALGORITMO
	t_num resul;
	t_num d = 0;
	t_num mult = 0;
	bool cuenta = true;
	t_num mis_digs = 0;
	t_num men_digs = 0;
	calc_num_alternados(n, cuenta, d, men_digs, mis_digs, mult);
	resul = mis_digs + men_digs + 1;

	return  resul;
}

/*
Determina justificadamente la complejidad del algoritmo

(1) Determinación de las ecuaciones de recurrencia para la generalización
	t(1) = co
	t(n) = c1 + t(n/10)
(2) Resolución utilizando los patrones vistos en clase
	  Es una recurrencia por division, donde:
    - a=1
	- k = 0
	- b = 10
  Por tanto, b^k = 1. Es decir, estamos en el caso
   a = b^k. Por tanto t(n) sera O(n^k log n). Es decir,
   O(n^0 log n). Es decir O(log n)   
(3) Determinación justificada de la complejidad del algoritmo final.
	Al el problema no estar acotado superiormente podemos decir que la complejidad final del algoritmo
	es 0(log n).

*/


bool procesa_caso() {
	long long n;
	cin >> n;
	if (n == -1) {
		return false;
	}
	else {
		cout << num_alternados((t_num)n) << endl;
		return true;
	}

}

int main() {
    while (procesa_caso());

}