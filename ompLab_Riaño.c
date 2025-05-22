/**************************************************************
*	Pontificia Universidad Javeriana
*	Autor: Gabriel Riaño
*	Materia: Sistemas Operativos
*	Fecha: 22/5/2025
*	Topico: Uso de OpenMP
*	Descripción: 
*	Este programa demuestra el uso básico de OpenMP para paralelizar
*	un bucle `for` y un bloque de impresión usando múltiples hilos.
*	Se establece un número de hilos según el argumento del usuario.
**************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>


int main(int argc, char *argv[]) {
	if(argc < 2){
		printf("Uso: %s$./ejecutable <num_hilos>\n", argv[0]);
		return 1;
	}

	int hilos = (int) atoi(argv[1]);
	int i;
	int a = 50;
	int b = 0;
	const int N = 1000;
	int maxhilos = omp_get_max_threads();  // Obtiene el número máximo de hilos disponibles
	omp_set_num_threads(hilos);           // Establece el número de hilos a usar

	// Bloque paralelo simple. Todos los hilos imprimirán el mensaje.
#pragma omp parallel
	printf("El número máximo de hilos es: %d, equipo de hilos impuesto: %d\n", maxhilos, omp_get_num_threads());

	// Bucle paralelo. Cada iteración se ejecuta en paralelo.
	// La variable 'a' y 'i' son privadas para evitar condiciones de carrera.
#pragma omp parallel for private(a,i)
	for (i = 0; i < N; i++) {
		b = a + i;
	}

	printf("El valor de a: %d, el valor de b: %d (se espera que a=50 y b=1049)\n", a, b);
	
	return 0;
}

/**************************************************************
*	Conclusiones:
*	OpenMP permite paralelizar código de manera eficiente y sencilla.
*	Es importante manejar adecuadamente las variables privadas y compartidas.
*	La impresión desde múltiples hilos puede generar salidas desordenadas.
*	El valor de la variable `b` al final puede no reflejar el resultado esperado.
*	Esto se debe a que varias iteraciones pueden sobrescribir el valor de `b`.
*	Comprender el manejo de memoria compartida es crucial para evitar errores.
**************************************************************/
