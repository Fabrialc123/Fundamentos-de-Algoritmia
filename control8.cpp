/*
No Grupo: 2
Nombre y Apellidos de los miembros: Fabrizio Alcaraz & David del Cerro

*/
#define DOM_JUDGE

#include <iostream>
#ifndef DOM_JUDGE
#include <ctime>
#include <stdlib.h>
#endif

using namespace std;




/*
(1) En caso de utilizar una generalizacion,
determinaci�n de los par�metros de la generalizaci�n.
Determina los par�metros de la generalizaci�n. Para cada par�metro
indica: (i) su tipo; (ii) su nombre; (iii) si es un par�metro
de entrada, de salida, o de entrada / salida; (iv) su prop�sito,
descrito de manera clara y concisa.


(2) An�lisis de casos:

(2.1) Casos base


(2.2) Casos recursivos

(3) En caso de utilizar una generalizacion, definici�n por inmersi�n
del algoritmo. Describe de manera clara y concisa c�mo se lleva a
cabo el algoritmo, en qu� punto o puntos se invoca a la generalizaci�n,
con qu� par�metros reales, y c�mo se genera el resultado
a partir de los devueltos por la generalizaci�n.



*/
int min_poder(int enemigos[], int n, int max_duelos) {  // Punto de entrada al algoritmo: a implementar
	int poder = 0;
	if (max_duelos == 1) for (int i = 0; i < n; i++) poder += enemigos[i]; 
	else if (max_duelos >= n) {
		for (int i = 0; i < n; i++) {
			if (enemigos[i] > poder) poder = enemigos[i];
		}
	}
}


#ifdef DOM_JUDGE
const int MAX_ENEMIGOS = 1000;
bool ejecuta_caso() {
	int enemigos[MAX_ENEMIGOS];
	int num_enemigos;
	cin >> num_enemigos;
	if (num_enemigos == -1) {
		return false;
	}
	else {
		int max_torneos;
		cin >> max_torneos;
		for (int i = 0; i < num_enemigos; i++) {
			cin >> enemigos[i];
		}
		cout << min_poder(enemigos, num_enemigos, max_torneos) << endl;
		return true;
	}
}
#endif


#ifndef DOM_JUDGE
int min_poder_naif(int enemigos[], int n, int max_duelos) {
	int poder = 0;
	while (!factible(enemigos, n, poder, max_duelos)) {
		poder++;
	}
	return poder;
}


const int MAX_ENEMIGOS_TEST = 20;
const int MAX_PODER = 20;
bool chequea() {
	int enemigos[MAX_ENEMIGOS_TEST];
	int num_enemigos = (rand() % MAX_ENEMIGOS_TEST) + 1;
	int max_torneos = (rand() % num_enemigos) + 1;
	for (int i = 0; i < num_enemigos; i++) {
		enemigos[i] = (rand()+1)%MAX_PODER;
	}
	int resul1 = min_poder(enemigos, num_enemigos, max_torneos);
	int resul2 = min_poder_naif(enemigos, num_enemigos, max_torneos);
	if (resul1 != resul2) {
		cout << "NO FUNCIONA PARA: NUM_ENEMIGOS:" << num_enemigos << " MAX_TORNEOS:" << max_torneos << endl;
		cout << "PODERES ENEMIGOS:";
		for (int p = 0; p < num_enemigos; p++) {
			cout << enemigos[p] << " ";
		}
		cout << endl;
		cout << "SOLUCION ALGORITMO NAIF:" << resul2 << " SOLUCION ALGORITMO:" << resul1 << endl;
		return false;
	}
	else {
		return true;
	}
}
#endif


int main() {
#ifndef DOM_JUDGE
	srand(time(NULL));
	bool ok = true;
	int i = 0;
    while (ok && i < 1000) {
		ok = chequea();
		i++;
	}
	if (ok) cout << "OK" << endl;
	system("pause");
#endif

#ifdef DOM_JUDGE
	while (ejecuta_caso());
#endif

}
