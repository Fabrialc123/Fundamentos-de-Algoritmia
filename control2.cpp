#include <iostream>

using namespace std;

const int TMAX = 1000;  // No habrá vectores de más de 1000 elementos

// Nombres = José Fabrizio Alcaraz Escobar && David del Cerro Domínguez


/*

PRECONDICION DE LA FUNCION: 
  ---Escribe aquí la precondición de la función.
  
  P ≡ {0 < n <= TMAX}

*/
bool es_gaspariforme(const int a[], int n); 

/*
POSTCONDICION DE LA FUNCION: 
  ---Escribe aquí la poscondición de la función. Para refirte 
  ---al valor devuelto por la función, utiliza la pseudo-variable
  ---'resul'
  
  (1) Definiciones auxiliares (si procede):
  

  
  (2) Postcondición
    Q ≡ {resul = es_gaspariforme(a,n)}
		es_gaspariforme(a,n)= PARA_TODO i: 0 <= i < n - 1 :sumaParcial(a,i) > 0  AND sumaParcial(a,n) = 0
			sumaParcial(a,i) = SUMA j: 0 <= j < i : a[j]
			
  
 */

 /* DISEÑO DEL ALGORITMO:
 --- Detalla aquí el proceso seguido para diseñar el
 --- algoritmo
 
 PASO 1. Variables
	Variable de control i.
	Variable para el resultado de la sumaParcial.
	Variable booleana b; 
	

 PASO 2. Invariante
 
	INV = j < n-1? (SUMA i : 0 <= i < j : a[i]) > 0 : (SUMA i : 0 <= i < j : a[i]) = 0 ; 
 
 PASO 3. Inicialización:
	i = 0;
	sumaParcial = 0;
	b = true;

 PASO 4: Continuación y finalización

	b = sumaParcial(a,i) > 0 se continua el bucle y i < n, 
	en caso contrario sumaParcial(a,i) <= 0 o i = n se finaliza el bucle 
	y b=false.
	
 
 PASO 5: Cuerpo del bucle. 
 
	Actualizamos el valor de sumaParcial(a,i) con el anterior resultado + a[i];
	Comprobamos si es menor que 0 ;
	Aumentamos el valor de i;

PASO 6: Terminación		  

	Si i = n - 1 y b = true comprobamos si sumaParcial(a,i) = 0, en caso afirmativo el vector es gaspariforme
	en caso contrario no lo es.

 
*/
 
 
 
 bool es_gaspariforme(const int a[], int n) {
    /* IMPLEMENTACION: COMPLETA EL CUERPO DE LA FUNCION
       CON EL CODIGO QUE IMPLEMENTA EL ALGORITMO */
	 int sumaParcial = 0;
	 int i = 0;
	 bool b = true;

	 while (b && i < n - 1) {
		 sumaParcial = sumaParcial + a[i];
		 if (sumaParcial <= 0) {
			 b = false;
		 }
		 i++;
	 }
	 if(b){
		 sumaParcial = sumaParcial + a[i];
			 if (sumaParcial != 0) b = false;
		}

	 return b;

}	

/*
Complejidad: Determina justificadamente el orden de complejidad
de este algoritmo
	K0 = Coste de la inicialización y finalización del código
	K1 = Coste de cada iteración del código
	Y como tiene como mucho n iteracciones (tamaño del array), la complejidad es lineal (K0 + nK1)
	
*/ 
	 

/* CODIGO PARA LEER Y EJECUTAR LOS CASOS DE PRUEBA */

void lee_vector(int a[], int & n) {
	cin >> n; 
   for (int i=0; i < n; i++) {
	   cin >> a[i]; 
   }   
}

int main() {
   int a[TMAX];
   int n;
   do {
	   lee_vector(a,n); 
	   if (n>0) {
		 if (es_gaspariforme(a,n)) 
           cout << "SI" << endl;
         else  
           cout << "NO" << endl;			 
	   }
   }
   while (n != 0);	
}