/*

NUMERO DE GRUPO:02

NOMBRRE Y APELLIDOS DE LOS AUTORES: Fabrizio Alcaraz Escobar & David Del Cerro Dominguez


*/

#include <iostream>
using namespace std;

// Representación de un tema
typedef struct {
  float tiempo_req;  // tiempo requerido para estudiar
  float nota_prim;   // Nota que supone en la primera parte
  float nota_sec;    // Nota que supone en la segunda parte
} tInfoTema;



/*

(1) En caso de utilizar una generalización, indicar su parámetros, y explicar para que
sirven cada uno de ellos

	Parámetro 4: i, sirve para recorrer el array.
	Parámetro 5: nota1, sirve para acumular la posible nota de la primera parte del examen.
	Parámetro 6: nota2, sirve para acumular la posible nota de la segunda parte del examen.
	Parámetro 7: maximanota, sirve para guardar la máxima puntuación válida encontrada.

(2) ¿Cómo son las soluciones parciales de este problema?

	Las soluciones parciales de este problema son las acumulaciones de nota1, nota2 y el tiempo restante disponible.

(3) ¿Cuándo una solución parcial es viable?

	Una solución parcial es viable siempre que el tiempo restante sea mayor o igual que 0.

(4) ¿Cuándo una solución parcial es una solución final al problema?

	Una solución parcial es una solución final al problema cuando nota1 y nota2 sean mayor o igual que 5 y no haya tiempo restante.

(5) Dada una solución parcial, ¿cómo se generan las siguientes soluciones
parciales viables?

	Las siguientes soluciones parciales viables se generan accediendo al siguiente elemento del array. En caso de aún haber tiempo restante, se acumula su nota1 y nota2.
	Se termina de generar las siguientes soluciones cuando se pase del array.

(6) Análisis de casos

(6.1) Caso(s) base
	Si el tiempo restante es menor que 0, se verifica si la nota1 y nota2 acumulado de las anteriores posiciones del array superan o igualan el 5, en caso afirmativo se calcula la media y se compara con la máxima nota encontrada anteriormente.
			Si la nueva nota es mayor, la máxima nota se sustituye por esta.
	Si el vector actual del array es el último y aún queda tiempo restante, se acumula su nota1 y nota2 ,y se hace lo mismo que en el anterior caso base (ignorando si el tiempo restante es menor que 0).

(6.2) Caso(s) recursivos
	Si el tiempo restante es mayor que 0, se recorre la siguiente posicione del array buscando la posible combinacion en la que se agote el tiempo restante y se apruebe el examen. En caso contrario se vuelve atrás 
	y se prueba con el siguiente a este.

(7) En caso de utilizar una generalización, explicar cómo se define el algoritmo final
a partir de la misma, por inmersión.

	Dado un vector inicial, se buscan todas las posibles combinaciones en las que se agote el tiempo restante y se apruebe el examen.

*/

void calculanota(const tInfoTema info_temas[], unsigned int num_temas, float tiempo_disponible, int i, float nota1, float nota2, float & maximanota) {

	float tiempo_restante = tiempo_disponible - info_temas[i].tiempo_req;
	if (tiempo_restante < 0) {
		if ((nota1 >= 5) && (nota2 >= 5)) {
			float aux = (nota1 + nota2) / 2;
			if (aux > maximanota) maximanota = aux;
		}
	}
	else {
		nota1 += info_temas[i].nota_prim;
		nota2 += info_temas[i].nota_sec;
		if (i + 1 == num_temas) {
			if ((nota1 >= 5) && (nota2 >= 5)) {
				float aux = (nota1 + nota2) / 2;
				if (aux > maximanota) maximanota = aux;
			}
		}
		for (int j = i + 1; j < num_temas ; j++) {
			calculanota(info_temas, num_temas, tiempo_restante, j, nota1 , nota2 , maximanota);
		}
	}

}

float mejor_puntuacion(const tInfoTema info_temas[], unsigned int num_temas, float tiempo_disponible) {
	// Punto de entrada al algoritmo: a implementar
	float maximanota = -1;
	float nota1 = 0;
	float nota2 = 0;

	for (int i = 0; i < num_temas; i++) {
		calculanota(info_temas, num_temas, tiempo_disponible, i, nota1, nota2, maximanota);
	}


	return maximanota;

}





const unsigned int MAX_TEMAS = 20;


bool procesa_caso() {
	int num_temas;
	tInfoTema info_temas[MAX_TEMAS];
	cin >> num_temas;
	if (num_temas != -1) {
		float tiempo_disponible;
		cin >> tiempo_disponible;
		for (int i = 0; i < num_temas; i++) {
			cin >> info_temas[i].tiempo_req;
			cin >> info_temas[i].nota_prim;
			cin >> info_temas[i].nota_sec;
		}
		cout << mejor_puntuacion(info_temas, num_temas, tiempo_disponible) << endl;
		return true;
	}
	else {
		return false;
	}
}

int main() {
	while (procesa_caso());
}