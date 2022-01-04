/*
GRUPO:2
COMPONENTES DEL GRUPO:David del Cerro Dominguez y Fabrizio Alcaraz Escobar

*/


#include <iostream>


using namespace std;


/*

PRECONDICION DE LA FUNCION: 
  ---Escribe aquí la precondición de la función.
  P ≡ { n' = n >= 0}

*/
bool es_sobrado(int n); 

/*
POSTCONDICION DE LA FUNCION: 
  ---Escribe aquí la poscondición de la función. Para refirte 
  ---al valor devuelto por la función, utiliza la pseudo-variable
  ---'resul'
  
  (1) Definiciones auxiliares (si procede):
	es_sobrado = PARATODO i; 0 < i < tam(n); n[i - 1] < n[i] 
  
  (2) Postcondición
	Q ≡ { resul = es_sobrado(n, tam(n)) }
		     
 */

 /* DISEÑO DEL ALGORITMO:
 --- Detalla aquí el proceso seguido para diseñar el
 --- algoritmo
 
 PASO 1. Variables
	Utilizaremos un booleano resul, int N, que es el número original, int N' , que es la copia del número original
	y una variable auxiliar digAnterior.
 
 PASO 2. Invariante
	 INV = es_sobrado (n', tam(n'))

 PASO 3. Inicialización:
	N = n;
	resul = true ; ya que en caso de que solo sea un dígito (< 10) es sobrado.
	N' = 0;
	digAnterior = -1;
 PASO 4: Continuación y finalización: 
 	  El bucle sigue mientras que n' != 0 y siga siendo sobrado. Finaliza cuando una de las dos condiciones sea falsa.
 
 PASO 5: Cuerpo del bucle
	
	 Si el digito anterior es mayor o igual que  n' % 10 entonces resultado es falso,
	 en caso contrario digAnterior = n' % 10  y n' = n' / 10;
	 

 PASO 6: Terminación		  
	Tomamos como cota el valor absoluto de N', ya que le vamos a ir quitando digitos y está acotado por 0.
	 
*/
 
 
 bool es_sobrado(int n) {
    /* IMPLEMENTACION: COMPLETA EL CUERPO DE LA FUNCION
       CON EL CODIGO QUE IMPLEMENTA EL ALGORITMO */
	 bool resul = true;
	 int nPrima = n;
	 int digAnterior = -1;
	 while (nPrima != 0 && resul) {
		 if (digAnterior >= nPrima % 10) { resul = false; }
		 else {
			 digAnterior = nPrima % 10;
			 nPrima = nPrima / 10;
		 }
	 }
	 return resul;
}	

/*
Complejidad: Determina justificadamente el orden de complejidad
de este algoritmo
	K0 = coste de inicialización y finalización del código.
	K1 = coste del cuerpo del bucle.
	Como el número de iteracciones depende del número de dígitos de N, el coste total quedaría:
	
	K0 + (log(n) + 1)*K1, en el peor de los casos (hace el recorrido completo)

	o

	K0 + K1 , en el mejor (solo hay 1 digito)

*/ 
	 

/* CODIGO PARA LEER Y EJECUTAR LOS CASOS DE PRUEBA */


int main() {
   int n_casos;
   cin >> n_casos;
   while (n_casos > 0) {
	   int n;
	   cin >> n;
	   if (es_sobrado(n)) {
		  cout << "SI" << endl;  
	   }
	   else {
		  cout << "NO" << endl; 
	   }
	   n_casos--;
   }
   return 0;
}