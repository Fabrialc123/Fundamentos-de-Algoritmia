/*
No Grupo:02
Nombre y Apellidos de los miembros:David del Cerro y Fabrizio Alcaraz Escobar

*/


// Si se comenta esta definición, el programa
// autocomprobará su funcionamiento comparando
// la implementación realizada con una 
// implementación 'naif' del algoritmo
#include <iostream>

#define DOM_JUDGE

#ifndef DOM_JUDGE
#include <ctime>
#include <stdlib.h>
#endif 

using namespace std;

typedef unsigned long long t_num;

/*
(1) En caso de utilizar una generalizacion,
determinación de los parámetros de la generalización.
Determina los parámetros de la generalización. Para cada parámetro
indica: (i) su tipo; (ii) su nombre; (iii) si es un parámetro
de entrada, de salida, o de entrada / salida; (iv) su propósito,
descrito de manera clara y concisa.
	- t_num n, parametro de entrada: El numero para el que hay
	que calcular todos los naturales menores que el, que sean
	singulares, es decir que ninguna cifra se repita con la primera

  - num_menos_num_digs, parametro de salida: Cantidad de
	naturales postivos singulares(es decir que ninguna cifra
	se repita con la primera) , y que tienen
	menos digitos que 'n'
  - num_mismo_num_digs, parametro de salida: Cantidad de
	naturales positivos menores que 'n', y que son singulares,
	y con exactamente el mismo numero de d�gitos que 'n'
  - t_num c = 9*9*9*9 ...
  - primerdig, parametro de entrada y salida que almacena el primer
	digito de n para despues usarlo calculando algunos numeros.
  - bool noContar  parametro de entrada y salida que dice si el numero n dado
	no es singular y por tanto no hace falta calcular su cardinal en algun punto

(2) Análisis de casos:

(2.1) Casos base
	Si tiene un solo digito, es decir n < 10,
	entonces:
		num_mismo_digs = n;
		num_menos_digs = 0;
		primerdig = n;
		c = 1;

(2.2) Casos recursivos
	n tiene mas de un digito entonces:
		resolvemos el problema para un digito menos n/10
			num_singurales(t_num n, t_num num_mismo_digs, t_num num_menos_digs, int primerdig);

		Para resolver el programa para n:
		Se valora si el numero n ya no es singular con el parametro noContar, si este es false entonces
		se calcula el cardinal del numero tal que los numeros sean singulares
		Despues se actualiza el valor de num_mismo_digs = num_mismo_digs * 9 + suma; siendo suma
		el valor calculado anteriormente.
		Se calcula el valor de num_menos_digs siendo este num_menos_digs = c * 9 + num_menos_digs;
		Se actualiza el valor de c multiplicandolo por 9


(3) En caso de utilizar una generalizacion, definición por inmersión
del algoritmo. Describe de manera clara y concisa cómo se lleva a
cabo el algoritmo, en qué punto o puntos se invoca a la generalización,
con qué parámetros reales, y cómo se genera el resultado
a partir de los devueltos por la generalización.

 Si n = 0 entonces este caso se trata devolviendo directamente el resultado,
 el resultado seria 0

 El resto de casos se resuelven invocando a la generalizacion como:
	num_singurales(n,num_mismo_digs,num_menos_digs,primerdig,noContar,c);

	devolviendo como resultado num_mismo_digs + num_menos_digs + 1;

*/
void num_singurales(t_num n, t_num& num_mismo_digs, t_num& num_menos_digs, int& primerdig, bool& noContar, t_num& c);

t_num num_singulares_menoresque(t_num n) {
	// Punto de entrada al algoritmo.
	// A implementar
	t_num num_mismo_digs = 0;
	t_num num_menos_digs = 0;
	int primerdig = 0;
	bool noContar = false;
	t_num c = 0;
	if (n == 0) {
		return 0;
	}
	else {
		num_singurales(n, num_mismo_digs, num_menos_digs, primerdig, noContar, c);
		return num_mismo_digs + num_menos_digs + 1;
	}

}
void num_singurales(t_num n, t_num& num_mismo_digs, t_num& num_menos_digs, int& primerdig, bool& noContar, t_num& c) {
	int suma = 0;
	int dig;
	if (n < 10) {
		num_mismo_digs = n - 1;
		num_menos_digs = 0;
		primerdig = n;
		c = 1;

	}
	else {
		num_singurales(n / 10, num_mismo_digs, num_menos_digs, primerdig, noContar, c);
		dig = n % 10;
		if (!noContar) {
			if (dig == primerdig) {
				noContar = true;
			}
			for (int i = 0; i < dig; i++) {
				if (i != primerdig) {
					suma++;
				}
			}
		}

		num_mismo_digs = num_mismo_digs * 9 + suma;
		num_menos_digs = c * 9 + num_menos_digs;
		c = 9 * c;



	}
}
/*
Determina justificadamente la complejidad del algoritmo

(1) Determinación de las ecuaciones de recurrencia para la generalización
  t(1) = co
  t(n) = c1 + t(n/10)
(2) Resolución utilizando los patrones vistos en clase
	Es una recurrencia por divisi�n, donde:
	- a=1
	- k = 0
	- b = 10
  Por tanto, b^k = 1. Es decir, estamos en el caso
   a = b^k. Por tanto t(n) sera O(n^k log n). Es decir,
   O(n^0 log n). Es decir O(log n)
(3) Determinación justificada de la complejidad del algoritmo final.
	La complejidad es O(log n), ya que el caso inmerso no esta acotado superiormente.

*/

#ifndef DOM_JUDGE
unsigned short digito_mas_significativo(t_num n) {
	while (n > 9) {
		n = n / 10;
	}
	return (unsigned short)n;
}
bool es_singular(t_num n) {
	unsigned short msd = digito_mas_significativo(n);
	bool loes = true;
	while (n > 9 && loes) {
		loes = (n % 10 != msd);
		n = n / 10;
	}
	return loes;
}

t_num num_singulares_menoresque_naif(t_num n) {
	t_num num = 0;
	for (t_num i = 0; i < n; i++) {
		if (es_singular(i)) {
			num++;
		}
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
		cout << num_singulares_menoresque(n) << endl;
		return true;
	}
}
#endif

int main() {

#ifndef DOM_JUDGE
	srand(time(NULL));
	for (int i = 1; i < 1000; i++) {
		t_num  n = (t_num)rand();
		if (num_singulares_menoresque_naif(n) != num_singulares_menoresque(n)) {
			cout << "NO FUNCIONA" << endl;
			cout << n << ":" << num_singulares_menoresque_naif(n) << "..." << num_singulares_menoresque(n) << endl;
			break;
		}
	}
	cout << "OK" << endl;
	system("pause");
#endif

#ifdef DOM_JUDGE
	while (ejecuta_caso());
#endif
}
