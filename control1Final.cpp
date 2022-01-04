#include <iostream>

/*

Nº GRUPO:2

NOMBRE Y APELLIDOS DE LOS MIEMBROS: José Fabrizio ALcaraz Escobar & David del Cerro Domínguez


OBSERVACIONES:
  

*/



using namespace std;

const int TMAX = 1000;  // No habrá vectores de más de 1000 elementos




/*

PRECONDICION DE LA FUNCION: 
  ---Escribe aquí la precondición de la función.
  P ≡ { 0 <= n <= TMAX}

*/
int pares_menos_impares(const int a[], int n); 

/*
POSTCONDICION DE LA FUNCION: 
  ---Escribe aquí la poscondición de la función. Para referirte 
  ---al valor devuelto por la función, utiliza la pseudo-variable
  ---'resul'
  
   Q ≡ {resul = pares_menos_impares (a , n) }
		pares_menos_impares(a,n) ≡ sumaPares (a, n) - sumaImpares (a, n)
			sumaPares (a , n) ≡ SUMA i: (0 <= i < n) AND (esPar(a[i]): a[i]
			sumaImpares (a, n) ≡ SUMA i: (0 <= i < n) AND (¬esPar(a[i]): a[i]
				esPar (a)≡ a % 2 = 0
 */

 /* DISEÑO DEL ALGORITMO:
 --- Detalla aquí el proceso seguido para diseñar el algoritmo
 
 PASO 1: Variables

 Utilizará una variable de control i, y otros dos 
  para contener resultados de expresiones : sumaPares
  y sumaImpares.
 
 PASO 2: Invariante
 
 Invariante ≡  resul = sumaPares - sumaImpares



 PASO 3: Inicio

  i = 0
 
 PASO 4: Continuación y finalización

 Se sale del bucle cuando i >= n, continua en el caso contrario.


 
 PASO 5: Bloque del bucle
 
 En cada ciclo se compara a[i], y se modifica el valor de resul 
 Para avanzar se suma i++.

 
 PASO 6: Terminación.
	COTA ≡ n - i >= 0
	return resul
	 
 */
 
bool esPar(int num) {
	return (num % 2 == 0);
}
 
 int pares_menos_impares(const int a[], int n) {
    /* IMPLEMENTACION: COMPLETA EL CUERPO DE LA FUNCION
       CON EL CODIGO QUE IMPLEMENTA EL ALGORITMO */
	 int sumaPares = 0;
	 int sumaImpares = 0;
	 int resul = 0;
	 for (int i = 0; i < n; i++) {
		 if (esPar(a[i])) { resul += a[i]; }
		 else resul -= a[i];

		 resul = sumaPares - sumaImpares;
	 }

	 return resul;
 } 
 
 /*
COMPLEJIDAD: Determina razonadamente la
complejidad del algoritmo

	Complejidad del algoritmo es lineal (k +jn), debido a un
	unico recorrido del bucle desde 0 a TMAX
 
 */
 

/* CODIGO PARA LEER Y EJECUTAR LOS CASOS DE PRUEBA */

void lee_vector(int a[], int & n) {
   cin >> n; 
   for (int i=0; i < n; i++) {
	   cin >> a[i]; 
   }   
}

bool ejecuta_caso() {
   int a[TMAX];
   int n;
   lee_vector(a,n);
   if (n >= 0) {
	   cout << pares_menos_impares(a, n) << endl;
	   return true;
   }
   else {
	   return false;
   }
}

int main() {
   int n;
   while (ejecuta_caso());
}